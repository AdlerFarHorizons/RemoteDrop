// #include <AFMotor.h>
 
int sol1Pin = 2;
int sol2Pin = 3;
int sol3Pin = 4;
int sol4Pin = 5;
int sol5Pin = 6;

int in;
int cmd1, cmd2, cmd3;
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Drop Solenoid Driver");
  }
 
void loop() {
  while (Serial.available()) {
    in = Serial.read();
    Serial.print("received ");Serial.println(in);
    cmd1 = in & 0x0003;
    cmd2 = (in & 0x000C)/4;
    cmd3 = (in & 0x0030)/16;
    if ( cmd1 == 1 ) {
      digitalWrite( sol1Pin, HIGH);
      delay(1000);
      digitalWrite( sol1Pin, LOW);
  } else if ( cmd1 == 2 ) {
      digitalWrite( sol2Pin, HIGH);
      delay(1000);
      digitalWrite( sol2Pin, LOW);
  } else if ( cmd2 == 1 ) {
      digitalWrite( sol3Pin, HIGH);
      delay(1000);
      digitalWrite( sol3Pin, LOW);
  } else if ( cmd2 == 2 ) {
      digitalWrite( sol4Pin, HIGH);
      delay(1000);
      digitalWrite( sol4Pin, LOW);
  } else if ( cmd3 == 1) {
      digitalWrite( solPin5, HIGH);
      delay(1000);
      digitalWrite( sol5Pin, LOW);
  }

   delay( 200 );
}

// Activates solenoid.
//void solActivate{
//  digitalWrite(ledPin, HIGH);
//  digitalWrite(sol1Pin, HIGH);
//  delay(1000);
//  digitalWrite(sol1Pin, LOW);
//  digitalWrite(ledPin, LOW);  
}
