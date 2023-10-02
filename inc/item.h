#ifndef ITEM_H_
    #define ITEM_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

//////
// Items :
//////

//  Initializations:

enum ITEM_ID
{
    WEAPON,
    UTIL
};

typedef struct item_s {
    const char *name;
    short maxQuantity;
    short ID;
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *shape;
} item_t;

//  Functions :

item_t block(void);

//////
//  Map :
//////

#endif /* !ITEM_H_ */
