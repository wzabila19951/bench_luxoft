#ifndef CORDINATE_H
#define CORDINATE_H


struct Cordinate
{
    Cordinate(const char position_horyzontal, const int position_vertical, const bool is_ship_exist)
        : horizontal(position_horyzontal)
        , vertical(position_vertical)
        , state((is_ship_exist) ? State::Ship : State::Active) {}

    Cordinate(const bool is_ship_exist) {
        state = (is_ship_exist) ? State::Ship : State::Active;
    }

    enum class State {
        Active = 0,
        Ship,
        Shooted,
        Hited
    };

    char horizontal;
    int vertical;
    State state;

    bool operator==(const Cordinate& other) const {
        return other.horizontal == horizontal
            && other.vertical == vertical;
    }

    bool IsActive() const  {
        return State::Active == state || State::Ship == state;
    }
};

#endif // CORDINATE_H
