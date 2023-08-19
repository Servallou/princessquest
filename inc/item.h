#ifndef ITEM_H_
    #define ITEM_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct item_s {
    const char *name;
    short quantity;
    short ID;
    sfSprite *sprite;
    sfTexture *texture;
} item_t;

#endif /* !ITEM_H_ */
