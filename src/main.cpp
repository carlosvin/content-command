#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "ContentCmdHandlerImpl.h"
#include "ServerRunner.h"


using namespace std;
using namespace content;

constexpr int DEFAULT_PORT = 10001;

int get_port (int argc, char ** argv)
{
	return argc > 1 ? stoi(argv[1]) : DEFAULT_PORT;
}

string get_address(int argc, char ** argv)
{
	// TODO we can add set the host as configurable as parameter
	return string{"0.0.0.0:"} + to_string(get_port(argc, argv));
}

int main(int argc, char** argv) {

	const string address = get_address(argc, argv);

	grpc_init();

	ContentCmdHandlerImpl content_cmd_handler{};

	ServerRunner server_runner {address, {&content_cmd_handler}};

	grpc_shutdown();

	return 0;
}
