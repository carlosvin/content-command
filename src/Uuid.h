/*
 * Uuid.h
 *
 *  Created on: 29/3/2015
 *      Author: carlos
 */

#ifndef UUID_H_
#define UUID_H_

#include <random>


namespace ddd {

class Uuid {
private:
	static constexpr char SEP = '-';
	static constexpr short FIRST_SEP_POSITION = 8;

	static int64_t get_rnd();

public:
	const int64_t most, least;

	Uuid(int64_t most, int64_t least);
	/**
	 * automatic generation of this uuid
	 * */
	Uuid();

	Uuid(const Uuid & id);

	bool operator==(const Uuid & id);
	bool operator!=(const Uuid & id);

	~Uuid() = default;

	const char * to_str();

};

} /* namespace ddd */

#endif /* UUID_H_ */
