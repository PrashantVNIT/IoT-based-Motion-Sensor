#include <ESP8266WiFi.h>		//Including the wifi library
#include <ESP8266HTTPClient.h>	//Including HTTP library

//Defining Pins 
int BUZZER_PIN = 13;
int LED_PIN = 5;
int PIR_PIN = 15;

//Wifi Credentials
char* ssid = "****"; //Your WiFi ssid
char* pwd = "****";  //Your WiFi password
HTTPClient http;	//Defining object of class HTTPClient

boolean sendNotification = false;	//variable to store status of notification has send or not

//Enter your IFTTT Webhooks key here
char* key = "";

//timer setup
boolean startTimer = false;
int runDetector = true;
int now = millis();
int prevTime = 0;

void setup() {  			// setup function
  Serial.begin(9600);			//set the baud rate
  Serial.println("Starting...");		

  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  

  WiFi.mode(WIFI_OFF);	
  delay(1000);
  WiFi.mode(WIFI_STA); 		
  
  pinMode(LED_PIN,OUTPUT);
  pinMode(PIR_PIN,INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);
  
  //Low level trigger buzzer
  digitalWrite(BUZZER_PIN,HIGH);

  now = millis();
  prevTime = millis();
  
  //connecting wifi
  WiFi.begin(ssid,pwd);		
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");    
    delay(500);
  }  
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());

  now = millis();
  int time_passed = (int)((now - prevTime)/1000);
  int i = 0;
  for(i = 0; i < 30 - time_passed; i++){
    blk(500);  
  }
  
//Interrupt to run motionDetected function 
  attachInterrupt(digitalPinToInterrupt(PIR_PIN),motionDetected,RISING);  
}

void loop() {				//loop function
  now = millis();

  if(startTimer && (now - prevTime) >= 30000){
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN,HIGH);
    runDetector = true;
  }

  if(sendNotification){
    
    sendNotification = false;      
    http.begin("http://maker.ifttt.com/trigger/motion_detected/with/key/" + key);
    delay(1000);  
    http.GET();  //Send the request
    http.end();  //Close connection
    Serial.println("NOTIFICATION SENT");  	
//messege for confirmation on serialprint.
  }

}


ICACHE_RAM_ATTR void motionDetected(){		//storing function in RAM
  if(runDetector){  
    startTimer = true;  
    prevTime = millis();
  
    digitalWrite(LED_PIN,HIGH);
    Serial.println("Motion Detected");

    digitalWrite(BUZZER_PIN,LOW);		//Buzzer will sound
    sendNotification = true;
    runDetector = false;
  }
}


void blk(int x){		//function for blink led
  
  digitalWrite(LED_PIN,HIGH);
  delay(x);  
  digitalWrite(LED_PIN,LOW);
  delay(x);
}
