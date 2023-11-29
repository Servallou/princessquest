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

extern void getInventory(inv_t *inventory)
{
    if (inventory->isOpen == YES) {
        openInventory(inventory);
        return;
    }
    if (inventory->isOpen == NO) {
        closeInventory(inventory);
        return;
    }
}
