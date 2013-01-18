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

//Credit to http://www.cplusplus.com/forum/articles/7312/ for this "Press ENTER to continue" boilerplate
void PressEnterToContinue()
{
	int c;
	printf( "Press ENTER to continue... " );
	fflush( stdout );
	do 
		c = getchar(); 
	while ((c != '\n') && (c != EOF));
}

int main(){
	for (int i = 1; i < 11; i++){
		int current_cash, num_heads, num_tails, coin, diff_heads;
		//total_take_home - the total earnings over kDaysOfPlay days
		int total_take_home = 0;
		//sum_net_gain - the number of net gains over kDaysOfPlay trials if take-home = 5
		int count_five_net_gain = 0;
		//sum_net_gain - the number of net gains over kDaysOfPlay trials if take-home = 3
		int count_three_net_gain = 0;
		int heads_tails_difference = 0;
		for(int days = 0; days < kDaysOfPlay; days++){
			bool continue_game = true;
			current_cash = kStartingCash;
			num_heads = 0;
			num_tails = 0;
			do{	
				current_cash -= kCostPerFlip;
				coin = rand() % 2;
				(coin == 0 ? num_heads : num_tails) += 1;
				diff_heads = num_heads - num_tails;
				if(diff_heads == kStoppingDifference){
					current_cash += kJackpot;
					continue_game = false;
				}
			}while(continue_game && current_cash > 0);
			total_take_home += current_cash;
			if(current_cash - kStartingCash == 3)
					count_three_net_gain += 1;
			else if (current_cash - kStartingCash == 5)
					count_five_net_gain += 1;
			else
				;//do nothing
		}
		//The average daily net gain is equal to the sum of the net gain divided by kDaysOfPlay
		cout << "Average daily take-home: ";
		cout << (double) total_take_home / kDaysOfPlay << std::endl;
		//The probability of a net gain of $5 is equal to # of games resulting in a net gain of five dollars divided by kDaysOfPlay
		cout << "Probability of a net gain of $5: ";
		cout << (double) count_five_net_gain / kDaysOfPlay << std::endl;
		//The probability of a net gain of $3 is equal to # of games resulting in a net gain of three dollars divided by kDaysOfPlay
		cout << "Probability of a net gain of $3: ";
		cout << (double) count_three_net_gain / kDaysOfPlay << std::endl;
	}
	PressEnterToContinue();
	return 0;
}