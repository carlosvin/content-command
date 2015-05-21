/*
 * EventStore.h
 *
 *  Created on: 21 de may. de 2015
 *      Author: carlos
 */

#ifndef EVENTSTORE_EVENTSTORE_H_
#define EVENTSTORE_EVENTSTORE_H_

#include "Uuid.h"

namespace content
{

virtual class EventStore
{
public:
    virtual ~EventStore() { }

	virtual const char * get_aggregate(const Uuid & id) = 0;
};

}

#endif /* EVENTSTORE_EVENTSTORE_H_ */
