#include <stdio.h>
#include "Analyze_BMS_range.h"

extern const char* bmsAlertPrintMsg[TOTAL_LANGUAGE][TOTAL_ERROR_MSG * BMS_ERROR_LIMIT];
extern int selectLanguage;
extern int tolerancePercentage;
extern st_BMSParameters st_BatterTemp,st_BatterSoc,st_BatterChargeRate;

void printError(char* errStr)
{
    printf("%s\n",errStr);
}

int BMS_ParameterErrCheck(float bmsValue,float min,float max,const char* printBuf)
{
  if(bmsValue < min || bmsValue > max) 
  {
    printError(printBuf);
    return 0;
  }
  return 1;
}

int checkMinBatteryTolerance(float bmsValue,st_BMSParameters batteryParameterVal,int Count)
{
	int return_Status = 1;
	float toleranceVal = TOLERANCE_VALUE(batteryParameterVal.max,tolerancePercentage);
	toleranceVal = toleranceVal + batteryParameterVal.min;
	if(bmsValue <= toleranceVal)
	{
		printError(bmsAlertPrintMsg[selectLanguage][Count]);
		return_Status = 0;
	}
	return return_Status;
}

int checkMaxBatteryTolerance(float bmsValue,st_BMSParameters batteryParameterVal,int Count)
{
	int return_Status = 1;
	float toleranceVal = TOLERANCE_VALUE(batteryParameterVal.max,tolerancePercentage);
	toleranceVal = batteryParameterVal.max - toleranceVal ;
	if(bmsValue >= toleranceVal)
	{
		printError(bmsAlertPrintMsg[selectLanguage][Count+3]);
		return_Status = 0;
	}
	return return_Status;
}

int batteryMidLevelCheck(float batteryParameterVal, float maxParameterVal)
{
	float maxParameterMidVal = maxParameterVal/2;
	if(batteryParameterVal < maxParameterMidVal)
	{
		return 0;
	}
	return 1;
}

