#include <stdio.h>
#include "Analyze_BMS_range.h"
#include "BMS_Check.h"

const char* bmsErrorPrintMsg[TOTAL_LANGUAGE][TOTAL_ERROR_MSG] = {
			{
				"Temperature out of range!",
				"State of Charge out of range!",
				"Charge Rate out of range!",
			},
			{
				"Temperatur außerhalb des Bereichs!",
				"Ladezustand außerhalb des Bereichs!",
				"Laderate außerhalb des Bereichs!",
			}
		};
			
const char* bmsAlertPrintMsg[TOTAL_LANGUAGE][TOTAL_ERROR_MSG * BMS_ERROR_LIMIT] =  {
			{	
				"Alert!! Temperature range is going to Low!",
				"Alert!! State of Charge range is going to Low!",
				"Alert!! Charge Rate range is going to Low!",
				"Alert!! Temperature range is going to High!",
				"Alert!! State of Charge range is going to High!",
				"Alert!! Charge Rate range is going to High!",
			},
			{
				"Alarm!! Temperaturbereich wird niedrig!",
				"Alarm!! Der Ladezustand wird niedrig!",
				"Alarm!! Der Laderatenbereich wird niedrig!",
				"Alarm!! Temperaturbereich wird hoch!",
				"Alarm!! Der Ladezustand wird hoch!",
				"Alarm!! Der Laderatenbereich wird hoch!",
			}
		};			

st_BMSParameters st_BatterTemp,st_BatterSoc,st_BatterChargeRate;

int selectLanguage = ENGLISH;
int tolerancePercentage = 5;

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
	float batteryParameterValues[3]={temperature,soc,chargeRate};
	st_BMSParameters batteryParameter[3] = {st_BatterTemp,st_BatterSoc,st_BatterChargeRate};
	int return_Status = 1;
	for(int loopCnt=0;loopCnt<3;loopCnt++)
	{
		return_Status &= BMS_ParameterErrCheck(batteryParameterValues[loopCnt],batteryParameter[loopCnt].min,
								batteryParameter[loopCnt].max,bmsErrorPrintMsg[selectLanguage][loopCnt]);
	}
	return return_Status;
}

int checkBatteryWarning(float temperature, float soc, float chargeRate) 
{
	float batteryParameterValues[3]={temperature,soc,chargeRate};
	st_BMSParameters batteryParameter[3] = {st_BatterTemp,st_BatterSoc,st_BatterChargeRate};
	int return_Status = 1;
	int return_MidLevel = 0;
	int (*warnCheck_ptr[])(float,st_BMSParameters,int) = {checkMinBatteryTolerance,checkMaxBatteryTolerance};
	for(int loopCnt=0;loopCnt<3;loopCnt++)
	{
		return_MidLevel = batteryMidLevelCheck(batteryParameterValues[loopCnt],batteryParameter[loopCnt].max);
		printf("return_MidLevel : %d\n",return_MidLevel);
		return_Status &= (*warnCheck_ptr[return_MidLevel])(batteryParameterValues[loopCnt],batteryParameter[loopCnt],loopCnt);
	}
	return return_Status;
}
