using namespace std;

#include <iostream>
#include <thread>
#include <future>
#include <deque>

/*
In summary:
there are 3 ways to get a future:
	a. promise::get_future().
	b. packaged_task::get_future().
	c. async() returns a future.
*/

namespace {
	int factorial(int n) {
		int result = 0;
		for (int i = n; i > 1; --i) {
			result *= i;
		}

		return result;
	}
	// the advantage of packacge_task is to associate to to the future.
	// which is very important in threading envirnoment

	void mainThread() {
		std::thread t1(factorial, 6);

		std::packaged_task<int(int)> t2(factorial);
		t2(6); // in different context
		int x = t2.get_future().get();

		// #bind returns a funtion object
		std::packaged_task<int()> t3(std::bind(factorial, 6));
		t3();

		// alternatively 
		auto t4 = std::bind(factorial, 6);
		t4();
	}


	std::deque<std::packaged_task<int()>> task_q;
	mutex mt;
	condition_variable cond;

	void worker() {
		std::packaged_task<int()> t;
		{
			std::unique_lock<mutex> locker(mt);
			cond.wait(
				locker,
				[&]() {
					return !task_q.empty();
				}
			);

			t = std::move(task_q.front());
			task_q.pop_front();
		}

		t();
	}

	void mainThread2() {
		std::thread th(worker);

		std::packaged_task<int()> t(std::bind(factorial, 6));
		std::future<int> fu = t.get_future();

		{
			std::unique_lock<mutex> locker(mt);
			task_q.push_back(std::move(t));
		}

		cond.notify_one();

		cout << fu.get();

		th.join();
	}
}

void testPackagedTask() {
	mainThread();

	mainThread2();
}