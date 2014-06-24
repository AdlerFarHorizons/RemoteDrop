#include <SoftwareSerial.h>
#include <string.h>
SoftwareSerial mySerial(12,13); // RX, TX

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  for(int setPin=2; setPin<=11; setPin++){
    pinMode(setPin,OUTPUT);
  }
}
void loop(){
  String content = "";
  char character;
  while(mySerial.available()) {
      character = mySerial.read();
      content.concat(character);
  }

  if (content != "") {
    Serial.println(content);
      
      int out=0;
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
        if(content.indexOf('8')!=-1)
          digitalWrite(9,HIGH);
       //More outputs than this means we can't encode using numbers, Need to switch to letters      
    delay(1000);
          
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
        if(content.indexOf('8')!=-1)
          digitalWrite(9,LOW);
  }
}
