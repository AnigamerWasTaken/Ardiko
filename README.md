# Ardiko
An arduino based Taiko inspired 1 button rhythm game!
**NOTE: This project was made and intended to run on Arduino MEGA2560 hardware. Others are possible, but they are not supported by me, as the mega is my sole arduino board**

# How to create it physically:
You need a button (tactile, large ones are ideal), an LED bar graph, 3 more LEDs, and a piezzo buzzer.

Connect your button to 24, Connect the LED bar graph (or 10 LEDs) to 26 - 44, 3 of your other leds for lives to 44 - 50, and finally the buzzer to 12 PWM.

## How to design tracks: 
Most important part: the music. Simply use the ```` tone() ```` function to make the song. Add them to loop.
Now, to spawn a note, simply add this code:

```` notes[sizeof(notes)] = 10; ```` into loop.

and in the empty spaces, use ````updateGame()```` and ````delay(1000)```` in loop. Now, to share your beautiful track, simply share your loop function.

## How to download tracks:

Simply duplicate your INO file and replace the loop function with the loop function of another song you found on pastebin, github, etc. and upload it to your MEGA.


# HAVE FUN!!!


