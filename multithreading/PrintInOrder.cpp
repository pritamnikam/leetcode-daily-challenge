// Print in order

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>


using namespace std;

namespace {
	class Foo {
		int lastExecutedFunction_;
		mutex mutex_;
		condition_variable cv_;

	public:
		Foo() {
			lastExecutedFunction_ = 0; // 0 (initial), 1, 2, or 3
		}

		void first(function<void()> printFirst) {
			unique_lock<mutex> lock(mutex_);
			cv_.wait(lock, [&] {return lastExecutedFunction_ == 0; });

			printFirst();
			lastExecutedFunction_ = 1;
			cv_.notify_all();
		}

		void second(function<void()> printSecond) {
			unique_lock<mutex> lock(mutex_);
			cv_.wait(lock, [&] {return lastExecutedFunction_ == 1; });

			printSecond();
			lastExecutedFunction_ = 2;
			cv_.notify_all();
		}

		void third(function<void()> printThird) {
			unique_lock<mutex> lock(mutex_);
			cv_.wait(lock, [&] {return lastExecutedFunction_ == 2; });

			printThird();
			lastExecutedFunction_ = 0;
			cv_.notify_all();
		}
	};

	

} // namespace

void testPrintInOrder() {
	function<void()> printFirst = []() {cout << "first" << endl; };
	function<void()> printSecond = []() {cout << "second" << endl; };
	function<void()> printThird = []() {cout << "third" << endl; };

	Foo foo;
	thread t1([&] {foo.first(printFirst); });
	thread t2([&] {foo.second(printSecond); });
	thread t3([&] {foo.third(printThird); });

	t1.join(); t2.join(); t3.join();
}
