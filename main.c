#include <stdio.h>
#include <assert.h>
#include "Analyze_BMS_range.h"
#include "BMS_Check.h"

extern int (*fun_ptr_arr[])(float) = {batteryTempIsOk, batterySocIsOk, batterychargeRateIsOk};
void main()
{
	//Test for batteryIsOk function
	assert(batteryIsOk(25, 70, 0.7));
	assert(!batteryIsOk(50, 85, 0));
	assert(!batteryIsOk(30, 50, 0.9));
	assert(!batteryIsOk(60, 70, 1.0));
	
	//Test for batteryTempIsOk function
	assert(((*fun_ptr_arr[0])(40)));
	assert(!((*fun_ptr_arr[0])(-20)));
	assert(!((*fun_ptr_arr[0])(60)));
	
	//Test for batterySocIsOk function
	assert(((*fun_ptr_arr[1])(55)));
	assert(!((*fun_ptr_arr[1])(10)));
	assert(!((*fun_ptr_arr[1])(90)));
	
	//Test for batterychargeRateIsOk function
	assert(((*fun_ptr_arr[2])(0.7)));
	assert(!((*fun_ptr_arr[2])(1.0)));
	assert(!((*fun_ptr_arr[2])(0.9)));
}