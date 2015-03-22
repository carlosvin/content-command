/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include "ContentCmdHandlerImpl.h"


namespace cms {

using grpc::ServerContext;
using grpc::Status;

ContentCmdHandlerImpl::ContentCmdHandlerImpl() {
}

ContentCmdHandlerImpl::~ContentCmdHandlerImpl (){

}

Status ContentCmdHandlerImpl::Create(ServerContext* context, const Content* request, CmdResponse* response)
{
	if (request->title().empty())
	{
		response->set_path("title");
		response->set_info("Title cannot be empty");
		response->set_level(CmdResponse_Level_ERROR);
		return Status::Cancelled;
	}
	else
	{
		return Status::OK;
	}
}

}
