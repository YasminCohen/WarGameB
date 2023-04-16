#pragma once

#include "player.hpp"

namespace ariel
{
    class Game
    {
        private:
            Player &p1, &p2;
            string lastStats, log;
            int numberOfturn, numberOfDraws, HowManyp1Wins, HowManyp2Wins;

        public:
            Game(Player& player1, Player& player2);
            void playTurn();
            void playAll();
            void printLastTurn() const;
            void printLog() const;
            void printWiner() const;
            void printStats() const;
    };
}