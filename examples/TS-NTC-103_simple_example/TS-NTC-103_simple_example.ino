#include <TS-NTC-103_simple.h>

void setup() {
 Serial.begin(9600);
}

void loop() {
  TS_NTC_103 sensor; //start an instance of the library
  //TS_NTC_103 sensor(3.3,12);support for 3.3 volt board and/or 12bit analog read resolution
  Serial.print("temp: ");
  Serial.println(sensor.getTemp(analogRead(0)));
  delay(1000);

}
