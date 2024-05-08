// Simple project using Arduino UNO with M5stack HEX RGB LED Display

// created by upir, 2024
// youtube channel: https://www.youtube.com/upir_upir

// YouTube video: https://youtu.be/1NI-I1Lpdqo
// Source files: https://github.com/upiir/arduino_hexagonal_displays
// WOKWI simulation: https://wokwi.com/projects/397321165094894593

// Links from the video:
// Hexagonal Display with smaller LEDs: https://shop.m5stack.com/products/neo-hex-37-rgb-led-board-ws2812
// Hexagonal Display with bigger LEDs: https://shop.m5stack.com/products/hex-rgb-led-board-sk6812
// NeoPixel documentation: https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
// Photoshop scripting: https://developer.adobe.com/photoshop/uxp/2022/ps_reference/classes/colorsamplers/
// Previous WOKWI sketch with neopixel canvas: https://wokwi.com/projects/394323585291513857
// Freeform sculptures: https://www.youtube.com/watch?v=LqVFxNFGNbc
// Neopixel canvas example: https://wokwi.com/projects/379096458121466881
// Breadboard wires: https://s.click.aliexpress.com/e/_Dkbngin
// Arduino UNO R3: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_DlxEfPX
// Photopea (online graphics editor like Photoshop): https://www.photopea.com/

// Related videos with LED Matrix Displays:
// LED ring light for potentiometer - https://youtu.be/Bot865qmdsM
// Robot eyes display: https://youtu.be/If-hiuwsQh0
// Arduino Wood Clock: https://youtu.be/50bVXHYW_9Q
// Arduino UNO R4 display: https://youtu.be/Qpi0Y5bcvlQ
// LED matrix badges: https://youtu.be/MRTxTx8bgYg
// Why are pixels square?: https://youtu.be/oLgUtjyKO6Q
// Three knob controller: https://youtu.be/e2UNsZPjHkk
// Really old display: https://youtu.be/PBaL9w5w-2c


#include <Adafruit_NeoPixel.h> // Adafruit NeoPixel library is required to drive the NeoPixel LEDs on the board

#define PIN        6  // data pin on the Arduino board, could be any pin
#define NUMPIXELS 37 // number of NeoPixels on the display
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // initialize the NeoPixels

// this array contains RGB values for the image that should be displayed on the hexagonal display
// it was automatically generated from a Photopea image using script - please see the video for details
byte hex_image[] = {
/*NeoPixel: 0*/ 255, 108, 0, 
/*NeoPixel: 1*/ 255, 108, 0, 
/*NeoPixel: 2*/ 255, 108, 0, 
/*NeoPixel: 3*/ 255, 108, 0, 
/*NeoPixel: 4*/ 194, 255, 0, 
/*NeoPixel: 5*/ 0, 0, 0, 
/*NeoPixel: 6*/ 0, 0, 0, 
/*NeoPixel: 7*/ 0, 0, 0, 
/*NeoPixel: 8*/ 194, 255, 0, 
/*NeoPixel: 9*/ 0, 0, 0, 
/*NeoPixel: 10*/ 0, 0, 0, 
/*NeoPixel: 11*/ 0, 0, 0, 
/*NeoPixel: 12*/ 0, 0, 0, 
/*NeoPixel: 13*/ 0, 0, 0, 
/*NeoPixel: 14*/ 39, 255, 0, 
/*NeoPixel: 15*/ 0, 0, 0, 
/*NeoPixel: 16*/ 0, 0, 0, 
/*NeoPixel: 17*/ 0, 0, 0, 
/*NeoPixel: 18*/ 0, 255, 253, 
/*NeoPixel: 19*/ 0, 255, 253, 
/*NeoPixel: 20*/ 0, 255, 253, 
/*NeoPixel: 21*/ 0, 255, 253, 
/*NeoPixel: 22*/ 0, 0, 0, 
/*NeoPixel: 23*/ 0, 0, 0, 
/*NeoPixel: 24*/ 0, 0, 0, 
/*NeoPixel: 25*/ 0, 0, 0, 
/*NeoPixel: 26*/ 0, 0, 0, 
/*NeoPixel: 27*/ 0, 16, 255, 
/*NeoPixel: 28*/ 183, 0, 255, 
/*NeoPixel: 29*/ 0, 0, 0, 
/*NeoPixel: 30*/ 0, 0, 0, 
/*NeoPixel: 31*/ 0, 0, 0, 
/*NeoPixel: 32*/ 183, 0, 255, 
/*NeoPixel: 33*/ 255, 0, 117, 
/*NeoPixel: 34*/ 255, 0, 117, 
/*NeoPixel: 35*/ 255, 0, 117, 
/*NeoPixel: 36*/ 255, 0, 117
};


void setup() { // put your setup code here, to run once
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}

void loop() {  // put your main code here, to run repeatedly
  
  //pixels.clear(); // Set all pixel colors to 'off'

  // go over all the neopixels
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // set the color of the neopixel to the RGB value from the array above
    pixels.setPixelColor(i /*index*/, /*Red*/ pixels.Color( hex_image[i*3], /*Green*/ hex_image[i*3+1], /*Blue*/ hex_image[i*3+2]  ));
    //delay(500); // uncomment the delay if you want the image to slowly appear
    pixels.show(); // show function must be called to update the neopixels with new colors

  }

  pixels.show();   // Send the updated pixel colors to the hardware.  
}
