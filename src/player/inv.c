#include "inv.h"
#include "lib.h"
#include <stdio.h>

static void openInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 255);
}

static void closeInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 0);
}

extern void getInventory(sfEvent *event, inv_t *inventory)
{
    int isOpen = inventory->isOpen;

    if (inventory->isOpen == NO && sfKeyboard_isKeyPressed(sfKeyE)) {
        openInventory(inventory);
        inventory->isOpen = YES;
    }
    if (isOpen == YES && sfKeyboard_isKeyPressed(sfKeyR)) {
        closeInventory(inventory);
        inventory->isOpen = NO;
    }
    printf("fillOpacity %d\n", sfRectangleShape_getFillColor(inventory->outerBox).a);
    printf("outlineOpacity %d\n", sfRectangleShape_getOutlineColor(inventory->outerBox).a);
    printf("getInventory %d: check\n", inventory->isOpen);
}