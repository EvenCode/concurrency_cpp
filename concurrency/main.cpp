#include "generateQueue.h"
#include <iostream>
#include <thread>
#include <functional>
#include <string>
using namespace std;

int main()
{
	int bSum = 0, cSum = 0;

	generateQueue numbers;

	thread start(&generateQueue::generateNumbers, &numbers);
	start.join();

	while(numbers.checkSize() != 0){
		auto b = thread(&generateQueue::fetchNumber, &numbers, ref(bSum));
		auto c = thread(&generateQueue::fetchNumber, &numbers, ref(cSum));
		b.join();
		c.join();
	}

	if(bSum > cSum)
		cout << "Thread B is the Winner" << endl;
	else if(bSum < cSum)
		cout << "Thread C is the Winner" << endl;
	else
		cout << "Its a Draw" << endl;


return 0;
}