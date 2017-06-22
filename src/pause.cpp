#include <ctime>
#include "pause.h"
#include "playerturn.h"


Pause::Pause(const Drawer& in_drawer) : drawer(in_drawer)
{

}

Pause::~Pause()
{

}

char Pause::getId() const
{
    return 's';
}

Cordinate Pause::MakeTurn()
{
    const clock_t start = clock();
    Cordinate a(false);
    drawer.ClearView();
    drawer.DrawText("Pause");
    drawer.DrawStatistic();
    scanf(" %c", &a);
    const float duration = static_cast<float>(clock() - start) / 100;
    std::cout<< duration << std::endl;
 return a;
}

void Pause::Next(GameState* out_state)
{
    delete out_state;
    out_state = new PlayerTurn();
}
