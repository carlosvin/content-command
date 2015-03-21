/*
 * ReportResponse.cpp
 *
 *  Created on: 19/3/2015
 *      Author: carlos
 */

#include "../libcmslight/ReportResponse.h"

using namespace std;

Response::Response(const Level level, const string & msg): level_(level), msg_(msg) {}

ReportResponse::ReportResponse(const std::vector<Response> & responses): responses_(responses){}
