#include "inv.h"
#include "lib.h"
#include "game.h"
#include <stdio.h>

static void openInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory, 255);
}

static void closeInventory(inv_t *inventory)
{
    rect_ModifyAllOpacity(inventory, 0);
}

extern void getInventory(sfBool *previousKeyState, inv_t *inventory)
{
    sfBool keyState = sfKeyboard_isKeyPressed(sfKeyE);

    // if ((*previousKeyState == sfFalse) && (keyState == sfTrue)) {
        if (inventory->isOpen == NO && sfKeyboard_isKeyPressed(sfKeyE)) {
            openInventory(inventory);
            inventory->isOpen = YES;
            return;
        }
        if (inventory->isOpen == YES && sfKeyboard_isKeyPressed(sfKeyR)) {
            closeInventory(inventory);
            inventory->isOpen = NO;
            return;
        }
    // }
    // *previousKeyState = keyState;
}