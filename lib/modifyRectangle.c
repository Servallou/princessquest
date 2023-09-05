#include "setup.h"
#include <stdio.h>

extern void rect_ModifyAllOpacity(sfRectangleShape *rect, int opacity)
{
    sfColor fillColor = sfRectangleShape_getFillColor(rect);
    sfColor outlineColor = sfRectangleShape_getOutlineColor(rect);

    fillColor.a = opacity;
    outlineColor.a = opacity;
    sfRectangleShape_setFillColor(rect, fillColor);
    sfRectangleShape_setOutlineColor(rect, outlineColor);
}