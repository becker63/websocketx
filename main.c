#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

int main()
{
  Display *dpy = XOpenDisplay(0);
  int it = 0;
  while( it < 100 ) {
    sleep(2);
    it = it + 1;
    Window root_window;
    root_window = XRootWindow(dpy, 0);
    XSelectInput(dpy, root_window, KeyReleaseMask);
    XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, 1, 1);
    XFlush(dpy);
    XSync(dpy, False);
  }
}
