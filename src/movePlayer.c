#include "main.h"

extern void movePlayer(mob_t *princess)
{
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        printf("W %d\n", sfKeyW);
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        printf("A %d\n", sfKeyA);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        printf("S %d\n", sfKeyS);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        printf("D %d\n", sfKeyD);
    }
}