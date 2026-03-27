#include <Adafruit_NeoPixel.h>

#define LED_PIN 2   // led pin
#define MQ9_PIN A0   //sensor pin
#define BUZ_PIN 8    // buzzer pin
#define NUM_LEDS 8   // set the no of leds in  led strip

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int safeLevel = 150;  // safe level of air quality
int alarmLevel = 450;  // level of air which is hazardous

void setup() {
  Serial.begin(9600);
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(MQ9_PIN, INPUT);

  strip.begin();
  strip.setBrightness(100);  //set the brighness of the leds
  strip.show(); 

  for(int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255));
  }
  strip.show();
  delay(2000); 
}

void loop() {
  int val = analogRead(MQ9_PIN);
  Serial.println(val);

  if (val >= alarmLevel) {
    tone(BUZ_PIN, 1000); 
    
    for(int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
    strip.show();
    delay(250); 
    
    noTone(BUZ_PIN); 
    strip.clear();      
    strip.show();
    delay(250); 
    
  } else {
    noTone(BUZ_PIN); 
    
    int cVal = constrain(val, safeLevel, alarmLevel);
    long hue = map(cVal, safeLevel, alarmLevel, 21845, 0);   // maps  the color of the leds with the sensor reading of AIR
    uint32_t color = strip.ColorHSV(hue, 255, 255);
    
    for(int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, color);
    }
    strip.show();
    
    delay(100);
  }
}
