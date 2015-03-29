/*
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#ifndef CONTENT_AGGREGATEREPOSITORYIMPL_H_
#define CONTENT_AGGREGATEREPOSITORYIMPL_H_

#include <map>
#include <memory>
#include <mutex>
#include <grpc++/server.h>
#include <grpc++/server_context.h>
#include <grpc++/status.h>
#include "cms.pb.h"

/**
 * TODO now it is a stateful service, but when we store this info in a NoSQL repository we can re-implemented as stateless service.
 * */
namespace cms {

class UuidImpl {
private:
	int64_t most_;
	int64_t less_;
public:
	UuidImpl (int64_t most, int64_t less);
	UuidImpl (const UuidImpl & uuid);
	UuidImpl (const Uuid & uuid);

	virtual ~UuidImpl() = default;

	UuidImpl & operator=(const Uuid & id);
	UuidImpl & operator=(const UuidImpl & id);
	bool operator==(const UuidImpl & id);
	bool operator!=(const UuidImpl & id);
	bool operator<(const UuidImpl & id);
	bool operator>(const UuidImpl & id);

	int64_t most() const;
	int64_t less() const;
};

struct UuidComparer
{
    bool operator()(const UuidImpl  &uuid1,const UuidImpl  &uuid2) const {
    	return uuid1.most() < uuid2.most();
    }
};

class AggregateImpl
{
private:
	std::mutex mutex_;
	std::unique_ptr<Aggregate> aggregate_;
public:
	AggregateImpl(const Aggregate & aggregate);
	virtual ~AggregateImpl();


	AggregateImpl(const AggregateImpl & aggregate);
	AggregateImpl & operator=(const AggregateImpl & aggregate);

	bool try_lock();
	void unlock();
};

class AggregateRepositoryImpl final: public AggregateRepository::Service
{
private:
	std::mutex mutex_;
	std::map<UuidImpl, std::unique_ptr<AggregateImpl>, UuidComparer> aggregates_;

public:
	explicit AggregateRepositoryImpl();
	~AggregateRepositoryImpl() = default;

	virtual ::grpc::Status get(::grpc::ServerContext* context, const ::cms::Uuid* request, ::cms::Aggregate* response);
	virtual ::grpc::Status set(::grpc::ServerContext* context, const ::cms::Aggregate* request, ::cms::CmdResponse* response);
};

}
#endif /* CONTENT_AGGREGATEREPOSITORYIMPL_H_ */
