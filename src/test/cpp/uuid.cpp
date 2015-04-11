/*
 * uuid.cpp
 *
 *  Created on: 30/3/2015
 *      Author: carlos
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "Uuid.h"
#include <catch.hpp>

ddd::Uuid uuid;

TEST_CASE( "Uuid", "[uuid]" ) {
    REQUIRE( uuid.to_str() != nullptr );
}
