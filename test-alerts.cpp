#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach as TOO_LOW according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach as NORMAL according to limits") {
  REQUIRE(inferBreach(21, 20, 30) == NORMAL);
}

TEST_CASE("infers the breach as NORMAL when any limit is equal to temparature") {
  REQUIRE(inferBreach(30, 20, 20) == NORMAL);
}

TEST_CASE("infers the breach as TOO_HIGH according to limits") {
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
}

TEST_CASE("classify the breach type when PASSIVE_COOLING and temparature is zero") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 0) == NORMAL);
}
