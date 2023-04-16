#pragma once

#include <vector>
#include "card.hpp"

namespace ariel
{
    class Player
    {
    private:
        int winCards;
        vector<Card> play;
        bool status;
        string name;

    public:
        Player(string name);

        int stacksize() const;

        int cardesTaken() const;

        Card &putCard();

        string getName() const
        {
            return name;
        }

        bool getStatus() const
        {
            return this->status;
        }

        void setstatus(bool status)
        {
            this->status = status;
        }
        void addOnCard();

        string toString() const
        {
            return "The Name of the Player is :" + name + ", in his stack has " + to_string(stacksize()) + " ,and the amount of the Card that he gain is:" + to_string(cardesTaken());
        }

        void addCard(Card &card)
        {
            play.push_back(card);
        }
    };
}