#ifndef MAIN_H_
    #define MAIN_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include "mob.h"

    #define WIDTH 1920
    #define HEIGHT 1080

typedef struct game_s {
    sfRenderWindow *window;
    sfMusic *music;

} game_t;

struct keyLang_s {
    int w;
    int a;
    int s;
    int d;
};

void movePlayer(mob_t *princess, sfRenderWindow *window, struct keyLang_s);

#endif /* !MAIN_H_ */
