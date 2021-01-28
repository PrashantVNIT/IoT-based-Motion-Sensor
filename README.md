# IoT-based-Motion-Sensor
This project is based on IoT(Internet of Things).In this an intruder alarm is made using ESP8266 microcontroller, PIR Motion sensor and Buzzer (as important components) etc .

## Table of contents
1.	Project at a glance…
2.	Principle
3.	Hardware required
4.	Working theory
5.	Circuit and its connections
  - a.	Connections of PIR sensor
  - b.	Connections of LED
  - c.	Connections of Buzzer
6.	IFTTT Applet creation

### 1.	Project at a glance…

This project is based on IoT(Internet of Things).We have made an intruder alarm using ESP8266 microcontroller, PIR Motion sensor and Buzzer (as important components) etc.

![](images/1.jpg)
When anybody (human, animal or body emitting infrared radiations) emitting heat waves comes close to our project (installation site). PIR motion sensor will instantly detect the presence of it and rings a buzzer alarm to notify us about an intrusion. The microcontroller sends a notification on the phone through IFTTT Webhooks (which helps us connect all of our different apps and devices) and also sounds the buzzer when motion is detected.


### 2. Principle 

Our project is based on the principle that :- Every body emits heat waves and heat waves contain infrared radiations. The more the body emitting heat the more the infrared radiations. Generally the living bodies emit more heat than the raw materials. So the PIR sensor can be used to detect the motion of living bodies.
Everything works through the internet so there is no limitation of the distance between the sensor and the phone.


### 3.	Hardware Required

#### a.	NodeMCU ESP8266

![](images/2.png)

This has been selected as the controller for this system due to its compact size, compatibility, stress-free interfacing over several other type of controller. ESP8266 is an open source Wi-Fi enabled module. It is integrated with TCP/IP protocol stack that can give any microcontroller access to your Wi-Fi network. The ESP8266 is capable of either hosting an application or offloading all Wi-Fi networking functions from another application processor.

#### b.	PIR sensor

![](images/3.png)   ![](images/4.png)

![](images/25.png)   ![](images/26.png)

A passive infrared sensor (PIR sensor) is an electronic sensor which measures infrared radiation in its field of view from objects. PIR sensors sense general movement, but don’t have information on who moved or what. These sensors allow you to sense motion, generally used to detect whether a human has moved in or out of the sensor range. They are small, inexpensive, low-power, easy to use and don’t wear out.

| Pin or Control      | Function |
| ----------- | ----------- |
| Time Delay Adjust      | Sets how long the output remains high after detecting motion.... Anywhere from 3 seconds to 5 minutes.|
| Sensitivity Adjust   | Sets the detection range.... from 3 meters to 7 meters   |
|Trigger Selection Jumper|Set for single or repeatable triggers.|
|Ground pin|Ground input|
|Output Pin|Low when no motion is detected.. High when motion is detected. High is 3.3V|
|Power Pin|5 to 20 VDC Supply input|

#### c.	LED

![](images/5.jpg)    ![](images/6.jpg)

A light emitting diode (LED) is a semiconductor device that emits visible light when an electric current passes through it.

#### d. Buzzer(One we have used in this project is LOW LEVEL TRIGGER i.e. will be triggered when the input is LOW)

![](images/7.png)

Here we have used active buzzer to make sound after motion detected. The active buzzer has an internal oscillating source, the buzzer will sound as soon as it is energized.
 

| Pin or Control      | Function |
| ----------- | ----------- |
|Ground pin|Ground input|
|Input Pin|When Input is LOW, the buzzer is turned On. When input it is HIGH the buzzer does not sound*|
|Power Pin|3.3 to 5 VDC Supply input|

#### e.	 Breadboard

![](images/8.jpg)

A breadboard is a platform you can use to build and test electronic circuits, usually without having to do any soldering. Certain parts of the breadboard are wired together so that electricity can flow from component to component in orderly rows. Breadboards are useful for quickly testing and prototyping electronics ideas.
Also Breadboard can also be used without soldering, which makes it easy to remove components and reuse them after doing experiment.

#### f.	Jumper Wires

![](images/9.jpg)

Jumper wires are simply wires that have connector pins at each end, allowing them to be used to connect to each other without soldering. Jumper wires are typically used with breadboards and other prototyping tools in order to make it easy to change a circuit as needed.

### 4. Working Theory

![](images/10.png)

* We have connected the PIR motion sensor to to the digital pin D8 (GPIO 15) of NodeMCU.
* Whenever the PIR detects motion then the output state of the PIR sensor will change which will be detected by the controller.
* We have programmed the NodeMCU to make an HTTP GET request to our IFTTT Webhooks app.
* Whenever the HTTP GET request has been made then it will trigger a notification alert on our mobile phone or the device connected.

### 5.	Circuit and its connections

![](images/11.jpg)

#### a.	Connections of PIR sensor
*	Connect GND of PIR sensor to the GND of NodeMCU.
*	Connect the VCC of PIR sensor to the 3.3 Volts of NodeMCU.
*	Connect the OUT of PIR sensor to the digital pin D8 (GPIO 15) of NodeMCU.

#### b.	Connections of LED
*	Connect GND of LED to 10K resistor.
*	Connect other end of resistor to GND of NodeMCU.
*	Connect positive of LED to (GPIO5).

#### c.	Connections of BUZZER
*	Connect GND of Buzzer to GND of NodeMCU.
*	Connect positive of Buzzer to 3.3 Volts of NodeMCU.
*	Connect input of Buzzer to pin D7 (GPIO13) of NodeMCU.

### 6.  IFTTT Applet Creation
 * Download the Android app from Play Store
 * Create an Account (If you don't have a account)
 
 1. Click on your profile icon and select the create option.
 
 2. Now click on + This
 
 3. Search for "Webhooks" and select it.
 
 4. Choose trigger option, "Receive a Web Request" .
 
 5. Give a name to your event. In our case we have used "motion_detected"
 
 6. Now click on +That
 
 7. Now from “choose action service”,
   
 8. Search for notification in the search box and click on the notification icon.
    • Note that you must be installed and logged in the IFTTT app on your           phone for the notifications to work.
    
 9. Choose Simple Notification
 
 10. Type the custom message you want to receive the notification.
 
 11. Click Finish.
