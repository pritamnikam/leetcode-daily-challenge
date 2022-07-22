// conditionVariable

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

using namespace std;

namespace {

	mutex mutex_;
	condition_variable cv_;

	bool dataReady { false };

	void doWork() {
		cout << "Processing shared data." << endl;
	}

	void waitingForWork() {
		cout << "Worker: Waiting for work." << endl;
		unique_lock<mutex> lock(mutex_);
		cv_.wait(lock, [] {return dataReady; });
		doWork();
		cout << "Work done" << endl;
	}

	void setDataReady() {
		{
			std::lock_guard<mutex> lock(mutex_);
			dataReady = true;
		}

		std::cout << "Sender: Data is ready." << std::endl;
		cv_.notify_one();
	}
} // namespace


void testConditionVariable() {
	std::cout << std::endl;

	std::thread t1(waitingForWork);
	std::thread t2(setDataReady);

	t1.join();
	t2.join();

	std::cout << std::endl;
}
