/*
 * RedisWrapper.cpp
 *
 *  Created on: 6 de abr. de 2015
 *      Author: carlos
 */

#include "RedisWrapper.h"

namespace db {

using namespace cms;

const char * RedisWrapper::DEFAULT_HOST = "127.0.0.1";

RedisWrapper::RedisWrapper()
{
	c_ = redisConnect(RedisWrapper::DEFAULT_HOST, RedisWrapper::DEFAULT_PORT);
}

RedisWrapper::RedisWrapper(const char * host, int port)
{
	c_ = redisConnect(host, port);
}

bool RedisWrapper::is_connected()
{
	return !(c_ == nullptr || c_->err);
}

void RedisWrapper::get_connection_info (cms::CmdResponse * response)
{
	if (c_ == nullptr){
		response->set_path("Redis Wrapper");
		response->set_level(CmdResponse_Level_ERROR);
		response->set_info("Cannot get connection");
	}else if (c_->err) {
		response->set_path("Redis Wrapper");
		response->set_level(CmdResponse_Level_ERROR);
		response->set_info((const char *)c_->errstr);
	}else{
		response->set_path("Redis Wrapper");
		response->set_level(CmdResponse_Level_DEBUG);
		response->set_info("Connected");
	}
}

RedisWrapper::~RedisWrapper()
{
	if (c_ != nullptr)
	{
		redisFree(c_);
	}
}

}
