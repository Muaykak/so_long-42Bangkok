# so_long-42Bangkok
This is the so_long project from 42Bangkok coding school

Main objective of this project is to create a basic 2D game 
using MiniLibX

## My journey:

### 1. Understand What is **MiniLibX**

I need to understand first what MiniLibX is what how I can use it

After a bit of looking through the internet
MiniLibX is a small graphical library for 42School

<img width="281" alt="Image" src="https://github.com/user-attachments/assets/359bc99c-b1bb-4e2b-9dbf-ed811f0e2979" />

Here is what MiniLibX uses 

  #### X Window System
https://en.wikipedia.org/wiki/X_Window_System

<img width="214" alt="Image" src="https://github.com/user-attachments/assets/d2f00268-658d-4241-835a-dbddfe91bf0b" />

The **MiniLibX** use the Xlib which is the library for Interracting with X Window System
it also provide functions for creating and managing windows, drawing graphics, and handling inputs, 
**miniLibx** is a very small version of Xlib for interacting with X Window System suitable for beginner


Basically the objective is to use function in MiniLibX that project provided to create a basic 2D game that display on screen(obviously lol)

### 2. Understand the **MiniLibX** library

I need to look into the MiniLibX library folder to see how each function is functioning(lol)

After looking into the readme file here

https://github.com/42paris/minilibx-linux?tab=readme-ov-file

This link also consists the requirements that MiniLibX needs

Since I worked on Linux I will Install all the requirements.
After install all the require ment let's look into what minilibx folder contains

#### How to use the MiniLibX Library
To use MiniLibX is very easy you go into the directory of MiniLibX and type

    make

this will create a makefile which create libmlx.a and libmlx_Linux.a so that we can link this library with our project file 

There is also man file to read how each function works but  it's doesn't help much for me 
(Because i'm dumb)
  I saw the test folder let's see what inside
There is a script name run_test.sh 

<img width="234" alt="Image" src="https://github.com/user-attachments/assets/21d95d7a-e268-4042-8ae3-61b9e80bea1d" />

The script will display various things on the screen show colors and also tracking mouse
which I still don't know how all of this works
