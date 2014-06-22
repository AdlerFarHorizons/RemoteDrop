  // Libraries
  #include <SoftwareSerial.h>
  
  // Pin Numbers
  int sol1Pin = 2; // choose drop type
  int sol2Pin = 3; // choose drop type
  int sol3Pin = 4; // choose drop type
  int sol4Pin = 5; // choose drop type
  int sol5Pin = 6; // choose drop type
  int sol6Pin = 7; // choose drop type
  int sol7Pin = 7; // choose drop type
  int dropPin = 9; // drop button
  int armPin = 10; // arm button
  int dropLED = 11; // drop button LED
  
  // Variables for reading pin vals
  int sol1;
  int sol2;
  int sol3;
  int sol4;
  int sol5;
  int sol6;
  int sol7;
  int drop;
  int arm;
  
  // Code Variables
  long code;
  char c[8];
  String str;
  
  // Boolean to keep LED from turning back on
  boolean done = false;

  // Use pins 12 and 13 for Wireless X-Bee
  SoftwareSerial mySerial(12,13); // RX, TX
  
  void setup()
  {
    mySerial.begin( 9600 );
    Serial.begin( 9600 );
    pinMode( sol1Pin, INPUT_PULLUP );
    pinMode( sol2Pin, INPUT_PULLUP );
    pinMode( sol3Pin, INPUT_PULLUP );
    pinMode( sol4Pin, INPUT_PULLUP );
    pinMode( sol5Pin, INPUT_PULLUP );
    pinMode( sol6Pin, INPUT_PULLUP );
    pinMode( sol7Pin, INPUT_PULLUP );
    pinMode( dropPin, INPUT_PULLUP );
    pinMode( armPin, INPUT_PULLUP );
    pinMode( dropLED, OUTPUT );
  }
  
  void loop()
  {
    // Read integer values (0/1) from switch pins
    sol1 = (int)(!digitalRead( sol1Pin ));
    sol2 = (int)(!digitalRead( sol2Pin ));
    sol3 = (int)(!digitalRead( sol3Pin ));
    sol4 = (int)(!digitalRead( sol4Pin ));
    sol5 = (int)(!digitalRead( sol5Pin ));
    sol6 = (int)(!digitalRead( sol6Pin ));
    sol7 = (int)(!digitalRead( sol7Pin ));
    drop = (int)(!digitalRead( dropPin ));
    arm = (int)(!digitalRead( armPin ));
    
    // If armed and drop has not just occurred
    if (arm && !done)
    {
      // If drop button pressed, turn off LED
      if (drop) {
        done = true;
        digitalWrite(dropLED,LOW);
        
        // Send integer code over wifi (mySerial)
        code = sol7*7000000 + sol6*600000 + sol5*50000 + sol4*4000 + sol3*300 + sol2*20 + sol1;
        str = String(code);
        str.toCharArray(c,8f);
        mySerial.println(c);
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
