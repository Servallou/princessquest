#include "main.h"

extern short game(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_setFramerateLimit(game->window, TICK * 600);
        sfRenderWindow_clear(game->window, sfBlack);
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            if (game->event.type == sfEvtClosed) {
                sfRenderWindow_close(game->window);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyP)) {
            lang = 'f';
            sfText_setString(text, "Fr");
        }
        if (sfKeyboard_isKeyPressed(sfKeyO)) {
            lang = 'e';
            sfText_setString(text, "En");
        }
        keyLang = changeLay(lang);
        getInventory(&previousKeyState, &inventory);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            break;
        }
        if (sfKeyboard_isKeyPressed(keyLang.a)) {
            princess_leftWalk(princess.sprite, game->clock, &princess_leftRect);
            princess.pos.x -= princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.d)) {
            princess_rightWalk(princess.sprite, game->clock, &princess_rightRect);
            princess.pos.x += princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.s)) {
            princess_downWalk(princess.sprite, game->clock, &princess_downRect);
            princess.pos.y += princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.w)) {
            princess_upWalk(princess.sprite, game->clock, &princess_upRect);
            princess.pos.y -= princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        sfRenderWindow_drawText(game->window, text, NULL);
        sfRenderWindow_drawText(game->window, version, NULL);
        sfRenderWindow_drawRectangleShape(game->window, itemBlock.shape, NULL);
        drawInventory(game->window, &inventory);
        sfRenderWindow_drawSprite(game->window, princess.sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}