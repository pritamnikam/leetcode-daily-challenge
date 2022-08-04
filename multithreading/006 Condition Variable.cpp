#include <iostream>
#include <thread>
#include <mutex>
#include <deque>


using namespace std;

/*
Synchronized the execution of threads condition variables are used.
*/

namespace {
	std::deque<int> q;
	std::mutex mt;
	std::condition_variable cond;

	void producer() {
		int count = 10;
		while (count > 0) {
			std::unique_lock<mutex> locker(mt);
			q.push_front(count);
			locker.unlock();
			std::this_thread::sleep_for(chrono::seconds(1));
			count--;
		}
	}


	// this leads to a busy-waiting - very inefficient way 
	void consumer() {
		int data = 0;
		while (data != 1) {
			std::unique_lock<mutex> locker(mt);
			if (!q.empty()) {
				data = q.back();
				q.pop_back();
				locker.unlock();

				cout << "t2 got a value from t1: " << data << endl;
			}
			else {
				locker.unlock();

				// opetion 1: if queue is empty we let the thread to take a nap and then go to the next loop
				// this will solve the busy
				std::this_thread::sleep_for(chrono::milliseconds(10));
			}
		}
	}


	void producer2() {
		int count = 10;
		while (count > 0) {
			std::unique_lock<mutex> locker(mt);
			q.push_front(count);
			locker.unlock();

			cond.notify_one();  // notify one waiting thread, if any.
			// cond.notify_all();  // notifies all waiting threads
			std::this_thread::sleep_for(chrono::seconds(1));
			count--;
		}
	}

	// this leads to a busy-waiting - very inefficient way 
	void consumer2() {
		int data = 0;
		while (data != 1) {
			std::unique_lock<mutex> locker(mt);
			cond.wait(locker, []() { return !q.empty(); });  // spurious wake
			data = q.back();
			q.pop_back();
			locker.unlock();

			cout << "t2 got a value from t1: " << data << endl;
			
		}
	}


	void mainThread() {
		thread t1(producer), t2(consumer);
		t1.join(); t2.join();
	}
} // namespace