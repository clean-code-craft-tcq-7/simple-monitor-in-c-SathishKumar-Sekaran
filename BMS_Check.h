#define TOTAL_ERROR_MSG			3
#define TOTAL_LANGUAGE			2
#define BMS_ERROR_LIMIT			2

#define ENGLISH					0
#define GERMAN					1

#define TOLERANCE_VALUE(maxVal,Percentage)  (maxVal*Percentage/100)

int batteryIsOk(float temperature, float soc, float chargeRate);
int checkBatteryWarning(float temperature, float soc, float chargeRate);
