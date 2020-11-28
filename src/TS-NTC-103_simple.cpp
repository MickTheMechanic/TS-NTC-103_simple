#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "TS-NTC-103_simple.h"


TS_NTC_103::TS_NTC_103() : resistance{ //resistance array
	301,335,372,415,464,520,596,671,757,857,974,1108,
	1266,1451,1669,1925,2229,2589,3537,4162,4912,5829,6941,8314,
	10000,12090,14680,17950,22030,27250,33850,42390,53310,67640		
	},
	temp_C{ //temperature array in celcius
	150,145,140,135,130,125,120,115,110,105,100,95,90,85,80,75,70,65,60,
	55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40
	}
	{
	}


TS_NTC_103::TS_NTC_103(float vRef, int RESO) : resistance{ //resistance array
	301,335,372,415,464,520,596,671,757,857,974,1108,
	1266,1451,1669,1925,2229,2589,3537,4162,4912,5829,6941,8314,
	10000,12090,14680,17950,22030,27250,33850,42390,53310,67640	
	},
	temp_C{ //temperature array in celcius
	150,145,140,135,130,125,120,115,110,105,100,95,90,85,80,75,70,65,60,
	55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40
	}
	{
		_vRef = vRef;
		if(RESO==12) _RESO = 4095;
	}


float TS_NTC_103::getTemp(int reading){//input a bitrade value from analog input
	float Vin = 0;
	Vin = reading*_vRef/_RESO;	//find voltage in the input
	float r = (Vin / (_vRef - Vin) * rRef); //calculate the resistance
	//find between resistance in the table
	int i = 0;
	while(resistance[i]<r)i++;	
	//find m and b value of y=mx+b ==>	
	float m = (temp_C[i]-temp_C[i-1])/(resistance[i]-resistance[i-1]);// m = (y1-y2)/(x1-x2)	
	float b = temp_C[i-1]-(m*resistance[i-1]);//find b = y1 - m*x1*/
	float temp = m*r+b; //y=mx+b
	return temp;
}
