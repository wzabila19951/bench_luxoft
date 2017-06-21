#include "ai.h"


AI::AI()
{

}

Cordinate AI::GetShotPoint()
{
    Cordinate cordinate(false);
    char horizontalNav[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int randomHorizontal = std::rand() % 10 + 1;
    int randomVertical = std::rand() % 10 + 1;
    cordinate.horizontal = horizontalNav[randomHorizontal];
    cordinate.vertical = randomVertical;
    return cordinate;
}
