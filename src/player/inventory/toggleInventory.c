#include "inv.h"
#include "lib.h"
#include "game.h"
#include <stdio.h>

static void openInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 255);
}

static void closeInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory->outerBox, 0);
}

extern void getInventory(sfBool *previousKeyState, inv_t *inventory)
{
    sfBool keyState = sfKeyboard_isKeyPressed(sfKeyE);

    if ((!*previousKeyState) && (keyState)) {
        if (inventory->isOpen == NO) {
            openInventory(inventory);
            inventory->isOpen = YES;
            return;
        }
        if (inventory->isOpen == YES) {
            closeInventory(inventory);
            inventory->isOpen = NO;
            return;
        }
    }
    *previousKeyState = keyState;
}