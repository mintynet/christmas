#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NEOPIN  2
#define LEDPIN1 1
#define LEDPIN2 0

boolean led1 = false;
boolean led2 = false;
int brightness = 0;
int fadeAmount = 5;
int counterMax = 2500;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, NEOPIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  strip.begin();
  strip.setBrightness(31);
  strip.show(); // Initialize all pixels to 'off'
  analogWrite(LEDPIN1,127);
  analogWrite(LEDPIN2,127);
//  digitalWrite(LEDPIN2,led2);
//  led2 = !led2;
//  digitalWrite(LEDPIN2,led2);
}

void loop() {
  rainbow(5);
  //front(5);
  rainbowCycle(5);
  //front(5);
  rear(5);
}

void rear(uint8_t wait) {
  strip.setPixelColor(0, 0xFFA500);
  strip.show();
  for (int counter=1;counter<counterMax;counter++) {
    analogWrite(LEDPIN1, brightness); 
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    delay(wait);   
  }
  analogWrite(LEDPIN1,127);   
  analogWrite(LEDPIN2,127);   
}

void front(uint8_t wait) {
  uint16_t i;
  for (i=0; i<5000;i++) {
    strip.setPixelColor(0, 0xFFA500);
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    strip.show();
    delay(wait);
  }
  for (i=0;i<1000;i++) {
    strip.setPixelColor(0,0);
    led2 = !led2;
    digitalWrite(LEDPIN2,led2);
    strip.show();
    delay(5);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*10; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j/10) & 255));
    }
    led1 = !led1;
    digitalWrite(LEDPIN1,led1);
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5*10; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j/10) & 255));
    }
    led1 = !led1;
    digitalWrite(LEDPIN1,led1);
    strip.show();
    delay(wait);
  }
  analogWrite(LEDPIN2,127);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
