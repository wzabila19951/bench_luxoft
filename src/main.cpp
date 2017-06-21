#include <iostream>

#include "lifecycle.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    LifeCycle game;
    game.play();

    return 0;
}
