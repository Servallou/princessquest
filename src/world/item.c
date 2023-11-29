#include "setup.h"
#include "item.h"

extern item_t block(void)
{
    item_t square = {
        "block",
        5,
        UTIL,
        NULL,
        NULL,
        sfRectangleShape_create()
    };
    sfRectangleShape_setSize(square.shape, (sfVector2f){1, 1});
    sfRectangleShape_setScale(square.shape, (sfVector2f){60, 60});
    sfRectangleShape_setPosition(square.shape, (sfVector2f){47, 288});
    sfRectangleShape_setFillColor(square.shape, (sfColor){255, 255, 0, 255});
    return square;
}
