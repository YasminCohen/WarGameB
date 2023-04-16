#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <random>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "game.hpp"

using namespace std;

namespace ariel
{
   Game::Game(Player &playerNum1, Player &playerNum2): p1(playerNum1), p2(playerNum2)
    {
        vector<Card> StackOfcards;
        this->numberOfturn = 0;
        this->numberOfDraws = 0;
        this->HowManyp1Wins = 0;
        this->HowManyp2Wins = 0;
        this->lastStats ="";
        this->log = "";
        p1.setstatus(true);
        p2.setstatus(true);

        int i =1;
        while(i<=13){
            i++;
            StackOfcards.push_back(Card(i, 1));
            StackOfcards.push_back(Card(i, 2));
            StackOfcards.push_back(Card(i, 3));
            StackOfcards.push_back(Card(i, 4));
        
        }

        std::srand(time(nullptr));
        vector<Card>::size_type t = StackOfcards.size() - 1;
        while(t>0)
        {   --t;
            vector<Card>::size_type j = static_cast<std::vector<int>::size_type>(rand()) % (t + 1);
            swap(StackOfcards[t], StackOfcards[j]);
        
        }

        for (int i = 1; i <= 26; i++)
        {
                p1.addCard(StackOfcards.back());
                StackOfcards.pop_back();
        }

        for (int i = 1; i <= 26; i++)
        {
                p2.addCard(StackOfcards.back());
                StackOfcards.pop_back();
        }
        
    }

    void Game::playTurn()
    {
        this->lastStats = "";
        int currnumberOfDraws = 0;
        if (p1.stacksize() == 0 || p2.stacksize() == 0||this->numberOfturn >= 26|| (&p1 == &p2))
         {   throw invalid_argument("error");
         }
        this->numberOfturn++;
        Card &p1OfCard = p1.putCard();
        Card &p2OfCard = p2.putCard();
        int countCardOnTable = 2;
        string numberOfTurns = to_string(this->numberOfturn);
        string card1 = p1OfCard.toString();
        string card2 = p2OfCard.toString();
        string name1 = p1.getName();
        string name2 = p2.getName();
        this->lastStats = "Number of Turns: " + numberOfTurns + ", Player 1: " + name1 + ", Played card: " + card1 + ", Against Player 2: " + name2 + ", Played card: " + card2 + ".";
        bool flag = (p1OfCard.getNameOfCard() == p2OfCard.getNameOfCard());
        while (flag)
        {
            this->lastStats += "Both players have the same card - a draw\n";

            if (p1.stacksize() < 2)
            {
                for(int i =countCardOnTable; i>0; i-=2){
                    p1.addOnCard();
                    p2.addOnCard();
                }
                this->lastStats += "Both players have the same card - a draw\n";

                break;
            }

            p1.putCard();
            p2.putCard();

            p1OfCard = p1.putCard();
            p2OfCard = p2.putCard();

            countCardOnTable = countCardOnTable + 4;
            currnumberOfDraws++;
            card1 = p1OfCard.toString();
            card2 = p2OfCard.toString();
            this->lastStats = "Number of Turns: " + numberOfTurns + ", Player 1: " + name1 + ", Played card: " + card1 + ", Against Player 2: " + name2 + ", Played card: " + card2 + ".";
            
            flag = (p1OfCard.getNameOfCard() == p2OfCard.getNameOfCard());
        }


        if (p1OfCard < p2OfCard)
        {
    
            for(int i =countCardOnTable; i>0; i--){
                    p2.addOnCard();
                }
            this->HowManyp2Wins++;
            this->lastStats += (p2.getName() + " get the Cards" + "\n");
        }

        if (p2OfCard < p1OfCard)
        {

            for(int i =countCardOnTable; i>0; i--){
                p1.addOnCard();
            }
            this->HowManyp1Wins++;
            this->lastStats += (p1.getName() + " get the Cards");
        }

        if (p1.stacksize() == 0)
        {
            p1.setstatus(false);
            this->lastStats += (p1.getName() + " Not in the game anymore");
            p2.setstatus(false);
            this->lastStats += (p2.getName() + "Not in the game anymore");
        }

        this->numberOfDraws = this->numberOfDraws + currnumberOfDraws;
        log += this->lastStats;
    }

    void Game::playAll()
    {
         cout << "play all: " << endl;
        while (p1.stacksize() > 0 && p2.stacksize() > 0)
            playTurn();
    }

    void Game::printWiner() const
    {
        if (p1.stacksize() > 0 || p2.stacksize() > 0){
              cout << "The game is not over yet" << endl;
            return;
        }
        if (p2.cardesTaken() > p1.cardesTaken()){
             cout << "The winner of the war game is " << p2.getName() << endl;
        }
        else if (p1.cardesTaken() > p2.cardesTaken()){
            cout << "The winner of the war game is" << p1.getName() << endl;
        }

        else{
             cout << "The situation is a draw - nobody won" << endl;
        }
    }

    void Game::printStats() const
    {
        double rateof1 = (HowManyp1Wins / numberOfturn);
        double rateof2 = (HowManyp2Wins / numberOfturn);
        double rate = (numberOfDraws  / numberOfturn);

        cout << "nuberOfturns that were: " << this->numberOfturn << "and the numberOfDraws that were:: " << this->numberOfDraws << endl;
        cout << "the draw rate: " << rate << endl;

        cout << p1.getName()  << " earn " << p1.cardesTaken() << " cards , The number of Cards left in the stack: " << p1.stacksize() <<" and the his Win rate is: " << rateof1 << endl;
        cout << p2.getName() << " earn " << p2.cardesTaken() << " cards ,The number of Cards left in the stack: " << p2.stacksize() << " and the his Win rate is: " << rateof2 << endl;

    }
    void Game::printLog() const
    {
        cout << this->log << endl;
    }
    void Game::printLastTurn() const
    {
        cout << this->lastStats << endl;
    }
}
