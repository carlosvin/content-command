/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include <iostream>
#include "AggregateRepositoryImpl.h"

namespace cms {

using grpc::ServerContext;
using grpc::Status;

using namespace std;

UuidImpl::UuidImpl (int64_t most, int64_t less): most_(most), less_(less)
{
}
UuidImpl::UuidImpl (const UuidImpl & uuid)
{
	most_ = uuid.most_;
	less_ = uuid.less_;
}
UuidImpl::UuidImpl (const Uuid & uuid)
{
	most_ = uuid.least_significant_bits();
	less_ = uuid.most_significant_bits();
}

UuidImpl & UuidImpl::operator=(const Uuid & uuid){
	most_ = uuid.most_significant_bits();
	less_ = uuid.least_significant_bits();
	return *this;
}

UuidImpl &  UuidImpl::operator=(const UuidImpl & id)
{
	most_ = id.most_;
	less_ = id.less_;
	return *this;
}

bool  UuidImpl::operator==(const UuidImpl & id)
{
	return most_ == id.most_ && less_ == id.less_;
}

bool UuidImpl::operator!=(const UuidImpl & id)
{
	return !(*this == id);
}

bool UuidImpl::operator<(const UuidImpl & id)
{
	return most_ < id.most_;
}
bool UuidImpl::operator>(const UuidImpl & id)
{
	return most_ > id.most_;
}
int64_t UuidImpl::most() const{
	return most_;
}
int64_t UuidImpl::less() const{
	return less_;
}


AggregateImpl::AggregateImpl(const Aggregate & aggregate):
	aggregate_(unique_ptr<Aggregate>(new Aggregate(aggregate)))
{

}

AggregateImpl::AggregateImpl(const AggregateImpl & aggregate):
		AggregateImpl(*(aggregate.aggregate_))
{

}

AggregateImpl & AggregateImpl::operator=(const AggregateImpl & aggregate)
{
	*aggregate_ = *(aggregate.aggregate_);
}

AggregateImpl::~AggregateImpl(){}

void AggregateImpl::lock()
{
	mutex_.lock();
}
void  AggregateImpl::unlock()
{
	mutex_.unlock();
}


AggregateRepositoryImpl::AggregateRepositoryImpl() {
}



Status AggregateRepositoryImpl::get(ServerContext* context, const Uuid* request, Aggregate* response)
{
	Status status = Status::Cancelled;
	mutex_.lock();
	Uuid id = *request;
	auto search = aggregates_.find(id );
	if(search != aggregates_.end())
	{
		aggregates_[id ]->lock();
		//aggregate->lock();
		//*response = *aggregate;
		status =  Status::OK;
	}
	mutex_.unlock();
	return status;
}

Status AggregateRepositoryImpl::set(ServerContext* context, const Aggregate* request, CmdResponse* response)
{
	Uuid id = request->aggregateid();

	mutex_.lock();
	auto search = aggregates_.find(id);
	if(search == aggregates_.end())
	{
		//auto aggregate = std::unique_ptr<AggregateImpl>(new AggregateImpl(*request));
		aggregates_[id] = unique_ptr<AggregateImpl>(new AggregateImpl(*request));
		response->set_info("New aggregate added");
	}
	else
	{
		*(aggregates_[id]) = *request;
		aggregates_[id]->unlock();
		response->set_info("Aggregate updated");
	}
	mutex_.unlock();
	response->set_level(CmdResponse_Level_INFO);
	response->set_path("Aggregate");
	return Status::OK;
}

}
