/*
 * uuid.cpp
 *
 *  Created on: 30/3/2015
 *      Author: carlos
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "Uuid.h"
#include "test/catch.hpp"
#include <string>

constexpr int MAX_ITERS = 1000;

TEST_CASE( "Uuid", "[uuid]" ) {
  for (int i=0; i<MAX_ITERS; i++){
    ddd::Uuid uuid;
    std::string uuid_str {uuid.to_str()};

    INFO(uuid_str);
    REQUIRE(uuid.most > 0);
    REQUIRE(uuid.least > 0);
    REQUIRE(uuid_str.size() == 36);
  }

}

/*
SCENARIO( "UUID creation", "[Uuid]" ) {

    for (int i=0; i<MAX_ITERS; i++){
      ddd::Uuid uuid;
      std::string uuid_str {uuid.to_str()};

      GIVEN( "A random UUID " + uuid_str) {
    	REQUIRE(uuid_str.size() == 36);

	WHEN( "get the most and least" ) {
		THEN( "should be more than 0" ) {
			REQUIRE( uuid.most > 0);
			REQUIRE( uuid.least > 0);

		}
	}

      }
    }
}*/

