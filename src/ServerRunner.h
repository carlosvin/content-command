/*
 * ServerRunner.h
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#ifndef SERVERRUNNER_H_
#define SERVERRUNNER_H_

#include <grpc++/server_builder.h>
#include <vector>

namespace content {
	class ServerRunner {
	public:
		ServerRunner(const std::string & address, const std::vector<grpc::SynchronousService * > & services);
		~ServerRunner() = default;
	};
}
#endif /* SERVERRUNNER_H_ */
