#include "main.h"

// static void princess_LeftWalk(mob_t *princess, sfIntRect *rect, game_t *game)
// {
//     rect->top = 346;
//     rect->height = 64;
//     if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 0.10f) {
//         if (rect->left == 471) {
//             rect->left = 23;
//         } else {
//             rect->left += 64;
//         }
//         sfSprite_setTextureRect(princess->sprite, *rect);
//         sfClock_restart(game->clock);
//     }
//     printf("%f\n", sfTime_asSeconds(sfClock_getElapsedTime(game->clock)));
// }

// extern void movePlayer(mob_t *princess, game_t *game, struct keyLang_s keyLang)
// {
//     sfIntRect princess_downRect = {
//         19,
//         223,
//         26,
//         62
//     };
//     sfIntRect princess_upRect = {
//         19,
//         149,
//         26,
//         62
//     };
//     sfIntRect princess_leftRect = {
//         23,
//         1,
//         22,
//         62
//     };
//     sfIntRect princess_rightRect = {
//         19,
//         75,
//         22,
//         62
//     };
//     if (sfKeyboard_isKeyPressed(keyLang.w)) {
//         princess->pos.y -= princess->speedMove;
//         sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
//         sfSprite_setTextureRect(princess->sprite, princess_upRect);
//     }
//     if (sfKeyboard_isKeyPressed(keyLang.a)) {
//         princess_LeftWalk(princess, &princess_leftRect, game);
//         princess->pos.x -= princess->speedMove;
//         sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
//     }
//     if (sfKeyboard_isKeyPressed(keyLang.s)) {
//         princess->pos.y += princess->speedMove;
//         sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
//         sfSprite_setTextureRect(princess->sprite, princess_downRect);
//     }
//     if (sfKeyboard_isKeyPressed(keyLang.d)) {
//         princess->pos.x += princess->speedMove;
//         sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
//         sfSprite_setTextureRect(princess->sprite, princess_rightRect);
//     }
//     sfRenderWindow_drawSprite(game->window, princess->sprite, NULL);
// }

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
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.10f) {
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
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.10f) {
        if (area->left == (19 + (64 * 7))) {
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
    area->top = 569;
    area->height = 63;
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.10f) {
        if (area->left == (19 + (64 * 7))) {
            area->left = 19;
        } else {
            area->left += 64;
        }
        sfSprite_setTextureRect(sprite, *area);
        sfClock_restart(clock);
    }
}
