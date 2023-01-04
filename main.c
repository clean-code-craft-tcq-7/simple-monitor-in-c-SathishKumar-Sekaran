#include <stdio.h>
#include <assert.h>
#include "Analyze_BMS_range.h"
#include "BMS_Check.h"

extern int selectLanguage;
extern int tolerancePercentage;
extern st_BMSParameters st_BatterTemp,st_BatterSoc,st_BatterChargeRate;

int main()
{
	st_BatterTemp.min = 0;
	st_BatterTemp.max = 45;
	st_BatterSoc.min = 20;
	st_BatterSoc.max = 80;
	st_BatterChargeRate.min = 0;
	st_BatterChargeRate.max = 0.8;
	//Test for batteryIsOk function
	assert(batteryIsOk(25, 70, 0.7));
	assert(!batteryIsOk(50, 85, 0));
	selectLanguage = ENGLISH;
	assert(!batteryIsOk(30, 50, 0.9));
	assert(!batteryIsOk(60, 70, 1.0));
	
	//Test for checkBatteryWarning function
	assert(!checkBatteryWarning(2,78,0.77));
	tolerancePercentage = 10;
	assert(!checkBatteryWarning(20,73,0.6));
	assert(!checkBatteryWarning(35,67,0.73));
	selectLanguage = GERMAN;
	assert(!checkBatteryWarning(42.5,72,0.5));
	assert(!checkBatteryWarning(43,74,0.72));
	assert(checkBatteryWarning(40,55,0.5));
	
	return 0;
}
