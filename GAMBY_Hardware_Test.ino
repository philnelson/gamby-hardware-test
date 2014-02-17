/*
GAMBY BlockMode Template
~~~~~~~~~~~~~~~~~~~~~~~

A jump start on using Gamby to draw a 24x16 grid of 4x4 pixel 'blocks.' This 
skeletal sketch contains the bare minimum required to get Gamby running in 
BlockMode. Do a "Save As" to make a copy and fill it out with your own code!

by David R. Stokes (gamby@logicalzero.com) 2012-08-28
*/

#include <Gamby.h>
#include <avr/pgmspace.h>

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


// Each of Gamby's 'modes' are wrapped in a class, a self-contained unit
// that bundles together all the required functionality. To use a mode,
// you must first create an 'instance' of its class -- a sort of working 
// copy. Your sketch should only use one.
GambyBlockMode gamby;

int buttonStates[] = {0,0,0,0};

void setup() {
  // Set the block palette. You generally need to do this only once, usually
  // just after initializing Gamby. You could, however, do this elsewhere in 
  // your sketch -- for example, if you had a role-playing game and had an 
  // 'indoor' and an 'outdoor' palette.
  gamby.palette = palette;
}

void loop () {
  
  gamby.readInputs();
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_1) {
    drawButtonOne(1);
    //tone(9,10,50);
  }
  else
  {
    drawButtonOne(2);
  }
  
  // Draw Button 1
  if (gamby.inputs & BUTTON_2) {
    drawButtonTwo(1);
    //tone(9,10,50);
  }
  else
  {
    drawButtonTwo(2);
  }
}

void drawButtonOne(int state) {
    gamby.drawBlock(0,0,state);
    gamby.drawBlock(0,1,state);
    gamby.drawBlock(0,2,state);
    gamby.drawBlock(1,0,state);
    gamby.drawBlock(1,1,state);
    gamby.drawBlock(1,2,state);
    gamby.drawBlock(2,0,state);
    gamby.drawBlock(2,1,state);
    gamby.drawBlock(2,2,state);
}

void drawButtonTwo(int state) {
    gamby.drawBlock(3,3,state);
    gamby.drawBlock(3,4,state);
    gamby.drawBlock(3,5,state);
    gamby.drawBlock(4,3,state);
    gamby.drawBlock(4,4,state);
    gamby.drawBlock(4,5,state);
    gamby.drawBlock(5,3,state);
    gamby.drawBlock(5,4,state);
    gamby.drawBlock(5,5,state);
}

void drawButtonThree(int state) {
    gamby.drawBlock(3,3,state);
    gamby.drawBlock(3,4,state);
    gamby.drawBlock(3,5,state);
    gamby.drawBlock(4,3,state);
    gamby.drawBlock(4,4,state);
    gamby.drawBlock(4,5,state);
    gamby.drawBlock(5,3,state);
    gamby.drawBlock(5,4,state);
    gamby.drawBlock(5,5,state);
}
