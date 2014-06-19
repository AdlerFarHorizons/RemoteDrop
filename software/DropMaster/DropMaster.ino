
// Pin Numbers
int sol1Pin = 2; // saved for switch
int sol2Pin = 3; // saved for switch
int sol3Pin = 4; // saved for switch
int sol4Pin = 5; // choose drop type
int sol5Pin = 6; // choose drop type
int dropPin = 7; // drop button
int armPin = 8; // arm button
int dropLED = 9; // drop button LED

// Variables for reading pin vals
int sol1;
int sol2;
int sol3;
int sol4;
int sol5;
int drop;
int arm;
int code;
char c[6];
String str;

// Boolean to keep LED from turning back on
boolean done = false;

void setup() {
  Serial.begin( 9600 );
  pinMode( sol1Pin, INPUT_PULLUP );
  pinMode( sol2Pin, INPUT_PULLUP );
  pinMode( sol3Pin, INPUT_PULLUP );
  pinMode( sol4Pin, INPUT_PULLUP );
  pinMode( sol5Pin, INPUT_PULLUP );
  pinMode( dropPin, INPUT_PULLUP );
  pinMode( armPin, INPUT_PULLUP );
  pinMode( dropLED, OUTPUT );
}

void loop() {
  
  // Read integer values (0/1) from switch pins
  sol1 = (int)(!digitalRead( sol1Pin ));
  sol2 = (int)(!digitalRead( sol2Pin ));
  sol3 = (int)(!digitalRead( sol3Pin ));
  sol4 = (int)(!digitalRead( sol4Pin ));
  sol5 = (int)(!digitalRead( sol5Pin ));
  drop = (int)(!digitalRead( dropPin ));
  arm = (int)(!digitalRead( armPin ));
  
  // If armed and drop has not just occurred
  if (arm && !done)
  {
    // If drop button pressed, turn off LED
    if (drop) {
      done = true;
      digitalWrite(dropLED,LOW);
      
      // Send integer code to serial (wifi)
      code = sol5*10000 + sol4*1000 + sol3*100 + sol2*10 + sol1;
      Serial.println(code);
      str = String(code);
      Serial.println(str);
      str.toCharArray(c,6);
      Serial.print((int)c[1]);
      Serial.print((int)c[2]);
      Serial.print("Code to send: ");
      Serial.println(c);
    }
    
    // While drop button left unpressed, keep LED on
    else if (!drop && !done) {
      digitalWrite(dropLED,HIGH);
    }
  }
  
  // If disarmed, reset boolean done to false and turn off light
  if (!arm) {
    digitalWrite(dropLED,LOW);
    done = false;
  }
  
}
