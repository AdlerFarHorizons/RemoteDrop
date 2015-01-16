  
  // Libraries
  #include <SoftwareSerial.h>
  #include <string.h>
  
  // mySerial pins
  SoftwareSerial mySerial(12,13); // RX, TX
  
  void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
  }
  
  void loop() {
    String content = "";
    char character;
    while(mySerial.available()) {
        character = mySerial.read();
        content.concat(character);
    }
  
    if (content != "") {
      // Print code, set out to 0
      Serial.println(content);
      int out = 0;
      
      // Turn on LEDs corresponding to code
      if(content.indexOf('1')!=-1)
        digitalWrite(2,HIGH);
      if(content.indexOf('2')!=-1)
        digitalWrite(3,HIGH);
      if(content.indexOf('3')!=-1)
        digitalWrite(4,HIGH);
      if(content.indexOf('4')!=-1)
        digitalWrite(5,HIGH);
      if(content.indexOf('5')!=-1)
        digitalWrite(6,HIGH);
      if(content.indexOf('6')!=-1)
        digitalWrite(7,HIGH);
      if(content.indexOf('7')!=-1)
        digitalWrite(8,HIGH);
      
      // Wait for 2 seconds
      delay(2000);
            
      // Turn off LEDs
      if(content.indexOf('1')!=-1)
        digitalWrite(2,LOW);
      if(content.indexOf('2')!=-1)
        digitalWrite(3,LOW);
      if(content.indexOf('3')!=-1)
        digitalWrite(4,LOW);
      if(content.indexOf('4')!=-1)
        digitalWrite(5,LOW);
      if(content.indexOf('5')!=-1)
        digitalWrite(6,LOW);
      if(content.indexOf('6')!=-1)
        digitalWrite(7,LOW);
      if(content.indexOf('7')!=-1)
        digitalWrite(8,LOW);
    }
  }
