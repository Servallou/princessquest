#include "setup.h"

extern sfText *actualVersion(char *string, sfFont *font)
{
    sfText *tmp = sfText_create();

    sfText_setString(tmp, string);
    sfText_setFont(tmp, font);
    sfText_setPosition(tmp, (sfVector2f){10, HEIGHT - 50});
    return tmp;
}