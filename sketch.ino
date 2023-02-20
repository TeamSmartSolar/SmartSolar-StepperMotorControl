#include <AccelStepper.h>

// Define pinouts.
#define HOME_CMD_PIN 0
#define ENABLE_PIN 1
#define ROTATE_BKWD_CMD_PIN 9
#define ROTATE_FRWD_CMD_PIN 8
#define TILT_BKWD_CMD_PIN 7
#define TILT_FRWD_CMD_PIN 6
#define TILT_SPEED_PIN A1
#define ROTATE_SPEED_PIN A2

// Define control variables.
const int minSpeed = 0;
const int maxSpeed = 230;
int tiltSpeed;
int tiltPos;
int rotateSpeed;
int rotatePos;
bool homing;

// Instantiate stepper motor objects. Using 4 wire direct control.
AccelStepper tiltStepper(AccelStepper::FULL4WIRE, 2, 3, 4, 5);
AccelStepper rotateStepper(AccelStepper::FULL4WIRE, 10, 11, 12, 13);

void setup() {
  // Configure the input pins to use the Arduino's internal pullup resistors.
  pinMode(HOME_CMD_PIN, INPUT_PULLUP);
  pinMode(ENABLE_PIN, INPUT_PULLUP);
  pinMode(ROTATE_BKWD_CMD_PIN, INPUT_PULLUP);
  pinMode(ROTATE_FRWD_CMD_PIN, INPUT_PULLUP);
  pinMode(TILT_BKWD_CMD_PIN, INPUT_PULLUP);
  pinMode(TILT_FRWD_CMD_PIN, INPUT_PULLUP);

  // Set the max speed of each stepper to prevent overshoot.
  tiltStepper.setMaxSpeed(maxSpeed);
  rotateStepper.setMaxSpeed(maxSpeed);
}

void loop() {
  // Prioritize homing over the enable signals from the master microcontroller.
  if (digitalRead(HOME_CMD_PIN) == HIGH || homing == true) {
	// Set the homing flag high at the beginning of each iteration.
    homing = true;

	// Read the tilt stepper motor's position and move to position 0.
    tiltPos = tiltStepper.currentPosition();
    if(tiltPos < 0) {
	  // If the tilt stepper has a net negative position relative to home, move clockwise.
      tiltStepper.setSpeed(tiltSpeed);
    }
    else if(tiltPos > 0) {
	  // If the tilt stepper has a net positive position relative to home, move counter-clockwise.
      tiltStepper.setSpeed(-tiltSpeed);
    }
    else {
	  // If the tilt stepper is at the home position, stop moving.
      tiltStepper.setSpeed(0);
    }

	// Read the rotate stepper motor's position and move to position 0.
    rotatePos = rotateStepper.currentPosition();
    if(rotatePos < 0) {
	  // If the rotate stepper has a net negative position relative to home, move clockwise.
      rotateStepper.setSpeed(rotateSpeed);
    }
    else if(rotatePos > 0) {
	  // If the rotate stepper has a net positive position relative to home, move counter-clockwise.
      rotateStepper.setSpeed(-rotateSpeed);
    }
    else {
	  // If the rotate stepper is at the home position, stop moving.
      rotateStepper.setSpeed(0);
    }

	// If both motors have reached their home positions, turn off the homing flag.
    if(tiltPos == 0 && rotatePos == 0){
      homing = false;
    }
  }
  // If the system is not homing, only move if the enable signal is high.
  else if (digitalRead(ENABLE_PIN) == HIGH) {
    // Read the tilt speed potentiometer.
    tiltSpeed = map(analogRead(TILT_SPEED_PIN), 0, 1023, minSpeed, maxSpeed);
    if (digitalRead(TILT_FRWD_CMD_PIN) == HIGH) {
      // If the forwards command signal is high, move forwards.
      tiltStepper.setSpeed(tiltSpeed);
    }
    else if (digitalRead(TILT_BKWD_CMD_PIN) == HIGH) {
      // If there is a backwards command, move backwards.
      tiltStepper.setSpeed(-tiltSpeed);
    }
    else {
      // If neither are present, the stop signal is implied high.
      tiltStepper.setSpeed(0);
    }

    // Read the rotate speed potentiometer.
    rotateSpeed = map(analogRead(ROTATE_SPEED_PIN), 0, 1023, minSpeed, maxSpeed);
    if (digitalRead(ROTATE_FRWD_CMD_PIN) == HIGH) {
      // If the forwards command signal is high, move forwards.
      rotateStepper.setSpeed(rotateSpeed);
    }
    else if (digitalRead(ROTATE_BKWD_CMD_PIN) == HIGH) {
      // If there is a backwards command, move backwards.
      rotateStepper.setSpeed(-rotateSpeed);
    }
    else {
      // If neither are present (voltage = 0V), the stop signal is implied high.
      rotateStepper.setSpeed(0);
    }
  }
  else {
    // If the enable signal is low, stop both motors.
    tiltStepper.setSpeed(0);
    tiltStepper.stop();

    rotateStepper.setSpeed(0);
    rotateStepper.stop();
  }

  // Update both motors on every iteration of loop().
  tiltStepper.runSpeed();
  rotateStepper.runSpeed();
}
