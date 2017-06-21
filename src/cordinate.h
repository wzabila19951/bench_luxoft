#ifndef CORDINATE_H
#define CORDINATE_H


struct Cordinate
{
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

    bool operator==(const Cordinate& other) {
        return other.horizontal == horizontal
            && other.vertical == vertical;
    }

    bool IsActive() {
        return State::Active == state || State::Ship == state;
    }
};

#endif // CORDINATE_H
