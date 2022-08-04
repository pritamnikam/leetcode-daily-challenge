using namespace std;

#include <thread>
#include <future>

namespace {

	int factorial(int x) {
		int result = 0;
		for (int i = x; i > 1; --i) {
			result *= i;
		}

		return result;
	}

	void mainThread() {
		// thread
		std::thread t1(factorial, 6);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(5);
		std::this_thread::sleep_until(tp);


		// mutex
		std::mutex mu;
		{ std::lock_guard<mutex> locker(mu); }
		{ 
			std::unique_lock<mutex> ulocker(mu);
			ulocker.try_lock();
			ulocker.try_lock_for(chrono::nanoseconds(500));
			ulocker.try_lock_until(tp);
		}


		// conditon variables
		std::condition_variable cond;
		{
			std::unique_lock<mutex> ulocker(mu);
			cond.wait(ulocker);
			cond.wait_for(ulocker, chrono::nanoseconds(500));
			cond.wait_until(ulocker, tp);
		}

		// future and promise
		std::promise<int> p;
		std::future<int> f = p.get_future();
		{
			f.get();
			f.wait();
			f.wait_for(chrono::nanoseconds(500));
			f.wait_until(tp);
		}

		// async
		std::future<int> fu = std::async(factorial, 6);


		// packaged task
		std::packaged_task<int(int)> pt(factorial);
		std::future<int> fu2 = pt.get_future();
		pt(6);
	}
}