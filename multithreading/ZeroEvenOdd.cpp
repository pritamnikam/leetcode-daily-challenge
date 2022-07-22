// Print Zero Even Odd


#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>

using namespace std;

namespace {

	class ZeroEvenOdd {
		int n;
		int count_;
		bool zeroTurn;
		mutex mutex_;
		condition_variable cv_;

	public:
		ZeroEvenOdd(int n) {
			this->n = n;
			count_ = 0;
			zeroTurn = true;
		}

		// printNumber(x) outputs "x", where x is an integer.
		void zero(function<void(int)> printNumber) {
			while (true) {
				unique_lock<mutex> lock(mutex_);
				cv_.wait(lock, [&] { return count_ >= n || zeroTurn; });

				if (count_ >= n) {
					return;
				}

				zeroTurn = false;
				++count_;
				cv_.notify_all();
			}
		}

		void even(function<void(int)> printNumber) {
			while (true) {
				unique_lock<mutex> lock(mutex_);
				cv_.wait(lock, [&] { return count_ >= n || (!zeroTurn && count_%2==0); });

				if (count_ >= n) {
					return;
				}
				
				printNumber(count_);
				zeroTurn = true;
				++count_;
				cv_.notify_all();
			}
		}

		void odd(function<void(int)> printNumber) {
			while (true) {
				unique_lock<mutex> lock(mutex_);
				cv_.wait(lock, [&] { return count_ >= n || (!zeroTurn && count_ % 2 == 1); });

				if (count_ >= n) {
					return;
				}

				printNumber(count_);
				zeroTurn = true;
				++count_;
				cv_.notify_all();
			}
		}
	};
}
