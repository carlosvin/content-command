#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "ContentCmdHandlerImpl.h"
#include "ServerRunner.h"


using namespace std;
using namespace cms;

constexpr int DEFAULT_PORT = 10001;

int main(int argc, char** argv) {

	const string address = "0.0.0.0:10001";

	grpc_init();

	cms::ContentCmdHandlerImpl content_cmd_handler{};

	cms::ServerRunner server_runner {address, {&content_cmd_handler}};

	grpc_shutdown();

	return 0;
}


int get_port (int argc, char ** argv)
{
	return argc > 1 ? stoi(argv[1]) : DEFAULT_PORT;
}
