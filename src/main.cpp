#include <Arduino.h>
#include <FastLED.h>
//fire_1
const int led_1_Pin =  11;
const int led_2_Pin =  10;
const int led_3_Pin =  9;
//fire_2
const int led_4_Pin =  3;
const int led_5_Pin =  5;
const int led_6_Pin =  6;
//kerk
const int led_7_Pin =  14;
const int led_8_Pin =  16;
//huisje_midden
const int led_9_Pin =  19;

// constants won't change:
const long interval_fire_1 = 100;  
unsigned long previousMillis_fire_1 = 0;   //store last update time   

const long interval_fire_2 = 100;  
unsigned long previousMillis_fire_2 = 0;   //store last update time   

//RGB section


#define NUM_LEDS 1 
#define LED_TYPE    WS2812b
#define DATA_PIN 18
#define BRIGHTNESS 255
#define SATURATION 255
#define COLOR 125
#define COLOR2 255

CRGB leds[NUM_LEDS];
unsigned long previousMillis_rgb = 0;
const unsigned long interval_rgb = 100;
byte C_NOW = 0; byte C_NEXT = 0; int RANDOM_R = 0; int DIRECTION = 1; 
  


void setup() {
  // set the digital pin as output:
  pinMode(led_1_Pin, OUTPUT);
  pinMode(led_2_Pin, OUTPUT);
  pinMode(led_3_Pin, OUTPUT);
  pinMode(led_4_Pin, OUTPUT);
  pinMode(led_5_Pin, OUTPUT);
  pinMode(led_6_Pin, OUTPUT);
  pinMode(led_7_Pin, OUTPUT);
  pinMode(led_8_Pin, OUTPUT);
  pinMode(led_9_Pin, OUTPUT);

   FastLED.setMaxPowerInVoltsAndMilliamps(5,1000);
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    
}

void loop() {

  fire_effect_1();
  fire_effect_2();
  kerk();
  kerstboom();
  huisje_midden();
}

//==========================================================

void fire_effect_1(){
  unsigned long currentMillis_fire_1 = millis();
  if (currentMillis_fire_1 - previousMillis_fire_1 >= interval_fire_1) {
    
    // save the last time you blinked the LED
    previousMillis_fire_1 = currentMillis_fire_1;
    
    // make fire go BRRRRR
    analogWrite(led_1_Pin, random(120)+135);
    analogWrite(led_2_Pin, random(120)+135);
    analogWrite(led_3_Pin, random(120)+135);
  }
}

//==========================================================

void fire_effect_2(){
  unsigned long currentMillis_fire_2 = millis();
  if (currentMillis_fire_2 - previousMillis_fire_2 >= interval_fire_2) {
    
    // save the last time you blinked the LED
    previousMillis_fire_2 = currentMillis_fire_2;
    
    // make fire go BRRRRR
    analogWrite(led_4_Pin, random(120)+135);
    analogWrite(led_5_Pin, random(120)+135);
    analogWrite(led_6_Pin, random(120)+135);
  }
}

//==========================================================

void kerk(){
digitalWrite(led_7_Pin, HIGH);
digitalWrite(led_8_Pin, HIGH);
}

//==========================================================

void huisje_midden(){
digitalWrite(led_9_Pin, HIGH);
}

//==========================================================

void kerstboom() {

 fill_solid(leds, NUM_LEDS, CHSV(C_NOW, SATURATION, BRIGHTNESS)); FastLED.show();

  unsigned long currentMillis_rgb = millis();
 
  if (currentMillis_rgb - previousMillis_rgb >= interval_rgb){
    previousMillis_rgb = currentMillis_rgb;
    if(C_NOW == C_NEXT){
    
    C_NEXT = random8(); 
    RANDOM_R = random8(); //chooses a random number for the fade to see which direction the fade goes

      //this section chooses a direction of the fade by checking RANDOM_R
      if (RANDOM_R >= 128){
            DIRECTION = 1;
          }else{
            DIRECTION = -1;

          }    }else{ 
          C_NOW = C_NOW + DIRECTION; // the actual fade from current colour to the new colout
}
}}