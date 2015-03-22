/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include "ContentCmdHandlerImpl.h"
#include <iostream>

namespace cms {

using grpc::ServerContext;
using grpc::Status;

using namespace std;

ContentCmdHandlerImpl::ContentCmdHandlerImpl() {
}

ContentCmdHandlerImpl::~ContentCmdHandlerImpl (){

}

Status ContentCmdHandlerImpl::Create(ServerContext* context, const Content* request, CmdResponse* response)
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
		response->set_path("Content");
		response->set_level(CmdResponse_Level_DEBUG);
		response->set_info("Content created properly");
		return Status::OK;
	}
}

}
