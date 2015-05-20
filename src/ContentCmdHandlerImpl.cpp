/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include "ContentCmdHandlerImpl.h"
#include <iostream>


namespace content {

using grpc::ServerContext;
using grpc::Status;

using namespace std;

ContentCmdHandlerImpl::ContentCmdHandlerImpl() {
}

ContentCmdHandlerImpl::~ContentCmdHandlerImpl (){

}

Status ContentCmdHandlerImpl::save (ServerContext* context, const Content* request, CmdResponse* response){
	cout << "save" << endl;
	return Status::OK;
}

Status ContentCmdHandlerImpl::remove (ServerContext* context, const Uuid* request, CmdResponse* response){
	cout << "remove" << endl;
	return Status::OK;
}

Status ContentCmdHandlerImpl::removePart (ServerContext* context, const Uuid* request, CmdResponse* response){
	cout << "removePart" << endl;
	return Status::OK;
}

Status ContentCmdHandlerImpl::updatePart (ServerContext* context, const UpdatePart* request, CmdResponse* response){
	cout << "updatePart" << endl;
	return Status::OK;
}

}
