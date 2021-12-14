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
In order to create the isometric effect, I transformed my map:
```
1111111111
1000000001
1000000001
1000000001
1000000001
1111111111
```

```
XXXXX1111111111
XXXX1000000001X
XXX1000000001XX
XX1000000001XXX
X1000000001XXXX
1111111111XXXXX
```
From last line, I

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

## Functionnalities
I implemented basic game mechanics that you can find on traditionnal games.  
* Press key to start an event  
* Open a dialog-box  
* Animated sprites
* Story
