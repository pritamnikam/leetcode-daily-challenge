#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <future>

using namespace std;

namespace {
	void factorial(int n) {
		int result = 1;
		for (int i = n; i > 1; --i) {
			result *= i;
		}

		cout << "Result is: " << result << endl;
	}


	void mainThread() {
		thread t(factorial, 5);
		t.join();
	}


	/*
	mutex mt;
	condition_variable cond;

	void factorial2(int n, int& x) {
		int result = 1;
		for (int i = n; i > 1; --i) {
			result *= i;
		}

		cout << "Result is: " << result << endl;
		x = result;
	}

	void mainThread2() {
		int x = 0;
		thread t(factorial, 5, std::ref(x));
		t.join();
	}
	*/

	int factorial3(int n) {
		int result = 1;
		for (int i = n; i > 1; --i) {
			result *= i;
		}
		return result;
	}

	void mainThread3() {
		// future is a channel from where we can get the result from the child thread.
		std::future<int> fu = std::async(factorial3, 4);
		int x = fu.get(); // wait until child thread finish and then return the result.
		
						  
		// future call only get called once.
		// attempt to call #get() again crash the program.
		// fu.get() // crash the program.
	}


	void mainThread4() {
		// #async() does not always creates a child thread.
		// std::launch::deferred just deferres the execution until #get() is called in same the thread.
		std::future<int> fu = std::async(std::launch::deferred, factorial3, 4);

		// do something
		int x = fu.get();
	}

	void mainThread5() {
		// #async() with std::launch::async will creates a child thread.
		std::future<int> fu = std::async(std::launch::async, factorial3, 4);

		// do something
		int x = fu.get();
	}


	int factorial6(std::future<int>& f) {
		cout << "Thread: " << std::this_thread::get_id() << endl;
		int result = 1;
		int n = f.get();  // exception: std::future_errc::broken_promise
		for (int i = n; i > 1; --i) {
			result *= i;
		}
		return result;
	}

	void mainThread6() {
		cout << "Main Thread: " << std::this_thread::get_id() << endl;

		// By using promise and future, we are tellingthe child thread
		// that we will be passing a value
		// but we dont have value yet
		// I will send it over in the future
		// that is my promise
		std::promise<int> p;
		std::future<int> f = p.get_future();

		std::future<int> fu = std::async(std::launch::async,
										 factorial6,
										 std::ref(f));

		// do something
		std::this_thread::sleep_for(chrono::seconds(1));
		p.set_value(4);

		int x = fu.get();

		cout << "Result: " << x << endl;
	}

	void mainThread7() {
		cout << "Main Thread: " << std::this_thread::get_id() << endl;

		// By using promise and future, we are tellingthe child thread
		// that we will be passing a value
		// but we dont have value yet
		// I will send it over in the future
		// that is my promise
		std::promise<int> p;
		std::future<int> f = p.get_future();

		std::future<int> fu = std::async(std::launch::async,
			factorial6,
			std::ref(f));

		// do something
		std::this_thread::sleep_for(chrono::seconds(1));

		// If we break the promise
		// set the exception - so when child thread calls #get() it get this exception
		p.set_exception(std::make_exception_ptr(std::runtime_error("To er is human.")));
	}



	int factorial8(std::shared_future<int> f) {
		cout << "Thread: " << std::this_thread::get_id() << endl;
		int result = 1;
		int n = f.get();
		for (int i = n; i > 1; --i) {
			result *= i;
		}
		return result;
	}

	void mainThread8() {
		cout << "Main Thread: " << std::this_thread::get_id() << endl;

		std::promise<int> p;
		std::future<int> f = p.get_future();
		std::shared_future<int> sf = f.share(); // suitable for broadcast

		std::future<int> fu = std::async(std::launch::async,
			factorial8,
			sf);
		std::future<int> fu2 = std::async(std::launch::async,
			factorial8,
			sf);
		std::future<int> fu3 = std::async(std::launch::async,
			factorial8,
			sf);
		std::future<int> fu4 = std::async(std::launch::async,
			factorial8,
			sf);
		// .... 10 more such threads

		// do something
		std::this_thread::sleep_for(chrono::seconds(1));
		p.set_value(4);
	}

} // namespace


void testFuturePromiseAndAsync() {
	mainThread6();
	mainThread8();
}