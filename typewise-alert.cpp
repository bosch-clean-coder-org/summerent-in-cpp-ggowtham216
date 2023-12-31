#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int limits[][2] = {
    {0, 35},    // PASSIVE_COOLING
    {0, 45},    // HI_ACTIVE_COOLING
    {0, 40}     // MED_ACTIVE_COOLING
  };

  int coolingIndex = static_cast<int>(coolingType);
  double lowerLimit = limits[coolingIndex][0];
  double upperLimit = limits[coolingIndex][1];

  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  const char* messages[] = {
    "",                               // NORMAL
    "Hi, the temperature is too low", // TOO_LOW
    "Hi, the temperature is too high" // TOO_HIGH
  };
  int index = static_cast<int>(breachType);
  const char* message = messages[index];
  if (message[0] != '\0') {
    printf("To: %s\n", recepient);
    printf("%s\n", message);
  }
}
