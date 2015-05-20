

#include <iostream>
#include <memory>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/server_credentials.h>
#include "ServerRunner.h"

namespace content {

using namespace std;
using namespace grpc;

ServerRunner::ServerRunner(const string & address, const vector<SynchronousService *> & services)
{
	  ServerBuilder builder;

	  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
	  for (auto s : services){
		  builder.RegisterService(s);
	  }
	  unique_ptr<Server> server(builder.BuildAndStart());
	  cout << address << ": Server listening" << endl;
	  server->Wait();
}

}
