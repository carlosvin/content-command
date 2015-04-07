/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include "ContentCmdHandlerImpl.h"
#include <iostream>
#include "RedisWrapper.h"


namespace cms {

using grpc::ServerContext;
using grpc::Status;

using namespace std;

ContentCmdHandlerImpl::ContentCmdHandlerImpl() {
}

ContentCmdHandlerImpl::~ContentCmdHandlerImpl (){

}

Status ContentCmdHandlerImpl::create(ServerContext* context, const Content* request, CmdResponse* response)
{
	cout << "handling request <-(" << request->title() <<")"<< endl;
	if (request->title().empty())
	{
		response->set_path("Content.title");
		response->set_info("Title cannot be empty");
		response->set_level(CmdResponse_Level_ERROR);
		return Status::Cancelled;
	}
	else
	{
		Status status;
		redisContext *c = redisConnect("127.0.0.1", 6379);
		if (c == nullptr){
			response->set_path("Content");
			response->set_level(CmdResponse_Level_ERROR);
			response->set_info("Cannot get connection");
			return Status::Cancelled;
		}else if (c->err) {
			response->set_path("Content");
			response->set_level(CmdResponse_Level_ERROR);
			response->set_info((const char *)c->errstr);
		    redisFree(c);
			return Status::Cancelled;
		}else{
			response->set_path("Content");
			response->set_level(CmdResponse_Level_DEBUG);
			response->set_info("Content created properly");
			redisReply *reply = (redisReply *)redisCommand(c, "PING");
		    cout << "PING: " << reply->str << endl;
		    freeReplyObject(reply);
		    redisFree(c);
			return Status::OK;
		}
	}
}

}
