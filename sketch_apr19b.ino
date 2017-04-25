#include <EYW.h>

EYW::Altimeter myalt;

float current_height=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myalt.begin();
myalt.calibrate(100);
myalt.alarm();
}

void loop() {
  // put your main code here, to run repeatedly:
current_height = myalt.getHeightAvg (20);
Serial.print("Current Height: ");
Serial.println(current_height);

if (current_height>1){
  myalt.alarm(6,2000,500);
}
}
