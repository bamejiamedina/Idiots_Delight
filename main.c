#include <stdio.h>
#include <stdlib.h>

double Uniform(double a, double b){
       SelectStream(1);
  return (a + (b - a) * Random());
}

void shuffle(int deck[]){
    int j;
    int r;
    int temp;
    for(j = 0; j < 52; j++){
        r = j + ((int)Uniform(0.0, 52.0) % (52 - j));
        temp = deck[j];
        deck[j] = deck[r];
        deck[r] = temp;
    }
}

int isClubs(int val){

    int clubs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int k;
    int toReturn = 0;

    for(k = 0; k < 13; k++){
        if(clubs[k] == val)
            toReturn = 1;
    }
    return toReturn;
}

int isHearts(int val){

    int hearts[] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
    int k;
    int toReturn = 0;

    for(k = 0; k < 13; k++){
        if(hearts[k] == val)
            toReturn = 1;
    }
    return toReturn;
}

int isDiamonds(int val){

    int diamonds[] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int k;
    int toReturn = 0;

    for(k = 0; k < 13; k++){
        if(diamonds[k] == val)
            toReturn = 1;
    }
    return toReturn;
}

int isSpades(int val){

    int spades[] = {27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int k;
    int toReturn = 0;

    for(k = 0; k < 13; k++){
        if(spades[k] == val)
            toReturn = 1;
    }
    return toReturn;
}

int play(int deck[], int hand[]){
    int i;
    int reference;
    int topCard;
    int cardsInHand = 0;
    int moneyMade = 0;
    int zeroCounter = 0;

    shuffle(deck);

    for(i = 0; i < 52; i++){
        hand[cardsInHand] = deck[i];
        if(cardsInHand >= 3){
            topCard = hand[cardsInHand - 3];
            reference = hand[cardsInHand];
            if((topCard % 13) == (reference % 13)){
                int j;
                for(j = 0; j < 4; j++){
                    hand[cardsInHand - j] = 0;
                }
                cardsInHand = cardsInHand - 4;
                moneyMade = moneyMade + 4;
            }
            else if(isClubs(topCard) && isClubs(reference)){
                hand[cardsInHand - 2] = reference;
                hand[cardsInHand - 1] = 0;
                hand[cardsInHand] = 0;
                cardsInHand = cardsInHand - 2;
                moneyMade = moneyMade + 2;
            }
            else if(isHearts(topCard) && isHearts(reference)){
                hand[cardsInHand - 2] = reference;
                hand[cardsInHand - 1] = 0;
                hand[cardsInHand] = 0;
                cardsInHand = cardsInHand - 2;
                moneyMade = moneyMade + 2;
            }
            else if(isDiamonds(topCard) && isDiamonds(reference)){
                hand[cardsInHand - 2] = reference;
                hand[cardsInHand - 1] = 0;
                hand[cardsInHand] = 0;
                cardsInHand = cardsInHand - 2;
                moneyMade = moneyMade + 2;
            }
            else if(isSpades(topCard) && isSpades(reference)){
                hand[cardsInHand - 2] = reference;
                hand[cardsInHand - 1] = 0;
                hand[cardsInHand] = 0;
                cardsInHand = cardsInHand - 2;
                moneyMade = moneyMade + 2;
            }
        }
        cardsInHand++;
    }
    for(i = 0; i < 52; i++){
        if(hand[i] == 0)
            zeroCounter++;
    }
    if(zeroCounter == 52)
        moneyMade = 10000;

    return moneyMade;
}

int main()
{
    int i;
    int deck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};

    int hand[52] = { 0 };

    for(i = 0; i < 1000; i++){
        printf("%d,", play(deck, hand));
    }
    return 0;
}

