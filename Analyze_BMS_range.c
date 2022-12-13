#include <stdio.h>
#include "Analyze_BMS_range.h"

void printError(char* errStr)
{
    printf("%s\n",errStr);
}

int batteryTempIsOk(float temperature)
{
  if(temperature < 0 || temperature > 45) 
  {
    printError("Temperature out of range!");
    return 0;
  }
  return 1;
}

int batterySocIsOk(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printError("State of Charge out of range!");
    return 0;
  }
  return 1;
}

int batterychargeRateIsOk(float chargeRate)
{
  if(chargeRate > 0.8) 
  {
    printError("Charge Rate out of range!");
    return 0;
  }
  return 1;
}
