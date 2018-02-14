#include "generateQueue.h"

#define mod3digit 1000

void generateQueue :: generateNumbers(int & signal, int & bSum, int & cSum, int & deathNotice){
	srand(time(NULL));
	for(int i = 0; i < 100; i++){
		unique_lock<mutex> lock(mu);
		this->myQueue.push(rand() % mod3digit);
		lock.unlock();
	}
	signal = 1;
	while(deathNotice == 0){
		continue;
	}

	if(deathNotice == 1){
		if(bSum > cSum)
			cout << "Thread B is the Winner" << endl;
		else if(bSum < cSum)
			cout << "Thread C is the Winner" << endl;
		else
			cout << "Its a Draw" << endl;
	}
}

void generateQueue :: fetchNumber(int & sum, int & signal){
	while(1){
		unique_lock<mutex> lock(mu);
		if(this->checkSize() != 0){
			sum += this->myQueue.front();
			this->myQueue.pop();
		}
		else if(signal == 1){
			lock.unlock();
			break;
		}
		else{
			continue;
		}
		lock.unlock();
	}
}

int const generateQueue :: checkSize(){
	return myQueue.size();
}