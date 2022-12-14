# so_long 🎮 [![esafar's 42 so_long Score](https://badge42.vercel.app/api/v2/cl6l739qg00490gialxmtgsrk/project/2392663)](https://github.com/JaeSeoKim/badge42)
## 🧱 Subject
You must create a small 2D game where a dolphin
escapes earth after eating some fish. Or any hero
collects any valuables before leaving the place.
You will use 2d view (top-down or profile)
###### Read more [here](https://cdn.intra.42.fr/pdf/pdf/34601/en.subject.pdf)

## 📔 Summary

 - [📺 Preview](#-preview)
 - [🎮 Features](#-features)
 - [📜 Story Mode](#-story-mode)
 - [🧑‍💻 2.5D semi isometric view](#-25d-semi-isometric-view)
 - [📦 Object Generation](#-object-generation)
 - [⚙️ How to run the project ?](#%EF%B8%8F-how-to-run-the-project-)

## 📺 Preview
![alt text](https://github.com/ethan0905/so_long-new-version/blob/master/textures/preview_dialogbox.png?raw=true)

## 🎮 Features
I implemented basic game mechanics that you can find on traditionnal games.  
* Press key to start an event  
* Open a dialog-box  
* Animated sprites
* Inventory
* Life bar
* Intro story

## 📜 Story Mode
I added a story extension if you use a specific map size. You can discover it by playing on `map/piano.ber` :
  
![alt text](https://github.com/ethan0905/so_long-new-version/blob/master/textures/preview_story.png?raw=true)
##### (Press Space to get to the next frame)
  
## 🧑‍💻 2.5D semi isometric view
In this project, I decided to use a 2.5d isometric view.  
In order to create the isometric effect, here are the steps :
* Step 1: I parse my map to get all my elements into a 2 dimensional array of char (char **)  
````shell
1111111111
1000000001
1000000001
1000000001
1000000001
1111111111
````
* Step 2: From last line, I moving up in my array, and for each line I am moving up, I am gonna add one more X at the begining of my line. This has for effect to create my 45 angle view. I finish by completing each of my line with X's in order to get a squared map that will perfectly fit inside my window.
````shell
XXXXX1111111111
XXXX1000000001X
XXX1000000001XX
XX1000000001XXX
X1000000001XXXX
1111111111XXXXX
````
* Step 3: I use this new 2d_map to print my textures at the right place.

## ✏️ How do I print my textures ?
.xpm format does not support transparency. If you are doing a 2d top-view(for example), you can counter this problem by pasting your texture on top of your floor texture. But because of the perspective, I couldn't use this method, so I recode the mlx_put_image_to_window from the minilibx, mlx_pixel_put(), to make it more efficient and faster, to have a really smooth result.
````c
void	my_mlx_pixel_put(t_test *test, int x, int y, int color)
{
	char	*dest;
	dest = test->data.addr + (y * test->data.line_length + x * (test->data.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
````
Then I simply told my algorithm that if it encounters a specific dark pixel (0xFF000000), It does not need to print it.  

## 📦 Object Generation

I managed to generate differents furnitures, depending on how the walls are placed inside the map playable zone.  
[FILL THIS SPACE]  
I also managed to display differents collectibles with pseudo-randomizer algorithm. (Because randomness does'nt really exist)  
[FILL THIS SPACE]  

## ⚙️ How to run the project ?

1. Clone the repository:  
`git clone https://github.com/ethan0905/so_long.git`  
2. Compile the project:  
`make -j`  
3. Run the program:  
`./so_long map/piano.ber`  
4. Enjoy ;)  
