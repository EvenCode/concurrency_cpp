#include "generateQueue.h"
#include <iostream>
#include <thread>
#include <functional>
#include <string>
#include <future>
using namespace std;

int main()
{
	int bSum = 0, cSum = 0, signal = 0, deathNotice = 0;

	generateQueue numbers;

	thread start(&generateQueue::generateNumbers, &numbers, ref(signal), ref(bSum), ref(cSum), ref(deathNotice));

	while(1){
		if(numbers.checkSize() != 0)
		{
			auto b = thread(&generateQueue::fetchNumber, &numbers, ref(bSum));
			auto c = thread(&generateQueue::fetchNumber, &numbers, ref(cSum));
			if(b.joinable())	
				b.join();
			if(c.joinable())	
				c.join();
		}
		else if(signal == 1 && numbers.checkSize() == 0){
			deathNotice = 1;
			break;
		}
	}

	if(start.joinable())
		start.join();

	// if(bSum > cSum)
	// 	cout << "Thread B is the Winner" << endl;
	// else if(bSum < cSum)
	// 	cout << "Thread C is the Winner" << endl;
	// else
	// 	cout << "Its a Draw" << endl;

return 0;
}