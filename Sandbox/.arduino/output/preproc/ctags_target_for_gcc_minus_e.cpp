# 1 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino"
# 2 "/Users/aslakoverengiveland/Documents/IELS1001/arduinotest/project-course-h2023/Sandbox/ledstrip/ledstrip.ino" 2






Adafruit_NeoPixel pixels(32, 2, ((1 << 6) | (1 << 4) | (0 << 2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);



/*int rodMeter = A5
int blaaMeter = A4
int gronnMeter = A3*/

int redColor;
int blueColor;
int greenColor;

void setup() {




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

  for (int i = 0; i < 32; i++) {
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));

    pixels.show();

    delay(20);
  }
}
