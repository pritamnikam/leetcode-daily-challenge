// Fizz Buzz Multithreaded

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>
#include <queue>

using namespace std;

namespace {

	class FizzBuzz {
		int n;
		int count;
		std::condition_variable cv_;
		std::mutex m_mutex;
	public:
		FizzBuzz(int n) {
			this->n = n;
			count = 0;
		}

		// printFizz() outputs "fizz".
		void fizz(function<void()> printFizz) {
			while (true) {
				unique_lock<mutex> lock(m_mutex);
				cv_.wait(lock, [&] {return (count < n && count % 3 == 0 && count % 5 != 0); });
				//counter exceeded, all threads need to break
				if (count > n) break;
				count++;
				printFizz();
				cv_.notify_all();
			}
		}

		// printBuzz() outputs "buzz".
		void buzz(function<void()> printBuzz) {
			while (true) {
				unique_lock<mutex> lock(m_mutex);
				cv_.wait(lock, [&] {return (count < n && count % 3 != 0 && count % 5 == 0); });
				//counter exceeded, all threads need to break
				if (count > n) break;
				count++;
				printBuzz();
				cv_.notify_all();
			}
		}

		// printFizzBuzz() outputs "fizzbuzz".
		void fizzbuzz(function<void()> printFizzBuzz) {
			while (true) {
				unique_lock<mutex> lock(m_mutex);
				cv_.wait(lock, [&] {return (count < n && count % 3 == 0 && count % 5 == 0); });

				//counter exceeded, all threads need to break
				if (count > n) break;

				count++;
				printFizzBuzz();
				cv_.notify_all();
			}
		}
	};
}

