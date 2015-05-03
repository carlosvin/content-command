/*
 * Uuid.cpp
 *
 *  Created on: 29/3/2015
 *      Author: carlos
 */

#include "Uuid.h"
#include <iomanip>
#include <sstream>
#include <functional>
#include <chrono>

namespace ddd {

using namespace std;

auto SEED = chrono::system_clock::now().time_since_epoch().count();
auto RND =  bind (uniform_int_distribution<int64_t>{}, mt19937{SEED} );


Uuid::Uuid(): most(get_rnd()), least(get_rnd()){}

Uuid::Uuid(int64_t m, int64_t l): most(m), least(l) {}

Uuid::Uuid(const Uuid & id): most(id.most), least(id.least)
{
}

bool Uuid::operator==(const Uuid & id){
	return most == id.most && least == id.least;
}

bool Uuid::operator!=(const Uuid & id){
	return !(*this == id);
}

int64_t Uuid::get_rnd()
{
	return RND();
}

const char * Uuid::to_str()
{
	// 8-4-4-4-12
	stringstream stream;
	stream << hex << most << least;
	string result( stream.str() );
	for (int i=0; i<4; i++)
	{
		result.insert(FIRST_SEP_POSITION + (i * 4) + i, 1, SEP);
	}
	return result.c_str();
}

} /* namespace ddd */
