#ifndef GENERATEQUEUE_H
#define GENERATEQUEUE_H
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <future>
using namespace std;

class generateQueue{
	private:
		mutex mu;
		queue <int> myQueue;
	public:
		void generateNumbers(int &, int &, int &, int &);
		void fetchNumber(int &, int &);
		int const checkSize();
};

#endif