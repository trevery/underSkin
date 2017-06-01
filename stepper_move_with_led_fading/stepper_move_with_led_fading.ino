#include <AccelStepper.h>
#include <AFMotor.h>

// two stepper motors one on each port
AF_Stepper motor1(200, 1);
AF_DCMotor motor2(4);

// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}

// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);

const int ledPin = A0;


void setup()
{  
    pinMode(ledPin, OUTPUT);
    motor2.setSpeed(200);
    motor2.run(RELEASE);
    stepper1.setMaxSpeed(500.0);
    stepper1.setAcceleration(200.0);
    stepper1.moveTo(-150);
 
}


void loop()
{   
    int val = stepper1.distanceToGo();
    if (stepper1.distanceToGo() == 0)
  stepper1.moveTo(-stepper1.currentPosition());
    motor2.run(FORWARD);
    motor2.setSpeed(map(stepper1.distanceToGo(),0,150,100,255));
    stepper1.run();


}
