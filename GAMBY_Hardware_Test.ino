/*
GAMBY Hardware Test v001
~~~~~~~~~~~~~~~~~~~~~~~
An Arduino sketch to load onto your newly-built GAMBY in order to 
test all of the hardware buttons including the D-Pad, the LCD, 
and the piezo speaker.

Based on GAMBY BlockMode Template from David R. Stokes, with audio code from
(http://arduino.cc/en/Tutorial/tone)
*/

#include <Gamby.h>
#include <avr/pgmspace.h>
#include "pitches.h"

extern prog_int32_t font[];

// A sample palette of blocks, stored in program memory. You can replace one 
// or all of the individual blocks, but a palette can have no more than 16 
// blocks in it. Typically, you will have only one per sketch, but it is
// possible to create more than one and switch between them.
PROGMEM prog_uint16_t palette[] = {
    0x0000, //  0 All 'white' (block 0 should almost always be 0x0000) 
    0xffff, //  1 All 'black'
    0x5a5a, //  2 50% gray dither
    0xfaf5, //  3 75% gray dither
    0x050a, //  4 25% gray dither
    0xedb7, //  5 Light diagonal left line
    0x1248, //  6 Dark diagonal left line
    0x7bde, //  7 Light diagonal right line
    0x8421, //  8 Dark diagonal right line
    0x888f, //  9 Dark-on-light solid grid lines
    0x1110, // 10 Light-on-dark solid grid lines
    0xa080, // 11 Light-on-dark dotted grid lines
    0x5f1f, // 12 Dark-on-light dotted grid lines
    0x33cc, // 13 Checker pattern 
    0xcc33, // 14 Mirrored checker pattern
    0x0001  // 15 Single pixel (upper right)
};

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

// Each of Gamby's 'modes' are wrapped in a class, a self-contained unit
// that bundles together all the required functionality. To use a mode,
// you must first create an 'instance' of its class -- a sort of working 
// copy. Your sketch should only use one.
GambyBlockMode gamby;

int buttonStates[] = {0,0,0,0};

char* helpText = "Push somethin'";
char* newHelpText = helpText;

int activeButton = 0;

void setup() {
  // Set the block palette. You generally need to do this only once, usually
  // just after initializing Gamby. You could, however, do this elsewhere in 
  // your sketch -- for example, if you had a role-playing game and had an 
  // 'indoor' and an 'outdoor' palette.
  gamby.palette = palette;
  gamby.font = font;
}

void loop () {
  
  gamby.readInputs();
  
  int buttonPressed = 0;
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_1) {
    drawButtonOne(1);
    activeButton = 1;
    buttonPressed = 1;
    //tone(9,10,50);
  }
  else
  {
    drawButtonOne(2);
  }
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_2) {
    activeButton = 2;
    buttonPressed = 1;
    drawButtonTwo(1);
    //tone(9,10,50);
  }
  else
  {
    drawButtonTwo(2);
  }
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_3) {
    activeButton = 3;
    buttonPressed = 1;
    drawButtonThree(1);
    //tone(9,10,50);
  }
  else
  {
    drawButtonThree(2);
  }
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_4) {
    activeButton = 4;
    buttonPressed = 1;
    drawButtonFour(1);
    //tone(9,10,50);
  }
  else
  {
    drawButtonFour(2);
  }
  
  // Draw DPAD Up
  if (gamby.inputs & DPAD_UP) {
    activeButton = 5;
    buttonPressed = 1;
    drawDpadUp(1);
    //tone(9,10,50);
  }
  else
  {
    drawDpadUp(2);
  }
  
  // Draw DPAD Up
  if (gamby.inputs & DPAD_RIGHT) {
    activeButton = 6;
    buttonPressed = 1;
    drawDpadRight(1);
    //tone(9,10,50);
  }
  else
  {
    drawDpadRight(2);
  }
  
  // Draw DPAD Up
  if (gamby.inputs & DPAD_DOWN) {
    activeButton = 7;
    buttonPressed = 1;
    drawDpadDown(1);
    //tone(9,10,50);
  }
  else
  {
    drawDpadDown(2);
  }
  
  // Draw DPAD Up
  if (gamby.inputs & DPAD_LEFT) {
    activeButton = 8;
    buttonPressed = 1;
    drawDpadLeft(1);
    //tone(9,10,50);
  }
  else
  {
    drawDpadLeft(2);
  }
  
  drawHelpText(activeButton,buttonPressed);
}

void drawButtonOne(int state) {
    int top = 4;
    int left = 18;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawButtonTwo(int state) {
    int top = 7;
    int left = 21;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawButtonThree(int state) {
    int top = 7;
    int left = 15;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawButtonFour(int state) {
    int top = 10;
    int left = 18;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawDpadUp(int state) {
    int top = 4;
    int left = 4;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawDpadRight(int state) {
    int top = 7;
    int left = 7;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawDpadDown(int state) {
    int top = 10;
    int left = 4;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawDpadLeft(int state) {
    int top = 7;
    int left = 1;
    gamby.drawBlock(left+0,top+0,state);
    gamby.drawBlock(left+0,top+1,state);
    gamby.drawBlock(left+0,top+2,state);
    gamby.drawBlock(left+1,top+0,state);
    gamby.drawBlock(left+1,top+1,state);
    gamby.drawBlock(left+1,top+2,state);
    gamby.drawBlock(left+2,top+0,state);
    gamby.drawBlock(left+2,top+1,state);
    gamby.drawBlock(left+2,top+2,state);
}

void drawHelpText(int state, int buttonPressed) {
  
  if(state == 1) {
    newHelpText = "Button 1";
  }
  
  if(state == 2) {
    newHelpText = "Button 2";
  }
  
  if(state == 3) {
    newHelpText = "Button 3";
  }
  
  if(state == 4) {
    newHelpText = "Button 4";
  }
  
  if(buttonPressed == 0) {
    newHelpText = "Push somethin'";
  }
  
  gamby.setPos(0,0);
  if(helpText != newHelpText) {
    gamby.clearLine();
  }
  
  gamby.print(newHelpText);
  
  helpText = newHelpText;
  
}
