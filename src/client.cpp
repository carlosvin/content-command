

#include <iostream>
#include <grpc/grpc.h>
#include <grpc++/server.h>

using namespace std;


int main(void) {
	grpc_init();
	cout << "client" << endl;
	grpc_shutdown();
	return 0;
}
