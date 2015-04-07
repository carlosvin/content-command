/*
 * RedisWrapper.h
 *
 *  Created on: 6 de abr. de 2015
 *      Author: carlos
 */

#ifndef REDISWRAPPER_H_
#define REDISWRAPPER_H_

#include <hiredis/hiredis.h>
#include "cms.pb.h"

namespace db {

class RedisWrapper {
private:
	static const int DEFAULT_PORT = 6379;
	static const char * DEFAULT_HOST;

	redisContext *c_;
public:
	RedisWrapper(const char * host, int port);
	RedisWrapper();
	virtual ~RedisWrapper();
	bool is_connected();
	void get_connection_info (cms::CmdResponse * response);


};

} /* namespace db */

#endif /* REDISWRAPPER_H_ */
