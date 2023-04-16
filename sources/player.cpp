#include "player.hpp"

namespace ariel {
    Player::Player(string name) {
        this->name = name;
        this->winCards = 0;
        this->status = false;
    }

    Card& Player::putCard() {
        Card& ret = this->play.back();
        this->play.pop_back();
        return ret;
    }
    int Player::stacksize() const {
        return (int)play.size();
    }
    int Player::cardesTaken() const{
        return winCards;
    }
    void Player::addOnCard() {
        winCards++;
    }

}