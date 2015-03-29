/*
 * Uuid.cpp
 *
 *  Created on: 29/3/2015
 *      Author: carlos
 */

#include "Uuid.h"
#include <iomanip>

namespace ddd {

using namespace std;

Uuid::Uuid(): most(get_rnd()), least(get_rnd()){}

Uuid::Uuid(int64_t m, int64_t l): most(m), least(l) {}

Uuid::Uuid(const Uuid & id)
{
	*this = id;
}

Uuid & Uuid::operator=(const Uuid & id)
{
	most = id.most;
	least = id.least;
	return *this;
}

bool Uuid::operator==(const Uuid & id){
	return most == id.most && least == id.least;
}

bool Uuid::operator!=(const Uuid & id){
	return !(*this == id);
}

int64_t Uuid::get_rnd()
{
	return DISTRIBUTION(RND_METHOD);
}

const char * Uuid::to_str()
{
	// 8-4-4-4-12
	std::stringstream stream;
	stream << std::hex << most;
	stream << std::hex << least;
	std::string result( stream.str() );
	result.insert(FIRST_SEP_POSITION, 1, SEP);
	result.insert(FIRST_SEP_POSITION + 4, 1, SEP);
	result.insert(FIRST_SEP_POSITION + 4, 1, SEP);
	result.insert(FIRST_SEP_POSITION + 4, 1, SEP);
	return result.c_str();
}

} /* namespace ddd */
