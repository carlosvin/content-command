#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "ContentCmdHandlerImpl.h"
#include "ServerRunner.h"


using namespace std;
using namespace cms;

int main(int argc, char** argv) {

	const string address = "0.0.0.0:10001";

	grpc_init();

	cms::ContentCmdHandlerImpl content_cmd_handler{};

	cms::ServerRunner server_runner {address, {&content_cmd_handler}};

	grpc_shutdown();

	return 0;
}
