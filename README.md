### GoPro API

Based on KonradIT's work (https://github.com/KonradIT).
Tested with GoPro Hero 5 Session.

## Status
- 2 - Battery Level
4=Charging
3=Full
2=Halfway
1=Low
0=Empty

<!-- status 8 and 19 have something to do with Bluetooth -->
- 40 - Current Date
e.g. %14%0B%0B%0C%39%19 -> 14=(20)20, 0b=Nov, 0b=11, 0c=12h, 39=57m, 19=25s
<!-- status 43 -->
<!-- status 44  submode -->

- 45 -> Locate 
1=ON, 0=OFF
<!-- status 54 space remaining -->
<!--- status 57 -> timer? -->

## Settings

# Video Mode
- 2 - Video Resolution 
1=4k, 
4=2.7k, 
6=2.7k 4:3,
7=1440,
9=1080, 
10=960, 
12=720

- 3 - FPS 
10=24fps 
9=25fps, 
8=30fps (NTSC only),
7=48fps, 
6=50fps, 
3=90fps

<!-- interplays with 3, resets 57 -->
- 3 - Video Format 
8=NTSC,
9=PAL

- 9 - Spot Meter 
1=ON, 
0=OFF

- 10 - Protune 
1=ON, 
0=OFF

- 89 - Default Mode 
12=VIDEO, 
17=PHOTO

# Photo Mode
- 17 - Megapixels 
11=10MP linear,
4=10MP wide

- 19 - Shutter Exposure
0=AUTO
1=2sec
2=5sec

- 20 - Spot Meter
- 21 - Protune
- 52 - Autorotation 
1=UP, 
2=DOWN, 
0=AUTO

- 78 - Video Stabilization
1=ON, 
0=OFF

- 86 - Voice Control
1=ON, 
0=OFF

- 87 - beep volume 
0=MUTE,
40=LOW, 
70=MED, 
100=HIGH

- 91 - LED
2=ON, 
1=FRONT ON,
0=OFF
