/*
 * ReportResponse.h
 *
 *  Created on: 19/3/2015
 *      Author: carlos
 */

#ifndef REPORTRESPONSE_H_
#define REPORTRESPONSE_H_

#include <string>
#include <vector>

/**
 *
 * */

class Response {

public:
	enum class Level { DEBUG, INFO, WARN, ERROR };

	Response(const Level level, const std::string & msg);
	~Response() = default;

private:
	const Level level_;
	const std::string msg_;
};

/**
 * Class to encapsulate a response when we execute a remote call
 * */
class ReportResponse {

public:
	ReportResponse(const std::vector<Response> & responses_);
	~ReportResponse() = default;

private:
	const std::vector<Response> & responses_;

};

#endif /* REPORTRESPONSE_H_ */
