#ifndef MAIN_H_
    #define MAIN_H_

    #include "setup.h"
    #include <stdio.h>
    #include "mob.h"
    #include "inv.h"

    #define WIDTH 1920
    #define HEIGHT 1080

typedef struct game_s {
    sfRenderWindow *window;
    sfMusic *music;
    sfClock *clock;
    sfEvent event;
} game_t;

struct keyLang_s {
    int w;
    int a;
    int s;
    int d;
};

void movePlayer(mob_t *princess, game_t *game, struct keyLang_s);

#endif /* !MAIN_H_ */
