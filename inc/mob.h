#ifndef MOB_H_
    #define MOB_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

enum ID
{
    PLAYER,
    ENNEMY,
    ALLY
};

typedef struct mob_s {
    sfSprite *sprite;
    sfTexture *texture;
    float healthPoint;
    const char *name;
    float hitPoint;
    sfMusic *hitSound;
    float speedMove;
    int id;
    sfVector2f pos;
} mob_t;

void princess_leftWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area);

void princess_rightWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area);

void princess_upWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area);

void princess_downWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area);

#endif /* !MOB_H_ */
