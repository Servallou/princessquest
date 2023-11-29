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

static void drawInventory(sfRenderWindow *window, inv_t *inventory)
{
    sfRenderWindow_drawRectangleShape(window, inventory->background, NULL);
    sfRenderWindow_drawRectangleShape(window, inventory->outerBox, NULL);
    // if (inventory->itemSprite[0] != NULL)
    //     sfRenderWindow_drawRectangleShape(window, inventory->itemSprite[0], NULL);
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

static void transferItemToInv(sfRectangleShape *itemToTransfer, inv_t *inv)
{
    printf("test\n");
    inv->itemSprite[0] = sfRectangleShape_copy(itemToTransfer);
    sfRectangleShape_setPosition(inv->itemSprite[0], (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(inv->itemSprite[0], (sfColor){255, 255, 0, 0});
}

int main(void)
{
    game_t game;
    inv_t inventory;
    struct keyLang_s keyLang;
    char lang = 'f';
    sfBool previousKeyState = sfFalse;
    item_t itemBlock = block();
    sfFont *font = sfFont_createFromFile("./resources/font/arial.ttf");
    sfText *text = sfText_create();
    sfText *version = actualVersion("princessdev0.0.2_2", font);
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
    sfText_setFont(text, font);
    sfText_setString(text, "Fr");
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfSprite_setScale(princess.sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(princess.sprite, princess.texture, sfTrue);
    sfSprite_setTextureRect(princess.sprite, princess_downRect);
    sfSprite_setPosition(princess.sprite, princess.pos);
    sfSprite_setOrigin(princess.sprite, (sfVector2f){26 / 2, 62 / 2});
    initGame(&game);
    initInventory(&inventory);
    while (sfRenderWindow_isOpen(game.window)) {
        sfRenderWindow_setFramerateLimit(game.window, TICK * 600);
        sfRenderWindow_clear(game.window, sfBlack);
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            if (game.event.key.code == 'e') {
                if (inventory.isOpen == NO) {
                    inventory.isOpen = YES;
                } else {
                    inventory.isOpen = NO;
                }
            }
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
        printf("%d\n", inventory.isOpen);
        getInventory(&inventory);
        drawInventory(game.window, &inventory);
        keyLang = changeLay(lang);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            break;
        }
        // if (sfKeyboard_isKeyPressed(sfKeyF)) {
        //     transferItemToInv(itemBlock.shape, &inventory);
        //     itemBlock.shape = NULL;
        // }
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
        // if (itemBlock.shape != NULL)
        //     sfRenderWindow_drawRectangleShape(game.window, itemBlock.shape, NULL);
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
