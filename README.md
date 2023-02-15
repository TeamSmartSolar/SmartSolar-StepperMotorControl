# SmartSolar-StepperMotorControl
Stepper Motor Control for ECE Senior Design 

Built for Arduino Uno with two Stepper Motors as output.

[Simulation on Wokwi](https://wokwi.com/projects/356667885699627009)

# Inputs to Arduino: 
      Enable Signal: Pin 1 - Digital signal 0V or 5V from Master Microcontroller 

      Rotate Backward Command: Pin 2 - Digital signal either 0V or 5V from Window Detector 1
      Rotate Forward Command: Pin 3 - Digital signal either 0V or 5V from Window Detector 1
      Tilt Backward Command: Pin 12 - Digital signal either 0V or 5V from Window Detector 2
      Tilt Forward Command: Pin 13 - Digital signal either 0V or 5V from Window Detector 2

      Rotate Speed Pin: A2 - Analog 0V to 5V controlled by Potentiometer 1
      Tilt Speed Pin: A1 - Analog 0V to 5V controlled by Potentiometer 2

# Outputs from Arduino:
      Rotate Output Command: Pin 4, 5, 6, 7
          Pin 4 is Stepper Motor's B- input
          Pin 5 is Stepper Motor's B+ input
          Pin 6 is Stepper Motor's A- input
          Pin 7 is Stepper Motor's A+ input

      Tilt Output Command: Pin 8, 9, 10, 11
          Pin 8 is Stepper Motor's B- input
          Pin 9 is Stepper Motor's B+ input
          Pin 10 is Stepper Motor's A- input
          Pin 11 is Stepper Motor's A+ input
    


