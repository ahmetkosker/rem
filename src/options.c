#include <stdio.h>

unsigned char flags()
{
    unsigned char Enable_Nothing = 0;
    unsigned char Enable_Color = 1;
    unsigned char Enable_Case_Sensitive = 2;
    unsigned char Enable_Line_Number = 3;
    unsigned char flags;
    if (Enable_Nothing)
        return flags = Enable_Nothing;
    else if (Enable_Color)
        return flags = Enable_Color;
    else if (Enable_Color & Enable_Case_Sensitive)
        return flags = Enable_Nothing | Enable_Color | Enable_Case_Sensitive;
    else if (Enable_Color & Enable_Case_Sensitive & Enable_Line_Number)
        return flags = Enable_Color | Enable_Case_Sensitive | Enable_Line_Number;
}
