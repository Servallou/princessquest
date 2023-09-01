#include "inv.h"
#include "lib_rect.h"
#include <stdio.h>

static void openInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 255);
}

static void closeInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 0);
}

extern void getInventory(inv_t *inventory)
{
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        // openInventory(inventory);
        inventory->isOpen = YES;
    }

    printf("fillOpacity %d\n", sfRectangleShape_getFillColor(inventory->outerBox).r);
    printf("outlineOpacity %d\n", sfRectangleShape_getOutlineColor(inventory->outerBox).r);
    // if (inventory->isOpen == YES && sfKeyboard_isKeyPressed(sfKeyE)) {
    //     closeInventory(inventory);
    //     inventory->isOpen = NO;
    // }
    printf("getInventory %d: check\n", inventory->isOpen);
}