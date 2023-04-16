#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace ariel
{
    class Card
    {
        private:
            int Name, type;

        public:
            Card(int Name = 1, int type = 1);

            int getNameOfCard() const {
                return Name;
            }

            int gettypeOfCard() const {
                return type;
            }

            bool operator<(Card& other) const{
                if (this->Name > 2 && other.Name == 1){
                return true;
                }

                if (this->Name == 1 && other.Name == 2){
                return true;
                }

                return Name < other.Name;
            }

            string toString() const;
    };
}