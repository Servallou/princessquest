/*
** EPITECH PROJECT, 2023
** princessquest
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_

    #include "setup.h"
    #include "inv.h"

//////
// Input lib :
//////

sfBool isKeyRelease(sfEvent *event, sfKeyCode key);

//////
// Rect lib :
//////

void rect_ModifyAllOpacity(inv_t *inventory, int opacity);

#endif /* !LIB_H_ */
