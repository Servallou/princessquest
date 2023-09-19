#ifndef GAME_H_
    #define GAME_H_

    #include "setup.h"

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



#endif /* !GAME_H_ */
