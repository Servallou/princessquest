#include "main.h"

extern void movePlayer(mob_t *princess, sfRenderWindow *window, struct keyLang_s keyLang)
{
    sfIntRect princess_downRect = {
        19,
        223,
        26,
        62
    };
    sfIntRect princess_upRect = {
        19,
        149,
        26,
        62
    };
    sfIntRect princess_leftRect = {
        23,
        1,
        22,
        62
    };
    sfIntRect princess_rightRect = {
        19,
        75,
        22,
        62
    };
    if (sfKeyboard_isKeyPressed(keyLang.w)) {
        printf("W %d\n", sfKeyW);
        princess->pos.y -= princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
        sfSprite_setTextureRect(princess->sprite, princess_upRect);
    }
    if (sfKeyboard_isKeyPressed(keyLang.a)) {
        printf("A %d\n", sfKeyA);
        princess->pos.x -= princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
        sfSprite_setTextureRect(princess->sprite, princess_leftRect);
    }
    if (sfKeyboard_isKeyPressed(keyLang.s)) {
        printf("S %d\n", sfKeyS);
        princess->pos.y += princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
        sfSprite_setTextureRect(princess->sprite, princess_downRect);
    }
    if (sfKeyboard_isKeyPressed(keyLang.d)) {
        printf("D %d\n", sfKeyD);
        princess->pos.x += princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
        sfSprite_setTextureRect(princess->sprite, princess_rightRect);
    }
    sfRenderWindow_drawSprite(window, princess->sprite, NULL);
}