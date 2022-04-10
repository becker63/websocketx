#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main(int argc, char *argv[]){

     Display *dpy;
     Window root_window;

     dpy = XOpenDisplay(0);

     root_window = XRootWindow(dpy, 0);

     int i = 0;
     int x = 180;
     while (i < 5) {
     printf("\n\n");
     i++;
     x = x + 50;

     int useconds = 500000;
     usleep(useconds); 
     
     XSelectInput(dpy, root_window, KeyReleaseMask);

     XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, x, 500);

     XGrabPointer(dpy, root_window, True, ButtonPressMask, GrabModeAsync,GrabModeAsync, None, None, CurrentTime);

     XFlush(dpy);
     }
    return 0;
  }