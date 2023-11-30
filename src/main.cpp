#include <Arduino.h>
#include <Bounce2.h>

//lib_deps = 
// 	miguelbalboa/MFRC522@^1.4.10
// 	z3t0/IRremote@^4.2.0
// 	chris--a/Keypad@^3.1.1

// put function declarations here:

Bounce debouncer1 = Bounce();
Bounce debouncer2 = Bounce();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  debouncer1.attach(2, INPUT_PULLUP);
  debouncer2.attach(3, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //Write code that detects that when one button is pressed, the onboard led toggles on, and when the other is pressed, it toggles off.
  debouncer1.update();
  debouncer2.update();

  if (debouncer1.changed()) {
    if(debouncer1.read() == LOW) {
      //Serial.println("Button 1 pressed");
      //Write code that makes the LED blink an SOS signal once.
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(20);
        digitalWrite(LED_BUILTIN, LOW);
        delay(20);
      }
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(60);
        digitalWrite(LED_BUILTIN, LOW);
        delay(60);
      }
      for (int i = 0; i < 3; i++)
      {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(20);
        digitalWrite(LED_BUILTIN, LOW);
        delay(20);
      }
      
    }
  }
  if (debouncer2.changed()) {
    if(debouncer2.read() == LOW) {
      //Serial.println("Button 2 pressed");
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    }
  }

  
}


