/*
 * ContentCmdHandlerImpl.h
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#ifndef CONTENT_CONTENTCMDHANDLERIMPL_H_
#define CONTENT_CONTENTCMDHANDLERIMPL_H_

//#include <grpc++/server_credentials.h>
//#include <grpc++/server_builder.h>

#include <grpc++/server.h>
#include <grpc++/server_context.h>
#include <grpc++/status.h>
#include "content.grpc.pb.h"

namespace content {

class ContentCmdHandlerImpl final: public ContentCmdHandler::Service {

public:
	explicit ContentCmdHandlerImpl();
	~ContentCmdHandlerImpl();

	grpc::Status save(grpc::ServerContext* context, const Content* request, CmdResponse* response) override;
	grpc::Status remove(grpc::ServerContext* context, const Uuid* request, CmdResponse* response) override;
	grpc::Status removePart(grpc::ServerContext* context, const Uuid* request, CmdResponse* response) override;
	grpc::Status updatePart(grpc::ServerContext* context, const UpdatePart* request, CmdResponse* response) override;
};

}
#endif /* CONTENT_CONTENTCMDHANDLERIMPL_H_ */
