# so_long
## Subject
You must create a small 2D game where a dolphin
escapes earth after eating some fish. Or any hero
collects any valuables before leaving the place.
You will use 2d view (top-down or profile)
###### Read more [here](https://cdn.intra.42.fr/pdf/pdf/34601/en.subject.pdf)

## Preview
![alt text](https://github.com/ethan0905/so_long-new-version/blob/master/textures/preview_dialogbox.png?raw=true)

## Map parsing
In this project, I decided to use a 2d isometric view.  
In order to create the isometric effect, here are the steps :
* Step 1: I parse my map to get all my elements into a 2 dimensional array of char (char **)  
```
1111111111
1000000001
1000000001
1000000001
1000000001
1111111111
```
* Step 2: From last line, I moving up in my array, and for each line I am moving up, I am gonna add one more X at the begining of my line.  
This has for effect to create my 45 angle view. I finish by completing each of my line with X's in order to get a squared map that will perfectly fit  
inside my window.
```
XXXXX1111111111
XXXX1000000001X
XXX1000000001XX
XX1000000001XXX
X1000000001XXXX
1111111111XXXXX
```
* Step 3: I use this new 2d_map to print my textures in the right place.

## How do I print my textures ?
Printing images directly by using mlx_put_image_to_window() function from the minilibx is from far easier, but the .xpm format does not  
support the transparency. If you are doing a 2d top-view(for example), you can counter this problem by pasting your texture on top of your floor  
texture. But because of the perspective, I couldnt use this method, so I managed to recode a function from the minilibx, mlx_pixel_put(), to  
make it more efficient and faster, to have a really smooth result.  

void	my_mlx_pixel_put(t_test *test, int x, int y, int color)
{
	char	*dest;

	dest = test->data.addr + (y * test->data.line_length + x * (test->data.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

## Functionnalities
I implemented basic game mechanics that you can find on traditionnal games.  
* Press key to start an event  
* Open a dialog-box  
* Animated sprites
* Inventory
* Life bar
* Intro story

I managed to generate differents furnitures, depending on how the walls are placed inside the map playable zone.  

I also managed to display differents collectibles with pseudo-randomizer algorithm. (Because randomness does'nt really exist)  

## Story
I added a story extension if you use a specific map size. You can discover it by copy pasting this map size sample :
```
111111111111
1011101C11T1
1T00000000C1
1000000CC001
1P01100000E1
111111111111
```
![alt text](https://github.com/ethan0905/so_long-new-version/blob/master/textures/preview_story.png?raw=true)
##### (Press Space to get to the next frame)
