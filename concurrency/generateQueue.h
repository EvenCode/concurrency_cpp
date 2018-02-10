#ifndef GENERATEQUEUE_H
#define GENERATEQUEUE_H
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>
using namespace std;

class generateQueue{
	private:
		mutex mu;
		queue <int> myQueue;
	public:
		void generateNumbers();
		void fetchNumber(int &);
		int const checkSize();
};

#endif