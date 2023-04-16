#include "card.hpp"

namespace ariel {
    Card::Card(int name, int type){
        if(name>0 && name<14 && type>0 && type<5 ){
        this->Name = name;
        this->type = type;
        }
    };
    
    string Card::toString() const{
        string sNameOfCard;
        string stypeOfCard;
        if(this->Name == 1 ){
         sNameOfCard  = "Ace";
        }
        else if(this->Name == 11 ){
         sNameOfCard  = "Jack";
        }
        else if(this->Name == 12 ){
         sNameOfCard  = "Queen";
        }
        else if(this->Name == 13 ){
          sNameOfCard  = "King";
        }
        else{
            sNameOfCard  = to_string(this->Name);
        }
                

        if(this->type==1){
            stypeOfCard = "Hearts";
        }
        else if(this->type==2){
            stypeOfCard = "Clubs";
        }
        else if(this->type==3){
            stypeOfCard = "Diamonds";
        }
        else if(this->type==4){
            stypeOfCard = "Spades";
        }
        return (sNameOfCard  + " from type- " + stypeOfCard);
    }

}
