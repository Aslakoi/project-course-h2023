#include <Arduino.h>
#line 1 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino"
#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 32 



Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 20

/*int rodMeter = A5
int blaaMeter = A4
int gronnMeter = A3*/

int redColor;
int blueColor;
int greenColor;

#line 20 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino"
void setup();
#line 31 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino"
void loop();
#line 20 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino"
void setup() {
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  /*pinMode(rodMeter, INPUT)
  pinMode(blaaMeter, INPUT)
  pinMode(gronnMeter, INPUT)*/
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  double redColor = analogRead(A5)/4.02;
  double blueColor = analogRead(A4)/4.02;
  double greenColor = analogRead(A3)/4.02;

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    pixels.show();

    delay(DELAYVAL);
  }
}

  

