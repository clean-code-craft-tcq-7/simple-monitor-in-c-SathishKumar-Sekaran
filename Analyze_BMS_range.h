
typedef struct 
{
	float min;
	float max;
}st_BMSParameters;

void printError(char*);
int BMS_ParameterErrCheck(float,float,float,const char*);
int checkMinBatteryTolerance(float,st_BMSParameters,int);
int checkMaxBatteryTolerance(float ,st_BMSParameters ,int);
