# Wolf3D (3D Labyrinth Generator)

Inspired by the famous eponymous 90s game that was the first First Person Shooter, this project allows you to tackle the technique of ray-casting. Your goal will be to represent a dynamic view inside a labyrinth in which one can move.

## Prerequisites

Only works on macOS.  Must have DirectX11 installed.  See header for libraries.

### Running the Program

The executable is called *wolf3d*.  It is created with the included *Makefile*.  All it needs to run is a map file located in the maps directory.  There are example maps, but there's also a file explaining how to make your own map.

Example: `./wolf3d maps/simple.txt`

Once inside, use the **ESC** key to exit the program at anytime.

### Controls

**Arrow Up and Down** to move forward and backward
**Arrow Left and Right** to turn left and right
Hold **Shift** to move faster
**Tab** cycles between control legend, minimap, and inactive.  Legend is on by default.

### Map-making

While there are premade maps, it's possible to make your own.

- Every character is seperated by a space, unless it's the edge of the map.
- 'W' is used to indicate a wall.  The map must be fully enclosed with walls to work.
- '.' is floor.  Basically you can move anywhere that there is one.  Anything that isn't a 'W' or a 'P' must be filled with this.
- 'P' is player starting position.  Must have one, and only one.
- Map size can be anywhere between 2x2 and 50x50, minus map edge.
- Map can have horizontal size bigger, but not vertical, i.e. 5x3 is fine, but not 3x5.

### Extras

These were considered extra for the purposes of a minimum working program.

* Wall collision
* Ray-cast floor
* Skybox
* Minimap

## About

Wolf3D was built using C.  It utilizes a mini-library derived from DirectX11 called minilibx.  The purpose of the project is to use ray-casting techniques to create a pseudo 3d labyrinth, and then navigate it.

Each wall is a different texture according to its cardinal direction.

This project was originally created by 42 Silicon Valley.
