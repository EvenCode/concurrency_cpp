#include "generateQueue.h"

#define mod3digit 1000

void generateQueue :: generateNumbers(int & signal){
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		lock_guard<mutex> lock(mu);
		this->myQueue.push(rand() % mod3digit);
	}
	signal = 1;
}

void generateQueue :: fetchNumber(int & sum){
	lock_guard<mutex> lock(mu);
	sum += this->myQueue.front();
	this->myQueue.pop();
}

int const generateQueue :: checkSize(){
	return myQueue.size();
}