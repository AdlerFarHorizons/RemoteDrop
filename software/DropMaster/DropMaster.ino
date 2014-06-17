
int sol1Pin = 2;
int sol2Pin = 3;
int sol3Pin = 4;
int sol4Pin = 5;
int sol5Pin = 6;
int dropPin = 7;
int armPin = 8;
int cmd;

void setup() {
  Serial.begin( 9600 );
  pinMode( sol1Pin, INPUT_PULLUP );
  pinMode( sol2Pin, INPUT_PULLUP );
  pinMode( sol3Pin, INPUT_PULLUP );
  pinMode( sol4Pin, INPUT_PULLUP );
  pinMode( sol5Pin, INPUT_PULLUP );
  pinMode( dropPin, INPUT_PULLUP );
  pinMode( armPin, INPUT_PULLUP );
}

void loop() {
  cmd = 0;
  cmd += (int)(!digitalRead( sol1Pin ));
  cmd += (int)(!digitalRead( sol2Pin )) * 2;
  cmd += (int)(!digitalRead( sol3Pin )) * 4;
  cmd += (int)(!digitalRead( sol4Pin )) * 8;
  cmd += (int)(!digitalRead( sol5Pin )) * 16;
  cmd += (int)(!digitalRead( dropPin )) * 32;
  cmd += (int)(!digitalRead( armPin )) * 64;
  Serial.println( (byte)cmd, HEX );
  delay(200);
}

