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

	thread b(&generateQueue::fetchNumber, &numbers, ref(bSum), ref(signal));
	thread c(&generateQueue::fetchNumber, &numbers, ref(cSum), ref(signal));
	
	if(b.joinable())
		b.join();
	if(c.joinable())
		c.join();
	
	// As both Threads finish deathNotice tells the Thread (start) that Sum can be compared; 
	deathNotice = 1;

	if(start.joinable())
		start.join();
return 0;
}