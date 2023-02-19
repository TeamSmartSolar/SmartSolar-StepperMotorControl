# SmartSolar-StepperMotorControl
Stepper Motor Control for ECE Senior Design 

Built for Arduino Uno with two Stepper Motors as output. An enable signal is sent from the master microcontroller. Potentiometers control speed (RPM) of motors. Coded logic determines which directions they should turn. 

[Simulation on Wokwi](https://wokwi.com/projects/356667885699627009)

# Inputs to Arduino: 
      Enable Signal: Pin 1 - Digital signal 0V or 5V from Master Microcontroller 

      Rotate Backward Command: Pin 9 - Digital signal either 0V or 5V from Window Detector 1
      Rotate Forward Command: Pin 8 - Digital signal either 0V or 5V from Window Detector 1
      Tilt Backward Command: Pin 7 - Digital signal either 0V or 5V from Window Detector 2
      Tilt Forward Command: Pin 6 - Digital signal either 0V or 5V from Window Detector 2

      Rotate Speed Pin: A2 - Analog 0V to 5V controlled by Potentiometer 1
      Tilt Speed Pin: A1 - Analog 0V to 5V controlled by Potentiometer 2

# Outputs from Arduino:
      Rotate Output Command: Pin 4, 5, 6, 7
          Pin 2 is Stepper Motor's B- input
          Pin 3 is Stepper Motor's B+ input
          Pin 4 is Stepper Motor's A- input
          Pin 5 is Stepper Motor's A+ input

      Tilt Output Command: Pin 8, 9, 10, 11
          Pin 10 is Stepper Motor's B- input
          Pin 11 is Stepper Motor's B+ input
          Pin 12 is Stepper Motor's A- input
          Pin 13 is Stepper Motor's A+ input
    
# Basic logic: 
      The minimum speed is 0, while the maximum speed is 230 RPM (determined by motor spec). 
      
      The potentiometer values are scaled in the digital logic to allow the speed to be controlled by the arduino.
      
      The input logic ranges from -5V 0V and 5V, and each of those values determine whether the motor 
      should turn backwards or forwards or not at all. 
      
# Software Activity Diagram
![image](https://user-images.githubusercontent.com/125402985/219469035-9ea51fa5-d149-4272-99ea-b112979ef72c.png)


