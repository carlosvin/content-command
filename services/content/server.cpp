#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "ContentCmdHandlerImpl.h"

//#include <grpc++/server.h>
//#include <grpc++/server_builder.h>
//#include <grpc++/server_context.h>
//#include <grpc++/server_credentials.h>
//#include <grpc++/status.h>
//#include "cms.pb.h"
//
//using grpc::Server;
//using grpc::ServerBuilder;
//using grpc::ServerContext;
//using grpc::Status;



int main(int argc, char** argv) {
	grpc_init();

	cms::ContentCmdHandlerImpl content_cmd_handler{};
	grpc_shutdown();
	return 0;
}
