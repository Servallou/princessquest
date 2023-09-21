#include "inv.h"

extern void rect_ModifyAllOpacity(inv_t *inventory, int opacity)
{
    sfColor fillColor = sfRectangleShape_getFillColor(inventory->outerBox);
    sfColor background_fillColor = sfRectangleShape_getFillColor(inventory->background);
    sfColor outlineColor = sfRectangleShape_getOutlineColor(inventory->outerBox);

    fillColor.a = opacity;
    background_fillColor.a = 150;
    outlineColor.a = opacity;
    sfRectangleShape_setFillColor(inventory->outerBox, fillColor);
    sfRectangleShape_setOutlineColor(inventory->outerBox, outlineColor);
    sfRectangleShape_setFillColor(inventory->background, background_fillColor);
}