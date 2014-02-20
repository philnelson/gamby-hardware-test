GAMBY Hardware Test
===================

like it says on the tin, this is a hardware test app for the [GAMBY retro gaming platform][gamby] on Arduino.

The goal of this Arduino sketch is to display each button on the GAMBY shield on its own LCD and provide use feedback when each button is pressed. This will help people who have just assembled the shield (or added custom components) to make sure everything works how it's supposed to.

[gamby]: http://logicalzero.com/gamby/ "GAMBY homepage"

What Works
===================

Buttons and DPAD are fully supported and testable. If you load up the Arduino sketch and your button presses don't register, or the DPAD directions do not activate the UI buttons, that means your hardware isn't wired up correctly.

Coming Up
===================

I'm adding a sound test suite and a more comprehensive LCD test, too, but that will take a little longer.
