#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach as TOO_LOW according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach as NORMAL according to limits") {
  REQUIRE(inferBreach(21, 20, 30) == NORMAL);
}

TEST_CASE("infers the breach as NORMAL when temparature, lower limit and upper limit are equal") {
  REQUIRE(inferBreach(20, 20, 20) == NORMAL);
}

TEST_CASE("infers the breach as TOO_HIGH according to limits") {
  REQUIRE(inferBreach(31, 20, 30) == TOO_HIGH);
}

TEST_CASE("classify the breach type when PASSIVE_COOLING and temparature is -5") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -5) == TOO_LOW);
}

TEST_CASE("classify the breach type when PASSIVE_COOLING and temparature is zero") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 0) == NORMAL);
}

TEST_CASE("classify the breach type when PASSIVE_COOLING and temparature is 10") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 10) == NORMAL);
}

TEST_CASE("classify the breach type when PASSIVE_COOLING and temparature is 36") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
}


