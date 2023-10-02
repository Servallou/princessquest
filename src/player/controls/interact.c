#include "setup.h"

extern sfBool event_playerInteract(sfKeyCode keyCode)
{
    if (sfKeyboard_isKeyPressed(keyCode)) {
        return sfTrue;
    }
    return sfFalse;
}