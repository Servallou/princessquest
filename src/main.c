#include "main.h"

static struct keyLang_s changeLay(char lang)
{
    struct keyLang_s tmp;

    if (lang == 'e') {
        tmp = (struct keyLang_s){
            sfKeyW,
            sfKeyA,
            sfKeyS,
            sfKeyD
        };
    } else {
        tmp = (struct keyLang_s){
            sfKeyZ,
            sfKeyQ,
            sfKeyS,
            sfKeyD
        };
    }
    return tmp;
}

static void init_game(game_t *game)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "Princess Quest", sfResize | sfClose, NULL);
    game->music = sfMusic_createFromFile("./resources/audio/loop.ogg");
    game->clock = sfClock_create();
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, 1);
}

static void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfMusic_destroy(game->music);
}

static void destroy_mob(mob_t *mob)
{
    sfSprite_destroy(mob->sprite);
    sfTexture_destroy(mob->texture);
    sfMusic_destroy(mob->hitSound);
    mob->name = NULL;
}

int main(void)
{
    sfEvent event;
    game_t game;
    struct keyLang_s keyLang;
    char lang = 'e';
    sfFont *font = sfFont_createFromFile("./resources/font/arial.ttf");
    sfText *text = sfText_create();
    sfText *version = sfText_create();
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
    mob_t princess = {
        sfSprite_create(),
        sfTexture_createFromFile("./resources/img/princess.png", NULL),
        3.0,
        "princess",
        1.0,
        sfMusic_createFromFile("./resources/audio/test.ogg"),
        10.5,
        PLAYER,
        (sfVector2f){0, 0}
    };
    sfText_setFont(version, font);
    sfText_setFont(text, font);
    sfText_setString(version, "princessdev0.0.1");
    sfText_setString(text, "En");
    sfText_setPosition(version, (sfVector2f){10, HEIGHT - 50});
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfSprite_setScale(princess.sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(princess.sprite, princess.texture, sfTrue);
    sfSprite_setTextureRect(princess.sprite, princess_downRect);
    init_game(&game);
    while (sfRenderWindow_isOpen(game.window)) {
        sfRenderWindow_setFramerateLimit(game.window, 60);
        sfRenderWindow_clear(game.window, sfBlack);
        while (sfRenderWindow_pollEvent(game.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(game.window);
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
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            break;
        }
        if (sfKeyboard_isKeyPressed(keyLang.a)) {
            princess_leftWalk(princess.sprite, game.clock, &princess_leftRect);
            princess.pos.x -= princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.d)) {
            princess_rightWalk(princess.sprite, game.clock, &princess_rightRect);
            princess.pos.x += princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.s)) {
            princess_downWalk(princess.sprite, game.clock, &princess_downRect);
            princess.pos.y += princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        if (sfKeyboard_isKeyPressed(keyLang.w)) {
            princess_upWalk(princess.sprite, game.clock, &princess_upRect);
            princess.pos.y -= princess.speedMove;
            sfSprite_setPosition(princess.sprite, (sfVector2f){princess.pos.x, princess.pos.y});
        }
        sfRenderWindow_drawText(game.window, text, NULL);
        sfRenderWindow_drawText(game.window, version, NULL);
        sfRenderWindow_drawSprite(game.window, princess.sprite, NULL);
        sfRenderWindow_display(game.window);
    }
    destroy_game(&game);
    destroy_mob(&princess);
    sfText_destroy(text);
    sfText_destroy(version);
    sfFont_destroy(font);
    sfClock_destroy(game.clock);
	return 0;
}

// #include "main.h"

// extern void active_sprite(sfSprite *sprite, sfClock *clock, sfIntRect *area)
// {
//     // *i -= 0.1;
//     // sfSprite_setPosition(sprite, (sfVector2f){*i, 1080 / 2});
//     area->top = 346;
//     area->height = 64;
//     if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.10f) {
//             if (area->left == 471) {
//                 area->left = 23;
//             } else {
//                 area->left += 64;
//             }
//             sfSprite_setTextureRect(sprite, *area);
//             sfClock_restart(clock);
//     }
// }

// int main(void)
// {
//     sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "Bjr", sfResize | sfClose, NULL);
//     sfEvent event;
//     float i = 1800;
//     sfTexture *texture = sfTexture_createFromFile("resources/img/princess.png", NULL);
//     sfSprite *sprite = sfSprite_create();
//     sfSprite_setTexture(sprite, texture, sfTrue);
//     sfIntRect area = {
//         23,
//         1,
//         22,
//         62
//     };
//     sfSprite_setTextureRect(sprite, area);
//     sfSprite_setScale(sprite, (sfVector2f){5, 5});
//     sfClock *clock = sfClock_create();
//     sfSprite_setPosition(sprite, (sfVector2f){i, 1080 / 2});

//     while(sfRenderWindow_isOpen(window)) {
//         while (sfRenderWindow_pollEvent(window, &event)) {
//             if (event.type == sfEvtClosed) {
//                 sfRenderWindow_close(window);
//             }
//         }
//         if (sfKeyboard_isKeyPressed(sfKeyQ)) {
//             active_sprite(sprite, clock, &area, &i);
//         }
//         sfRenderWindow_clear(window, sfBlack);
//         sfRenderWindow_drawSprite(window, sprite, NULL);
//         sfRenderWindow_display(window);
//     }
// }