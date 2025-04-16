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
