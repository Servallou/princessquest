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

static void initGame(game_t *game)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    game->window = sfRenderWindow_create(mode, "Princess Quest", sfResize | sfClose, NULL);
    game->music = sfMusic_createFromFile("./resources/audio/loop.ogg");
    game->clock = sfClock_create();
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, 1);
}

static void initInventory(inv_t *inventory)
{
    inventory->innerBox_1 = sfRectangleShape_create();
    inventory->innerBox_2 = sfRectangleShape_create();
    inventory->innerBox_3 = sfRectangleShape_create();
    inventory->innerBox_4 = sfRectangleShape_create();
    inventory->outerBox = sfRectangleShape_create();
    inventory->isOpen = NO;
    sfRectangleShape_setOutlineColor(inventory->outerBox, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setFillColor(inventory->outerBox, (sfColor){255, 255, 255, 0});
    sfRectangleShape_setOutlineThickness(inventory->outerBox, 1.0);
    sfRectangleShape_setOrigin(inventory->outerBox, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfRectangleShape_setScale(inventory->outerBox, (sfVector2f){2, 4});
    printf("init_inventory : check\n");
}

static void drawInventory(sfRenderWindow *window, inv_t *inventory)
{
    sfRenderWindow_drawRectangleShape(window, inventory->outerBox, NULL);
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
    game_t game;
    inv_t inventory;
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
        8.5,
        PLAYER,
        (sfVector2f){WIDTH / 2, HEIGHT / 2}
    };
    sfText_setFont(version, font);
    sfText_setFont(text, font);
    sfText_setString(version, "princessdev0.0.2");
    sfText_setString(text, "En");
    sfText_setPosition(version, (sfVector2f){10, HEIGHT - 50});
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfSprite_setScale(princess.sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(princess.sprite, princess.texture, sfTrue);
    sfSprite_setTextureRect(princess.sprite, princess_downRect);
    sfSprite_setPosition(princess.sprite, princess.pos);
    sfSprite_setOrigin(princess.sprite, (sfVector2f){26 / 2, 62 / 2});
    initGame(&game);
    initInventory(&inventory);
    while (sfRenderWindow_isOpen(game.window)) {
        sfRenderWindow_setFramerateLimit(game.window, 60);
        sfRenderWindow_clear(game.window, sfBlack);
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            if (game.event.type == sfEvtClosed) {
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
        getInventory(&inventory);
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
        drawInventory(game.window, &inventory);
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
