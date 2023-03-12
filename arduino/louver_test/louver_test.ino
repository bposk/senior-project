#include <Servo.h>
Servo servo1;
Servo servo2;

int servo1max = 140;
int servo2max = 120;
int servo1min = 60;
int servo2min = 10;

void setup() {
  // put your setup code here, to run once:
servo1.attach(12);
servo2.attach(13);

servo1.write((servo1max+servo1min)/2);
servo2.write((servo2max+servo2min)/2);
}

void loop() {
  for(int i = servo1min; i < servo1max; i++){
    servo1.write(i);
    delay(10);
  }
  for(int i = servo2min; i < servo2max; i++){
    servo2.write(i);
    delay(10);
  }
  for(int i = servo1max; i > servo1min; i--){
    servo1.write(i);
    delay(10);
  }
  for(int i = servo2max; i > servo2min; i--){
    servo2.write(i);
    delay(10);
  }
}
