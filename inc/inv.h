#ifndef INV_H_
    #define INV_H_

    #include "setup.h"

typedef struct inv_s {
    enum _isOpen {
        NO,
        YES
    } isOpen;
    sfRectangleShape *outerBox;
    sfRectangleShape *innerBox_1;
    sfRectangleShape *innerBox_2;
    sfRectangleShape *innerBox_3;
    sfRectangleShape *innerBox_4;
    sfTexture *outerBox_texture;
    sfTexture *innerBox;
} inv_t;

void getInventory(sfEvent *event, inv_t *inventory);

#endif /* !INV_H_ */
