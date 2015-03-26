
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include <grpc/grpc.h>
#include <grpc++/channel_arguments.h>
#include <grpc++/channel_interface.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/credentials.h>
#include <grpc++/status.h>
#include "cms.pb.h"

using grpc::ChannelArguments;
using grpc::ChannelInterface;
using grpc::ClientContext;
using grpc::Status;
using cms::Content;
using cms::CmdResponse;
using cms::ContentCmdHandler;

/*
 * This client is only for tests purposes, the actual client will be developed in dart
 * */
class ContentCmdClient {
public:
	ContentCmdClient(std::shared_ptr<ChannelInterface> channel) :
			stub_(ContentCmdHandler::NewStub(channel)) {
	}

	std::string create_content(const std::string & title) {
		Content content;
		content.set_title(title);

		CmdResponse response;
		ClientContext context;

		Status status = stub_->create(&context, content, &response);
		if (status.IsOk()) {
			return "OK: " + to_string(response);
		} else {
			return "Fail: " + to_string(response);
		}
	}

	void Shutdown() {
		stub_.reset();
	}

private:
	std::unique_ptr<ContentCmdHandler::Stub> stub_;

	std::string to_string (const CmdResponse & resp){
		std::string r;
		r.append("level"); // TODO convert level to string
		r.append(" : ");
		r.append(resp.path());
		r.append(" : ");
		r.append(resp.info());

		return r;
	}
};

int main(int argc, char** argv) {
	grpc_init();

	ContentCmdClient client(
			grpc::CreateChannel("localhost:10001", grpc::InsecureCredentials(),
					ChannelArguments()));


	std::cout << client.create_content("title")<< std::endl;
	std::cout << client.create_content("")<< std::endl;

	client.Shutdown();

	grpc_shutdown();
}
