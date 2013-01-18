/*NAME: Andrew Duberstein
 *DATE: 01-22-2013
 *CSE 471 Assignment #1
 */

#include <iostream>
#include <stdlib.h>
using namespace std;


static const int kCostPerFlip = 1;
static const int kJackpot = 8;
static const int kStartingCash = 9;
static const int kDaysOfPlay = 1000;
static const int kStoppingDifference = 3;

int main(){
	int current_cash, num_heads, num_heads, current_net_gain, coin, diff_heads;
	//TODO name
	int daily_take_home = 0;
	//sum_net_gain - the number of net gains over kDaysOfPlay trials if current_net_gain = 5
	int count_five_net_gain = 0;
	//sum_net_gain - the number of net gains over kDaysOfPlay trials if current_net_gain = 3
	int count_three_net_gain = 0;
	int heads_tails_difference = 0;
	for(int days = 0; days < kDaysOfPlay; days++){
		current_cash = kStartingCash;
		num_heads = 0;
		num_tails = 0;
		do{	
			current_net_gain -= kCostPerFlip;
			coin = rand() % 2;
			(coin == 0 ? num_heads : num_tails) += 1;
			diff_heads = num_heads - num_tails;
			if(diff_heads >= kStoppingDifference){
				current_net_gain+=8;
				break;
			}
			current_cash += current_net_gain;
			switch(current_net_gain){
				case 3:
					count_five_net_gain += 1;
					break;
				case 5:
					count_three_net_gain += 1;
					break;
				default:
					break;
			}
		}while(current_cash > 0);
		daily_take_home += current_cash;
	}
	//The probability of a net gain of $5 is equal to # of games resulting in a net gain of five dollars divided by kDaysOfPlay
	//The probability of a net gain of $3 is equal to # of games resulting in a net gain of three dollars divided by kDaysOfPlay
	//The average daily net gain is equal to the sum of the net gain divided by kDaysOfPlay
	return 0;
}