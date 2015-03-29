/*
 * uuid.cpp
 *
 *  Created on: 30/3/2015
 *      Author: carlos
 */


#include "Uuid.h"
#include <bandit/bandit.h>


int main(int argc, char* argv[])
{
  return bandit::run(argc, argv);
}

using namespace bandit;

go_bandit([](){

  describe("our first test", [](){
    it("should fail", [&](){
      AssertThat(5, Equals(6));
    });
  });

});
