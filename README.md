CoinTossGamblingGame
================
In this game, the player repeatedly flips a fair coin until the difference between the number of heads and the number of tails is three.  The player must pay $1 for each flip of the coin and he receives $8 when a difference of three is obtained. Each day the player sets aside $9 to play and continues playing this game until either (a) he loses all of the money he set aside for that day or (b) he completes a game and receives $8.

This program simulates 1000 days of play and estimates the following:
- The probability of a net gain of $5
- The probability of a net gain of $3
- The average daily net gain

It prints the results of 10 independent runs (each run is a 1,000 day
simulation). Native pseudorandom number generators simulate coin flips.

Adapted from a project for my simulations class at Miami University of Ohio.
