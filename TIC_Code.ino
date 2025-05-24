/*  TETRIX TeleOp Module example code for a genuine SONY PS4 gaming controller.
 *  Date: 09/25/2018
 *  Author: PWU
 * 
 *  IMPORTANT !! - To begin using a PS4 controller with the TeleOp module, you must first pair it to the Bluetooth Dongle. To do this, be sure the TeleOp module's
 *  Bluetooth dongle is inserted into the USB host port and the PS4 controller's battery is fully charged. Next, power up the module. After 3 - 4 seconds, the green LED should be blinking rapidly. 
 *  Most Bluetooth dongles will also have a blinking indicator as well. To proceed with pairing the controller to the dongle, press and hold down the SHARE and POWER button on the PS4 controller until
 *  the LED light on the controller begins to blink rapidly. This indicates that the PS4 is now in Discovery Mode. Release the buttons. Once in discovery mode, press the MODE button on the TeleOp module. 
 *  The RED LED will come on indicating that the TeleOp module is attempting to pair with the PS4 that is in discovery mode. When they have successfully paired, the TeleOp module's RED LED will turn off
 *  and the GREEN LED will turn on solid (no blink). In addition, the PS4's LED color will change to solid GREEN. Note, you only need to pair the devices once. After they are paired, you simply 
 *  power up the TeleOp module, then turn on your paired PS4 controller. The PS4 will do a slow LED blink while it is linking, then switch to solid GREEN color once they're linked. This could take
 *  up to 10 seconds to link.
 * 
 *  The TETRIX TeleOP module Arduino Library enables support for interfacing the PS4 gaming controller using the following commands:
 *    
 *  ps4.getPS4();         reads PS4 connections status and data from all digital and analog buttons and joysticks. This function should be called as frequently as possible in the main Arduino Sketch Loop to ensure data from PS4 controller is the latest.
 *  
 *  ps4.Connected;        returns PS4 connection status                           (0 = disconnected; 1 = connected)  
 *  ps4.inRange;          returns PS4 in/out of range status                      (0 = controller is out of range; 1 = controller is in range)
 *  ps4.resetTeleOp();    forces a reset of the TeleOp module
 *  
 *  ps4.Button(L1);       returns digital boolean value of L1 button              (0 = unpressed, 1 = pressed)
 *  ps4.Button(L2);       returns digital boolean value of L2 button              (0 = unpressed, 1 = pressed)
 *  ps4.Button(L3);       returns digital boolean value of L3 button              (0 = unpressed, 1 = pressed)
 *  ps4.Button(R1);       returns digital boolean value of R1 button              (0 = unpressed, 1 = pressed)
 *  ps4.Button(R2);       returns digital boolean value of R2 button              (0 = unpressed, 1 = pressed)
 *  ps4.Button(R3);       returns digital boolean value of R3 button              (0 = unpressed, 1 = pressed)  
 *  ps4.Button(L2T);      returns analog value of L2 Trigger button               (Range: 0 - 255)
 *  ps4.Button(R2T);      returns analog value of R2 Trigger button               (Range: 0 - 255)
 *  ps4.Button(UP);       returns digital boolean value of the DPad UP button     (0 = unpressed, 1 = pressed)
 *  ps4.Button(DOWN);     returns digital boolean value of the DPad DOWN button   (0 = unpressed, 1 = pressed)
 *  ps4.Button(RIGHT);    returns digital boolean value of the DPad RIGHT button  (0 = unpressed, 1 = pressed)
 *  ps4.Button(LEFT);     returns digital boolean value of the DPad LEFT button   (0 = unpressed, 1 = pressed)
 *  ps4.Button(TRIANGLE); returns digital boolean value of TRIANGLE button        (0 = unpressed, 1 = pressed)
 *  ps4.Button(CROSS);    returns digital boolean value of CROSS button           (0 = unpressed, 1 = pressed)
 *  ps4.Button(CIRCLE);   returns digital boolean value of CIRCLE button          (0 = unpressed, 1 = pressed)
 *  ps4.Button(SQUARE);   returns digital boolean value of SQUARE button          (0 = unpressed, 1 = pressed)
 *  ps4.Button(SHARE);    returns digital boolean value of SHARE button           (0 = unpressed, 1 = pressed)
 *  ps4.Button(OPTIONS);  returns digital boolean value of OPTIONS button         (0 = unpressed, 1 = pressed)
 *  ps4.Button(POWER);    returns digital boolean value of POWER button           (0 = unpressed, 1 = pressed)
 *  ps4.Button(TOUCH);    returns digital boolean value of TOUCH pad button       (0 = unpressed, 1 = pressed)
 *  
 *  ps4.buttons_1;        returns a byte value representing the digital boolean states of button group 1  (see TeleOp technical documentation for more information)
 *  ps4.buttons_2;        returns a byte value representing the digital boolean states of button group 2  (see TeleOp technical documentation for more information)
 *  
 *  ps4.Stick(LX);        returns the analog value of the Left X-axis Joystick    (Range: 0 - 255; 128 = center stick position)
 *  ps4.Stick(LY);        returns the analog value of the Left Y-axis Joystick    (Range: 0 - 255; 128 = center stick position)
 *  ps4.Stick(RX);        returns the analog value of the Right X-axis Joystick   (Range: 0 - 255; 128 = center stick position)
 *  ps4.Stick(RY);        returns the analog value of the Right Y-axis Joystick   (Range: 0 - 255; 128 = center stick position)
 *  
 *  ps4.Touchpad(TOUCHX); returns the X coordinate value of finger position on touch pad  (Range: 0 - 1920)
 *  ps4.Touchpad(TOUCHY); returns the Y coordinate value of finger position on touch pad  (Range: 0 - 941)
 *  
 *  ps4.Angle(PITCH);     returns the Pitch Angle of the PS4 controller           (Range: 0 - 360)
 *  ps4.Angle(ROLL);      returns the Roll Angle of the PS4 controller            (Range: 0 - 360)
 *  
 *  ps4.Motor(LX);        returns the position of the Left X-axis Joystick mapped to a PRIZM motor power range          (Range: -100 to 100) 
 *  ps4.Motor(LY);        returns the position of the Left Y-axis Joystick mapped to a PRIZM motor power range          (Range: -100 to 100)
 *  ps4.Motor(RX);        returns the position of the Right X-axis Joystick mapped to a PRIZM motor power range         (Range: -100 to 100)
 *  ps4.Motor(RY);        returns the position of the Right Y-axis Joystick mapped to a PRIZM motor power range         (Range: -100 to 100)
 *  
 *  ps4.Motor(L2T);       returns the analog position of the L2 Trigger button mapped to a PRIZM motor power range      (Range: 0 to 100)
 *  ps4.Motor(R2T);       returns the analog position of the R2 Trigger button mapped to a PRIZM motor power range      (Range: 0 to 100)
 *  
 *  ps4.Motor(PITCH);     returns the angular pitch of the PS4 gyro mapped to a PRIZM motor power range                 (Range: -100 to 100)
 *  ps4.Motor(ROLL);      returns the angular roll of the PS4 gyro mapped to a PRIZM motor power range                  (Range: -100 to 100)
 *  
 *  ps4.Servo(LX);        returns the position of the Left X-axis Joystick mapped to a PRIZM servo position range       (Range: 0 to 180) 
 *  ps4.Servo(LY);        returns the position of the Left Y-axis Joystick mapped to a PRIZM servo position range       (Range: 0 to 180)
 *  ps4.Servo(RX);        returns the position of the Right X-axis Joystick mapped to a PRIZM servo position range      (Range: 0 to 180)
 *  ps4.Servo(RY);        returns the position of the Right Y-axis Joystick mapped to a PRIZM servo position range      (Range: 0 to 180)
 *  
 *  ps4.Servo(L2T);       returns the analog position of the L2 Trigger button mapped to a PRIZM servo position range   (Range: 0 to 180)
 *  ps4.Servo(R2T);       returns the analog position of the R2 Trigger button mapped to a PRIZM servo position range   (Range: 0 to 180)
 *  
 *  ps4.Servo(PITCH);     returns the angular pitch of the PS4 gyro mapped to a PRIZM servo position range              (Range: 0 to 180)
 *  ps4.Servo(ROLL);      returns the angular roll of the PS4 gyro mapped to a PRIZM servo position range               (Range: 0 to 180)
 *   
 *  ps4.setRumble(STOP);  set the PS4 internal rumble motor to STOP (off) 
 *  ps4.setRumble(SLOW);  set the PS4 internal rumble motor to SLOW vibrate speed
 *  ps4.setRumble(FAST);  set the PS4 internal rumble motor to FAST vibrate speed
 *  
 *  ps4.setLED(RED);      set the PS4 LED color to RED
 *  ps4.setLED(BLUE);     set the PS4 LED color to BLUE
 *  ps4.setLED(YELLOW);   set the PS4 LED color to YELLOW
 *  ps4.setLED(GREEN);    set the PS4 LED color to GREEN
 *  
 *  ps4.setDeadZone(stick, amount);   set the amount of Joystick axis dead zone  (stick = LEFT or RIGHT; amount = 0 to 100)
 *  
 */



