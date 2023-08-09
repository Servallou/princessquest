#ifndef MAIN_H_
    #define MAIN_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include "mob.h"

typedef struct game_s {
    sfRenderWindow *window;
    sfMusic *music;

} game_t;

void movePlayer(mob_t *princess, sfRenderWindow *window);

#endif /* !MAIN_H_ */
