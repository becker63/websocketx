#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/becker/build/wsServer/include/ws.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>


/**
 * @brief This function is called whenever a new connection is opened.
 * @param client Client connection.
 */
void onopen(ws_cli_conn_t *client)
{
    char *cli;
    cli = ws_getaddress(client);
    printf("Connection opened, addr: %s\n", cli);
}

/**
 * @brief This function is called whenever a connection is closed.
 * @param client Client connection.
 */
void onclose(ws_cli_conn_t *client)
{
    char *cli;
    cli = ws_getaddress(client);
    printf("Connection closed, addr: %s\n", cli);
}

/**
 * @brief Message events goes here.
 * @param client Client connection.
 * @param msg    Message content.
 * @param size   Message size.
 * @param type   Message type.
 */
void onmessage(ws_cli_conn_t *client,
    const unsigned char *msg, uint64_t size, int type)
{
    char *cli;
    cli = ws_getaddress(client);
    printf("%s", msg);
    char test;
    test = atoi(msg);

    Display *dpy = XOpenDisplay(0);
    Window root_window;
    root_window = XRootWindow(dpy, 0);
    XSelectInput(dpy, root_window, KeyReleaseMask);
    XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, test, test);
    XFlush(dpy);
    XSync(dpy, False);

    free(test);
}

int main(void)
{
    /* Register events. */
    struct ws_events evs;
    evs.onopen    = &onopen;
    evs.onclose   = &onclose;
    evs.onmessage = &onmessage;

    /*
     * Main loop, this function never* returns.
     *
     * *If the third argument is != 0, a new thread is created
     * to handle new connections.
     */
    ws_socket(&evs, 8080, 0);

    return (0);
}