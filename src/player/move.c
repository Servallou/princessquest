#include "main.h"

extern void princess_leftWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area)
{
    area->top = 346;
    area->height = 64;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.10f) {
        if (area->left == (23 + (64 * 7))) {
            area->left = 23;
        } else {
            area->left += 64;
        }
        sfSprite_setTextureRect(sprite, *area);
        sfClock_restart(clock);
    }
}
extern void princess_rightWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area)
{
    area->top = 420;
    area->height = 64;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > TICK) {
        if (area->left == (19 + (64 * 7))) {
            area->left = 19;
        } else {
            area->left += 64;
        }
        sfSprite_setTextureRect(sprite, *area);
        sfClock_restart(clock);
    }
}
extern void princess_upWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area)
{
    area->top = 494;
    area->height = 63;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > TICK) {
        if (area->left == 467) {
            area->left = 19;
        } else {
            area->left += 64;
        }
        sfSprite_setTextureRect(sprite, *area);
        sfClock_restart(clock);
    }
}
extern void princess_downWalk(sfSprite *sprite, sfClock *clock, sfIntRect *area)
{
    area->top = 568;
    area->height = 63;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > TICK) {
        if (area->left == (19 + (64 * 7))) {
            area->left = 19;
        } else {
            area->left += 64;
        }
        sfSprite_setTextureRect(sprite, *area);
        sfClock_restart(clock);
    }
}
