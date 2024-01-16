# JM-Engine by Joan Damià & Miguel Rodríguez.
The JM Engine is a 3D engine focused on scripting tasks in C++ carried out by two CITM students for the third delivery of the Video Game Engines course.

This engine is developed by:
- Joan Damià - [Joan Damià](<https://github.com/JoanDamia>)
- Miguel Rodríguez - [Miguel Rodríguez](<https://github.com/Bankaster>)
  
Github repository: [JM-Engine](<https://github.com/Bankaster/JM-Engine>)

This Engine is forked from another CITM 3D Engine, you can check the original repesitory here:

Original repository: [DaTo Engine](<https://github.com/DaniMariages/DaTo-Engine>)

## Debug Controls:
- Left Control --> Center selected object
- Left shift --> Duplicate movement speed
- Right Click --> FPS camera
- Left Alt + Left Click --> Orbital camera
- Right Shift --> Top view
- Up Arrow --> Front view
- Right Arrow --> Right view
- Left Arrow --> Left view
- Down Arrow --> Back view
- Scroll up --> Zoom in
- Scroll down --> Zoom out

  
### FPS movement:
- W --> Move forward
- A --> Move left
- S --> Move backwards
- D --> Move right
- R --> Move up
- F --> Move down

  
### While selected (Guizmo):
- W --> Position
- R --> Scale
- E --> Rotate
- T --> Universal


### Play Controls:
- W --> Move forward
- A --> Rotate left
- S --> Move backwards
- D --> Rotate right
- Mouse Movement --> Aim Shoot
- Right Click --> Shoot

  
### Additional functionalities
- Top, sides, back and front view (Reworked).
- Quick options when you right click on the Game Objects displayed in the Hierarchy
- Reparent game objects one is selected and dragged to another one


## Features v0.1
- Loading models and textures with Assimp and DevIL.
- Render models and textures with OpenGL.
- .fbx support for models (at the moment).
- .png and .dds support for textures (for now).
- Unity-like camera controls.
- Hierarchy system.
- Drag & Drop for all supported formats.
- Game Objects with texture, mesh and transform components.


## Features v0.5
- Game objects can have a camera component.
- The Transform component of the Game Objects works, and can be modified both from the Inspector and with the Guizmos. 
- Hierarchy:
  - Fast options to Delete, Hide and Create Empty Child.
  - Reparent by dragging a Game Object into another.
- Game timer that can be played, paused, resumed and stopped.
- All meshes use a bounding volume (AABB) and can be discarded using Frustum Culling.
- Game Objects can be picked from the world using the mouse.
- Mouse Picking can be deactivated for a selected object.
- The editor has two windows, one with the scene (editor view) and another captured from a Game object witha camera component (Main Game Camera), each one has its own framebuffer and the user can visualize both at the same time.
- All normals move with the model.
- Skybox added.
- Warning window before deleting a game object or scene, with a checkbox for "Do not show again".
- Game Object can be renamed from Inspector.
- If an object is repeated, the name will change to: Name + (number of repetitions).


## Features v1.0
- The Tank moves and rotates with keyboard controls and the turret rotates with the mouse.
- When Play Mode stops the Tank positions resets.
- The Tank shoots bullets with right click.
- The Bullets are game objects with a life time.
- When a bullet is created, a text appears in the Console window.
- The script variables of the tank are modifiable in the Inspector window.


## Libraries
- [Assimp](<https://github.com/assimp/assimp.git>)
- [DevIL](<https://openil.sourceforge.net>)
- [Glew](<https://glew.sourceforge.net>)
- [ImGui](<https://github.com/ocornut/imgui.git>)
- [MathGeoLib](<https://github.com/juj/MathGeoLib.git>)
- [SDL](<https://www.libsdl.org>)
- [Parson](<https://github.com/kgabis/parson>)
- [PCG](<https://www.pcg-random.org>)
