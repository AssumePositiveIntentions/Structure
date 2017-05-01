#include <EYW.h>

EYW::Altimeter myalt;
float drop_height = 0;
float current_height=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myalt.begin();
myalt.calibrate(100); //takes first 100 measurements as calibration
myalt.alarm();
}

void loop() {
current_height = myalt.getHeightAvg (20); //takes the average of 20 heights to get current height
Serial.print("Current Height: "+current_height+"");
//Serial.println(current_height);

if (current_height > drop_height){
  myalt.alarm(6,2000,500);
  //intiates the drop mechanism
}
}
