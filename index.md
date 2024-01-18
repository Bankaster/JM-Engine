# JM Engine

The JM Engine is a 3D engine focused on scripting tasks in C++ carried out by two CITM students for the third delivery of the Video Game Engines course.


## Logo:

<img align="center" width="300" height="160" src="https://media.discordapp.net/attachments/1046911945695043725/1196885927948193864/JM.png">


## Developers GitHub:

### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [Joan Damià](<https://github.com/JoanDamia>)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [Miguel Rodríguez](<https://github.com/Bankaster>)

<div>
<img align="center" width="300" height="300" src="https://media.discordapp.net/attachments/1046911945695043725/1196885928451526717/Joan.png">
<img align="center" width="300" height="300" src="https://media.discordapp.net/attachments/1046911945695043725/1196885928812220437/Miguel.png">
</div>



## Main Core Subsystems

In Play Mode you can control a Tank and shoot bullets.

Tank Controls:
- W : Move forward
- A : Rotate left
- S : Move backwards
- D : Rotate right
- Mouse Movement : Aim Shoot
- Right Click : Shoot

The Tank moves and rotates with keyboard controls and the turret rotates with the mouse.

When Play Mode stops the Tank positions resets.

The Bullets are game objects with a life time.

When a bullet is created, a text appears in the Console window.

The script variables of the tank are modifiable in the Inspector window.



## How it works

This engine is focused on scripting, that is why its features and systems are focused on this concept.

As soon as you open the engine, you will be able to find the different game objects in the scene in the hierarchy menu. In this engine, the CENTURION game object has by default a script to simulate a tank that moves and shoots.

Select the CENTURION game object to see its parameters in the Inspector window. In this window you will see the Information section, in which you will be able to see the script associated with the game object and change its variables.

<img align="center" width="800" height="350" src="https://media.discordapp.net/attachments/1046911945695043725/1197477576634007563/JM-Engine_gif_1.gif">

By selecting the Play button, you will be able to control the game object that has a tank script associated with it, in this case, the CENTURION is associated by default.

The tank uses keyboard control to move and rotate while the mouse is used to aim and shoot. The bullets that are fired are new game objects that disappear after a few seconds.

Both the tank movement parameters and the speed and life of the bullets are configurable in the Information window in the Tank Script section.

Finally, use the PAUSE button to pause the scene, and the STOP button to stop it, when the scene stops, the tank will return to its initial position.

<img align="center" width="800" height="350" src="https://media.discordapp.net/attachments/1046911945695043725/1197477576134901862/JM-Engine_gif_2.gif">



## Engine operation example

<video src="https://media.discordapp.net/attachments/1046911945695043725/1197487204101017620/jm_engine_video.mp4"  width="1000" height="450"></video>



## License

MIT License

Copyright (c) 2024 Joan Damià & Miguel Rodríguez

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
