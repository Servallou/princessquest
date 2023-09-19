#include "inv.h"

extern void initInventory(inv_t *inventory)
{
    inventory->outerBox = sfRectangleShape_create();
    inventory->isOpen = NO;
    sfFloatRect outerBox_localBound;

    sfRectangleShape_setSize(inventory->outerBox, (sfVector2f){2, 0.4});
    sfRectangleShape_setScale(inventory->outerBox, (sfVector2f){400, 400});
    outerBox_localBound = sfRectangleShape_getLocalBounds(inventory->outerBox);
    sfRectangleShape_setOrigin(inventory->outerBox, (sfVector2f){outerBox_localBound.width / 2,
                                                                outerBox_localBound.height / 2});
    sfRectangleShape_setPosition(inventory->outerBox, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfRectangleShape_setOutlineThickness(inventory->outerBox, .01);
    sfRectangleShape_setOutlineColor(inventory->outerBox, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setFillColor(inventory->outerBox, (sfColor){0, 0, 0, 0});
}