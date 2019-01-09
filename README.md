# Idiots_Delight
C simulation of Idiot's Delight card game, calculates the money each player would win. Using this information, the hypothetical casino owner can adjust the cost to play the game in order to make an appropriate profit.

Rules for game are as follows:

A conventional 52-card deck is used – four suites, 13 cards per suite. Cards are drawn, one at a time,
from a well-shuffled deck and placed into a hand. The cards in the hand are maintained in the
order they were drawn from the deck. The top card in the hand is the one that is most recently
drawn. The reference card in the hand is the card three positions below the top card.

Each time a card is drawn, it becomes the top card and, if there are 4 or more cards in the hand,
the reference card is defined accordingly. The top card is the compared with the reference card and

(a) if the two cards agree in rank, then the top card, the two between cards, and the reference
card are discarded;
(b) else if the two cards agree in suit, then the two between cards (cards between reference and top card) are discarded;
(c) else no cards are discarded.

When cases (a) or (b) occur, if four or more cards remain after the discard, then a new reference
card is defined accordingly and compared with the top card to see if additional discards are possible.
The game proceeds in this way until all cards have been drawn from the deck and no more discards
from the hand are possible. No discards are possible unless there are at least 4 cards in the hand.
If there are less than 4 cards in the hand then, if possible, additional cards are drawn from the
deck until there are 4 cards in the hand.

For every card discarded, the player is awarded $1. If all cards are discarded (very difficult to do/unlikely), the player is awarded $10,000.
