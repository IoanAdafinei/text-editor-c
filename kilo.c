/*** includes ***/
#include "includes.h"

#include "data.h"
#include "defines.h"
#include "terminal.h"
#include "append_buffer.h"
#include "output.h"
#include "input.h"
#include "file_io.h"
#include "rowoperations.h"
#include "editoroperations.h"
#include "prototypes.h"
#include "find.h"
#include "filetypes.h"
#include "syntaxhighlight.h"

/*** defines ***/

// #include "defines.h";

/*** data ***/

// #include "data.h";

/*** terminal ***/
// #include "terminal.h"

/*** append buffer ***/

/*** output ***/

/*** input ***/

/*** init ***/

void initEditor()
{
    E.cx = 0;
    E.cy = 0;
    E.rx = 0;
    E.rowoff = 0;
    E.coloff = 0;
    E.numrows = 0;
    E.row = NULL;
    E.dirty = 0;
    E.filename = NULL;
    E.statusmsg[0] = '\0';
    E.statusmsg_time = 0;
    E.syntax = NULL;

    if (getWindowSize(&E.screenrows, &E.screencols) == -1)
        die("getWindowSize");
    E.screenrows -= 2;
}

int main(int argc, char *argv[])
{
    enableRawMode();
    initEditor();
    if (argc >= 2)
    {
        editorOpen(argv[1]);
    }

    editorSetStatusMessage(
        "HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");

    while (1)
    {
        editorRefreshScreen();
        editorProcessKeypress();
    }

    return 0;
}