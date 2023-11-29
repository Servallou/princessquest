#ifndef INV_H_
    #define INV_H_

    #include "setup.h"
    #include "item.h"


typedef struct inv_s {
    enum _isOpen {
        NO = -1,
        YES = 1
    } isOpen;
    sfRectangleShape *outerBox;
    sfRectangleShape *background;
    sfTexture *outerBox_texture;
    sfTexture *innerBox;
    sfRectangleShape *itemSprite[5];
    item_t slots[5];
} inv_t;

void getInventory(inv_t *inventory);

void initInventory(inv_t *inventory);

#endif /* !INV_H_ */
