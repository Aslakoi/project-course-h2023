#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 32 



Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


/*int rodMeter = A5
int blaaMeter = A4
int gronnMeter = A3*/

int DELAYVAL;

int redColor;
int blueColor;
int greenColor;

void setup() {
  
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
  pixels.setBrightness(255);
  /*pinMode(rodMeter, INPUT)
  pinMode(blaaMeter, INPUT)
  pinMode(gronnMeter, INPUT)*/
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  regnbue();

  }


void regnbue() {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    // strip.rainbow() can take a single argument (first pixel hue) or
    // optionally a few extras: number of rainbow repetitions (default 1),
    // saturation and value (brightness) (both 0-255, similar to the
    // ColorHSV() function, default 255), and a true/false flag for whether
    // to apply gamma correction to provide 'truer' colors (default true).
    pixels.rainbow(firstPixelHue);
    // Above line is equivalent to:
    // strip.rainbow(firstPixelHue, 1, 255, 255, true);
    pixels.show(); // Update strip with new contents
    DELAYVAL = analogRead(A5)/10;
    delay(DELAYVAL);  // Pause for a moment
  }
}


