#include "inv.h"
#include <stdio.h>

static void initOuterBox(sfRectangleShape *shape)
{
    sfFloatRect outerBox_localBound;

    sfRectangleShape_setSize(shape, (sfVector2f){2, 0.4});
    sfRectangleShape_setScale(shape, (sfVector2f){400, 400});
    outerBox_localBound = sfRectangleShape_getLocalBounds(shape);
    sfRectangleShape_setOrigin(shape, (sfVector2f){outerBox_localBound.width / 2,
                                                                outerBox_localBound.height / 2});
    sfRectangleShape_setPosition(shape, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfRectangleShape_setOutlineThickness(shape, .01);
    sfRectangleShape_setOutlineColor(shape, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setFillColor(shape, (sfColor){0, 0, 0, 0});
}

static void initBackground(sfRectangleShape *background)
{
    sfRectangleShape_setSize(background, (sfVector2f){1, 1});
    sfRectangleShape_setScale(background, (sfVector2f){WIDTH, HEIGHT});
    sfRectangleShape_setPosition(background, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(background, (sfColor){0, 0, 0, 0});
}

extern void initInventory(inv_t *inventory)
{
    inventory->outerBox = sfRectangleShape_create();
    inventory->background = sfRectangleShape_create();
    inventory->isOpen = NO;
    initOuterBox(inventory->outerBox);
    initBackground(inventory->background);
    printf("inv init\n");
}