#include <stdio.h>
#include "Analyze_BMS_range.h"
#include "BMS_Check.h"

int (*fun_ptr_arr[])(float) = {batteryTempIsOk, batterySocIsOk, batterychargeRateIsOk};

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
	float batteryParameter[3]={temperature,soc,chargeRate};
	int return_Status = 1;
	for(int loopCnt=0;loopCnt<3;loopCnt++)
	{
		return_Status &= (*fun_ptr_arr[loopCnt])(batteryParameter[loopCnt]);
	}
	return return_Status;
}