
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
using cms::CmdResponse;
using cms::Aggregate;
using cms::AggregateRepository;
using cms::Uuid;
using namespace std;
/*
 * This client is only for tests purposes, the actual client will be developed in dart
 * */
class AggregateClient {
public:
	AggregateClient(std::shared_ptr<ChannelInterface> channel) :
			stub_(AggregateRepository::NewStub(channel)) {
	}


	void get(const Uuid & request, Aggregate * response){
		ClientContext context;
		Status status = stub_->get(&context, request, response);
		if (status.IsOk())
		{
			cout << "OK:\tget " << request.most_significant_bits() << "-" << request.least_significant_bits() << endl;
			//return response;
		}
		else
		{
			cout << "Err:\tget " << request.most_significant_bits() << "-" << request.least_significant_bits() << endl;
			//return nullptr;
		}
	}

    bool set(const Uuid & id, int version, const string & data)
    {
		CmdResponse response;
    	ClientContext context;
    	Aggregate request;
    	request.set_allocated_aggregateid(new Uuid{id});
    	request.set_data(data);
    	request.set_version(version);
		Status status = stub_->set(&context, request, &response);
		cout << to_string(response) << endl;
		return status.IsOk();
    }

	void Shutdown() {
		stub_.reset();
	}

private:
	std::unique_ptr<AggregateRepository::Stub> stub_;

	std::string to_string (const CmdResponse & resp)
	{
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

	Uuid id;
	id.set_least_significant_bits(1);
	id.set_most_significant_bits(2);


	AggregateClient client{grpc::CreateChannel("localhost:10001", grpc::InsecureCredentials(), ChannelArguments())};

	auto set_result = client.set(id, 1, "BLA") ? "OK" : "Fail";
	cout << "set: " <<  set_result  << endl;

	Aggregate aggregate_response;
	client.get(id,&aggregate_response);
	cout <<  "get: " << aggregate_response.data() << endl;

	client.Shutdown();

	grpc_shutdown();
}
