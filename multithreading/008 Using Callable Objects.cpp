using namespace std;

#include <iostream>
#include <thread>
#include <future>


namespace {
	class A {
	public:
		void f(int x, char c) {}
		long g(double x) { return 0; }
		int operator() (int n) { return 0; }
	};

	void foo(int x) {

	}

	void mainThread() {
		A a;
		std::thread t1(a, 6);  // copy_of_a() invoking as a functor in different thread.
		std::thread t2(std::ref(a), 6);  // a() invoking as a functor in different thread.
		std::thread t3(A(), 6); // create temp A; and move to different thread
		std::thread t4([](int x) { return x * x; }, 6);
		std::thread t5(foo, 6);
		std::thread t6(&A::f, a, 6, 'A'); // copy_of_a.f(6, 'A')  in different thread.
		std::thread t7(&A::f, &a, 6, 'A'); // a.f(6, 'A')  in different thread.
		std::thread t8(std::move(a), 6);  // a is no longer usable in main thread


		// we can also use them callable using below methods
		// std::async(std::launch::async, a, 6);
		// std::bind(a, 6);
		// std::call_once(once_flag, a, 6);
	}
}