/*****************************************************************
* Programmer: Reed Williams, Hunter Koch, Alexis Maria
* Class: CptS 122, Spring 2025; Lab Section 1
* Programming Assignment: PA9
* Date: April 22, 2025
* Description: Content file that will include the definitons for
* the miscFunctions.hpp file.
*****************************************************************/

#include "miscFunctions.hpp"

int randRange(int min, int max)//lowest val is 0
{
    int val = 0;
    do
    {
        val = rand() % (max + 1);
    } while (val < min);
    return val;
}
