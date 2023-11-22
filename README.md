# so_long
Summary:
"This project is a very small 2D game.
Its purpose is to make you work with textures, sprites,
and some other very basic gameplay elements."

This project is part of the 42 Curcus projects. With using special library MiniLibX (mlx), this project aims to create a little 2D game. MiniLibX library is built on top of X11 which is X Window System. To get more detail about X Window System click <a href="https://en.wikipedia.org/wiki/X_Window_System" target="_blank">here</a>.

The aim of the game is to collect every collectibles placed in the map with the character then escape from the map. If all collectibles aren't collected by the character, character won't be able to escape from the map. Map will be given to the program by command-line arguments. For example:  ```./so_long maps/map.ber```. The .ber extension must be used for map files according to the project's instructions. Map could only contain several characters which are: 1, 0, C, P, E. Other characters than these will cause an error. Apart from these, there are several number of requirements for maps. To see all map requirements click <a href="en.subject.pdf">here</a>. Example of a valid map:
```
11111111111
1P000001001
1000C001001
110010C00E1
11111111111
```
The map will be parsed by the program and a compatible image will be placed in window based on the characters in the map. To create a window, the program uses a function of MiniLibX library which is ```mlx_new_window()```. However, to start to work with MiniLibX library which means before using any function of the library ```mlx_init()``` function must be called to create a connection between the program and the graphical system which is X11 on Unix-based systems. After creating a connection other library functions can be used. According to the <a href="en.subject.pdf">instruction page</a>, .xpm files must be used as sprites. To use xpm files as sprites ```mlx_xpm_file_to_image()``` function must be used to make xpm files usable by  ```mlx_put_image_to_window()``` function. When using this library, creating a window and putting an image into that window requires to work with pixels. After putting every image to the window, the program should become responsive to keybord keys. To make the program event driven  ```mlx_hook()``` function must be used. With using ```mlx_hook()``` function and key handling functions, which will be called by ```mlx_hook()``` function, the program becomes responsive to the keys. However, after calling hook functions of MiniLibX library, ```mlx_loop()``` function must be called to register the hooks and to prevent the program to finish it's execution. After collecting all the collectibles in the map, the player can exit from the map using the gate or door which is placed in the map.

It is important to note that to check if a map is valid or not which means if all collectibles are able to be collected by the player without making any impossible moves, this program uses recursive flood fill algorithm. With flood fill algortihm, the program travel all the map to find if all the collectibles can be collected by the player. To find more information about the recursive flood fill algorithm check <a href="https://en.wikipedia.org/wiki/Flood_fill">here</a>.

To start the game: 1- Execute ```make``` command in the directory where Makefile exists. 2- Execute ```./so_long maps/map1.ber```. There are several maps to play the game. To change the map choice, one can change the name of the map file to an existed map in the directory of ```maps```.

There aren't any official documentation of MiniLibX library. Therefore, most of the time, to understand how a function works, comments of the functions in the source code of the library could be useful. However there are some unofficial documentations which were made by 42 students. One of them was done by hsmits and jvan-sni. To find it click <a href="https://harm-smits.github.io/42docs/libs/minilibx">here</a>.

To find more detail about the project click <a href="en.subject.pdf">here</a>.
