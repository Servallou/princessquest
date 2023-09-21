#ifndef INV_H_
    #define INV_H_

    #include "setup.h"

typedef struct inv_s {
    enum _isOpen {
        NO,
        YES
    } isOpen;
    sfRectangleShape *outerBox;
    sfRectangleShape *background;
    sfTexture *outerBox_texture;
    sfTexture *innerBox;
} inv_t;

void getInventory(sfBool *previousKeyState, inv_t *inventory);

void initInventory(inv_t *inventory);

#endif /* !INV_H_ */