// Below is an example for how to use the TeleOp and PRIZM libraries to control your vehicle
// Feel free to use this code as a starting point to build on and make changes to better suit your design
// Remember to ask the Ideas Clinic Co-Ops if you run into any problems using the Tetrix Kits!

#include <PRIZM.h>   // TETRIX PRIZM Library
#include <TELEOP.h>  // TETRIX TeleOp module Library

PRIZM prizm;  // Create an instance within the PRIZM Library class named prizm
PS4 ps4;      // Create an instance within the PS4 Library class named ps4

// Remember to press the green button to start running the code on your vehicle
void setup() {

  Serial.begin(115200);  // Serial Monitor baud rate
  prizm.PrizmBegin();    // Intializes the PRIZM controller and waits here for press of green start button
  prizm.setServoSpeed(2,25);   // Set the speeds the servos will move at
  prizm.setServoSpeed(1,25);
  ps4.setDeadZone(LEFT, 10);   // set the Left Joystick dead zone range to +/- 10
  ps4.setDeadZone(RIGHT, 10);  // set the Right Joystick dead zone range to +/- 10
  /* ======================== What is Dead Zone ? =============================
 Sometimes when you let go of the left and right joysticks on a gaming contoller, they don't always come back to "exact" center. Dead zone is a range
 you can set about the center of the joystick XY axis that is considered to be neutral. As long as the joystick is within the dead zone range, it
 is considered to be at center. This parameter is used by the ps4.Motor() and ps4.Servo() functions, so that when the joystick is within the dead zone, the
 value returned by this function is always a zero (motor stop) for DC motors and 90 (center position) for servos.
*/
  Serial.println("initialized");  

  // Wait for ps4 controller to be connected
  ps4.getPS4();  // Get (read) all PS4 button and joystick data values
  
  // Wait for ps4 controller to be connected
  while(!ps4.Connected){
    ps4.getPS4();  // Get (read) all PS4 button and joystick data values
    Serial.println("Failed to connect to controller!");
    delay(500); 
  }

  Serial.println("Connected!");

}

void loop() {

  ps4.getPS4();  // Get (read) all PS4 button and joystick data values
  
  // If the blue cross button is pressed, move the servo to it's maximum rotation
  if(ps4.Button(CROSS)){
    prizm.setServoPosition(1,180);    // Move servo 1 to 180 degrees
  
  // If the red circle is pressed, then move the servo back to it's start position
  }else if(ps4.Button(CIRCLE)){
    prizm.setServoPosition(1,0);      // Move servo 1 to 0 degrees
  }


  // If the left trigger is pressed, rotate motor 1 forward
  if(ps4.Button(L2)){
    prizm.setMotorSpeed(1, 100);      // Move motor 1 forward at 100 degrees per second (max is 720)
  
  // If the left bumper is pressed, rotate motor 1 backward
  }else if(ps4.Button(L1)){
    prizm.setMotorSpeed(1, -100);      // Move motor 1 backward at 100 degrees per second (minimum is -720)
  
  // If neither the left trigger or bumper is pressed, do not move motor 1
  }else{
    prizm.setMotorSpeed(1, 0);         // Stop motor 1 rotation
  }
  
  // Control motor number 2 using the left joystick, press up to go forward and down to go back
  prizm.setMotorPower(2, ps4.Motor(LY));
}