#include "main.h"

static void init_game(game_t *game)
{
    sfVideoMode mode = {1280, 720, 32};

    game->window = sfRenderWindow_create(mode, "Princess Quest", sfResize | sfClose, NULL);
    game->music = sfMusic_createFromFile("./resources/audio/loop.ogg");
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
    const sfIntRect area = {0, 0, 60, 60};
    mob_t princess = {
        sfSprite_create(),
        sfTexture_createFromFile("./resources/img/princess.png", &area),
        3.0,
        "princess",
        1.0,
        sfMusic_createFromFile("./resources/audio/test.ogg"),
        0.3,
        PLAYER,
        (sfVector2f){0, 0}
    };
    sfSprite_setScale(princess.sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(princess.sprite, princess.texture, sfTrue);
    init_game(&game);
    if (!game.music)
        return 84;
    while (sfRenderWindow_isOpen(game.window)) {
        sfRenderWindow_setFramerateLimit(game.window, 30);
        while (sfRenderWindow_pollEvent(game.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(game.window);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            break;
        }
        sfRenderWindow_clear(game.window, sfBlack);
        movePlayer(&princess, game.window);
        sfRenderWindow_display(game.window);
    }
    destroy_game(&game);
    destroy_mob(&princess);
	return 0;
}