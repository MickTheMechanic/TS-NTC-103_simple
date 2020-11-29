// This file is part of uHTTP.
//
// uHTTP is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// uHTTP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.


		/*/////////////////////////////////////////////////
	First, read a value, then convert it to volt, then resistance
	Reading is base on a lookup table and use y=mx+b between interval
	where x = the resistance and y, the temperature==>
	to find m: take the between value on the table==>
		(y2-y1)/(x2-x1)
	then, find b = y - mx1
	finaly, apply the formula to the read resistance
		reading = m*(resistance read) +b
		/////////////////////////////////////////////////*/



#ifndef TS-NTC-103_simple
#define TS-NTC-103_simple

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif


#ifndef rRef
#define rRef 10000
#endif

class TS_NTC_103 {
public:
       
	TS_NTC_103(float vRef = 5, byte RESO = 10);
	float getTemp(int reading);
	
private:
	
	int _RESO;
	float _vRef;
};

#endif

