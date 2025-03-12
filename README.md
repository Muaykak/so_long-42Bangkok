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

Looked in to the main file and try to read and still doesn't help

maybe the main X11 file will help

Okay, There are some manuals to read guys.

<img width="497" alt="Image" src="https://github.com/user-attachments/assets/6350a25d-1ca1-438c-9cb6-81ba832716b5" />

#### Important funcitons

the main need to start with mlx_init() function

    void	*mlx_init()

this function always be the first function to call
  ,if look inside the function

<img width="351" alt="Image" src="https://github.com/user-attachments/assets/732bf9b0-7769-4c58-bae2-bbb50e9e4ba9" />

This function is first allocate the **t_xvar** variable. Which contain many attributes to use.

  As you can see after it allocates, each attributes of this **t_xvar** variable get its value from the functions like **XOpenDisplay**, **DefaultScreen**, etc.. . 

These functions are the function from X11 Xlib library 

  this function use the **XOpenDisplay** function. if i look into the pdf file of Xlib

  <img width="797" alt="Image" src="https://github.com/user-attachments/assets/3efea2ac-02d0-4f07-a034-4b4e93b9682e" />

Also if we look into the manual it will be a little bit more understandable

<img width="1110" alt="Image" src="https://github.com/user-attachments/assets/12b0ca92-1a4f-47f3-aad8-833916d82437" />

So, te **mlx_init()** is the function that need to calls to establish the connection with the X-Server


Okay, Now I think If I have to read all the documents it won't be enough time for me to even wrote a single program out of this in 1 month lol

I saw Oceano video on YouTube i Hope it may help

https://youtu.be/bYS93r6U0zg?si=KvcrR5ekXwxjGz6w

It Does help me understand this project a bit more

The next function after we open is we also need to close right?

yeah 

    int	mlx_destroy_display(t_xvar *xvar)
    {
	    XCloseDisplay(xvar->display);
    }

see? open then close, should be easy right? (My Dumb mode has opened lol)





