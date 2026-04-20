_This project has been created as part of the 42 curriculum by **nclavel**, **thlibers**_

<div align="center">
    <img src=".images/logo.png">
</div>


## Description:
**Cube3D** is program that used **raycasting** to render with the library called **"minilibx"**.

Raycasting is a rendering technic that consists of shooting ray to find the distance between the player and every wall on the field of view of the player. This rendering technic was highly used on 90s on games like Wolfenstein 3D (1992), Doom (1993) or Quake (1996)

## Instruction:
1. Build the project using `make` 
```sh
make
# OR 
make cube3D
```
2. Launch the game
```sh
./cube3D {[map].cub}
```
- Remove every compilation object file
```sh
make clean
```
- Remove every compilation object file and remove the compiled file
```sh
make fclean
```
- Remove every compilation object file, remove the compiled file and rebuild the project
```sh
make re
```

## Available features:
- [x] A working game
- [x] Minimap
- [x] Interaction with door
- [x] Collision system
- [x] Movement system (keyboard/mouse)
- [x] Animation

## Map requirement:
To launch the game you should put in 2nd argument a map file on the right format. The file should:
- File should end with '.cub' extension
- Texture should be in xpm format
- Contain information on the map like:
	- 'NO {texture_path.xpm}'  - Texture on the NORTH wall
	- 'WE {texture_path.xpm}'  - Texture on the WEST wall
	- 'SO {texture_path.xpm}'  - Texture on the SOUNTH wall
	- 'EA {texture_path.xpm}'  - Texture on the EAST wall
	- 'DO {texture_path.xpm}'  - Texture on the DOOR wall (required if the map contains door)
	- 'C R,G,B'                - Color of the celling with the RGB color code
	- 'F R,G,B'                - Color of the floor with the RGB color code
- Contain a map
- Map composed by only:
	- '0' - Floor
	- '1' - Wall
	- 'N', 'E', 'S', 'W' - Player that look on north, est, south or west
	- 'D' - Door (Optional)
- Map should be closed by wall
- Map may not be rectangular
- Map should be at the bottom of the file
- Map should be less that 180 character in width and 160 character in height

## Sample map
### Valid map
- Simple map
```cub
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001111111110111111
1111D111111111011100000010001
1111D111111111011101010010001
11000000110101011100000010001
1000E000000000000000000011111
10000000000000001101000010001
11000001110101011111000000111
11110111 1110101 100000000001
11111111 1111111 111111111111
```

- Map with door
```cub
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
DO ./path_to_door_texture

F 220,100,0
C 225,30,0

            11111111111111111111111111111111111111111111111111111111
            1100000000000000000000000000000000000000000000000010011
              1000000000000000000000000000000000000000000000001
              1000000000000000000000000000000000000000000000001
              1000000000000000111000000000000000000000000000001
              10000000000000001  10000000000000000000000000000111
              10000000000000001111000DDD0000000000000000000000001
         1111111000000000000000000000DND0000000000000000000000111
         1000000000000000000000000000DDD00000000000000000000001
         100000000000000000000000000000000000000000000000000001
         100000000000000000000000000000000000000000000000000001
         100000000000000000000000000000000000000000000000000001
         100000000000000000000000000000000000000000000000000001111111111111
         11111111111111111111111111111111111111111111111111111111111111111111111111111
```

### Invalid map
- This map have a red color code for the 'C' that are higher than 255
```cub
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
DO ./path_to_door_texture

F 220,100,0
C 226,30,0

11111111111111111111111111111111111111
1E000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000001000000000000000000001
1000000000000000D000000000000000000001
10000000000000000100000000000000000001
10000000000000001000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
11111111111111111111111111111111111111
```

- This map isn't closed
```cub
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
DO ./path_to_door_texture

F 220,100,0
C 225,30,0

        11111111111111111111111111111111111111
        1E000000000000000000000000000000000001
1111111110000000000000000000000000000111111111
10000000000000000000000000000000000001
10000000000000000000000011111111111111
1000000000000000000000001
1000000000000000100000001
1000000000000000000000001
10000000000000000100000011111111101111
10000000000000001000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
10000000000000000000000000000000000001
11100000000000000000000000000000000001
  111111111111111111111111111111111111

```

## Player control:
- Move the player with:
	- 'W' - Move forward
	- 'S' - Move backward
	- 'D' - Move on right
	- 'A' - Move on left
- Move camera with:
	- Mouse mouvement
	- '←' - Move camera to the left
	- '→' - Move camera to the right
- 'R' - Reload the gun
- Left mouse click - Shoot with the gun
- 'SPACE' xor 'E' - Open the door

## Part of ressources used:
- [LODEV wiki](https://lodev.org/cgtutor/raycasting.html)

## Showcase
[![Cube3D](.images/thumbnail.png)](.images/showcase.mp4)

<br>

<div align=center>
    <a href="https://github.com/gun8hoot/cube3d/?tab=readme-ov-file#description">
        <ul>
            <b>
            <il>Made with ❤️ by</il>
            <il>thlibers</il> 
            <il>nclavel</il>
            </b>
        </ul>
    </a>
</div>
