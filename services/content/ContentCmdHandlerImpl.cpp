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
    return Status::OK;
}

}
