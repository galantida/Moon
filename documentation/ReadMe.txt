This is a programmable lamp base for "moononournation" five inch moon Lamp.  I am new to 3D printing and for one of my first prints I printed the moon model. It was so beautiful I had to create a way to display it properly. I decided to create this base which supports both lighting the entire moon or only lighting half of the moon like it would really be in space. I also left the moon shade unmounted so you could rotate it to view the different phases of the moon. I mounted mine to a wooden base but it is designed to work without it as well.

I created the lamp base to have mounts for an Arduino Nano, two LEDs and two buttons. I simply hot glued the resistors so they didn't move around. I used some sand paper on the LEDS so I they would give off a soft defused light in all directions. Once assembled and the software is loaded the first button sets the mode. The available modes are off, cycle of real colors, constant white, constant yellow, constant red, cycle of random colors, and cycle of random complimentary colors. The second button is the halfmoon button. It sets the moon lighting from full to half. In the random modes the moon is always fully lit and halfmoon button switches from all one color to two different colors on each side. 

This was my first time using Fusion 360 as well as creating a 3D model for printing. I didn't realize how much there was to consider for a printed model. Some of my earlier designs were just not printable. Even in this design I had to curve some of the over hangs to support the print as it worked its way up. Now you should be able to print this without support structures turned on. It is a bit hard to get off the print bed though. I slid a metal poke through the power wire hole to pry it up without breaking it. Just make sure to put something under the other end so you don't scratch your bed. 

I have included my original model file as well as the Arduino source code in case you want to make changes. I have also included a schematic of the electronics. If you come up with a cool coding Idea please share it so I can include it in the original GitHub repository. This is my first post so let me know if I forgot anything.

Link to Original Moon
Original Moon Lamp by "moononournation". Print the 5" one with the flat bottom. 
https://www.thingiverse.com/thing:4102658

Link to latest Arduino Source Code
https://github.com/galantida/Moon

Parts List
Breadboard buttons - https://www.google.com/search?q=breadboard+buttons
RGB LEDS (common anode) - https://www.google.com/search?q=RGB+LEDS
ARDUINO NANO - https://www.google.com/search?q=Arduino+Nnano
2 Resistors 4.7K (Pull Down Resistors for buttons)
6 Resistors Sized for your LEDs ((2)Red 150 Ohm, (4)Blue and Green 68 Ohm)


Tools Used
Autodesk Fusion 360