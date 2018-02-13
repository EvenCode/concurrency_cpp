#include "generateQueue.h"

#define mod3digit 1000

void generateQueue :: generateNumbers(int & signal, int & bSum, int & cSum, int & deathNotice){
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		lock_guard<mutex> lock(mu);
		this->myQueue.push(rand() % mod3digit);
	}
	signal = 1;
	while(deathNotice == 0){
		if(deathNotice == 1){
			if(bSum > cSum)
				cout << "Thread B is the Winner" << endl;
			else if(bSum < cSum)
				cout << "Thread C is the Winner" << endl;
			else
				cout << "Its a Draw" << endl;
			break;
		}
	}
}

void generateQueue :: fetchNumber(int & sum){
	lock_guard<mutex> lock(mu);
	sum += this->myQueue.front();
	this->myQueue.pop();
}

int const generateQueue :: checkSize(){
	return myQueue.size();
}