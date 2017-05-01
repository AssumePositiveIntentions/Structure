#include <EYW.h>

EYW::Altimeter a;

float drop_height = 0; //input initial drop height
float current_height = 0; //input initial drop height

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
a.begin();
a.calibrate(100); //takes first 100 measurements as calibration
a.alarm();
}

void loop() {
current_height = a.getHeightAvg (20);//takes the average of 20 heights to get current height
Serial.print("Current Height: "+current_height+"");

if (current_height > drop_height){
  a.alarm(6,2000,500);
  //intiates the drop mechanism
}
}
