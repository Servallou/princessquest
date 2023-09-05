#include "setup.h"

extern sfBool isKeyRelease(sfEvent *event, sfKeyCode key)
{
    if (event->type == sfEvtKeyReleased && event->key.code == key) {
        return sfTrue;
    }
    return sfFalse;
}