#include <cstdlib>

#include "ai.h"
#include "cordinate.h"


AI::AI()
{

}

Cordinate AI::GetShotPoint()
{
    Cordinate cordinate(false);
    const char horizontalNav[10] = {'A','B','C','D','E','F','G','H','I','J'};
    const int randomHorizontal = std::rand() % 10 + 1;
    const int randomVertical = std::rand() % 10 ;
    cordinate.horizontal = horizontalNav[randomHorizontal];
    cordinate.vertical = randomVertical;
    return cordinate;
}
