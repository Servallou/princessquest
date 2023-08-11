#include "main.h"

extern void movePlayer(mob_t *princess, sfRenderWindow *window, struct keyLang_s keyLang)
{
    if (sfKeyboard_isKeyPressed(keyLang.w)) {
        printf("W %d\n", sfKeyW);
        princess->pos.y -= princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
    }
    if (sfKeyboard_isKeyPressed(keyLang.a)) {
        printf("A %d\n", sfKeyA);
        princess->pos.x -= princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
    }
    if (sfKeyboard_isKeyPressed(keyLang.s)) {
        printf("S %d\n", sfKeyS);
        princess->pos.y += princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
    }
    if (sfKeyboard_isKeyPressed(keyLang.d)) {
        printf("D %d\n", sfKeyD);
        princess->pos.x += princess->speedMove;
        sfSprite_setPosition(princess->sprite, (sfVector2f){princess->pos.x, princess->pos.y});
    }
    sfRenderWindow_drawSprite(window, princess->sprite, NULL);
}