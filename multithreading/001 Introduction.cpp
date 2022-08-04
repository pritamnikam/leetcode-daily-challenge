using namespace std;

#include <iostream>
#include <thread>

namespace {
	void funtion_1() {
		cout << "Beauty is only skin-deep" << endl;
	}

	// main thread calling #funtion_1
	void introduction1() {
		funtion_1();
	}

	void introduction2() {
		thread t1(funtion_1); // t1 starts running
	}

	void introduction3() {
		thread t1(funtion_1);  // t1 starts running
		t1.join(); // main thread waits for t1 to finish
	}

	void introduction4() {
		thread t1(funtion_1);  // t1 starts running
		t1.detach(); // t1 will be free on it's own - daemon process
	}

	void introduction5() {
		thread t1(funtion_1);  // t1 starts running
		t1.detach(); // t1 will be free on it's own - daemon process

		// one can join or detach a thread only once.
		// t1.join(); // crash - You cannot treat your child like that. Once detached, forever detached.

		// 
		if (t1.joinable())
			t1.join();
	}

} // namespace 

void testThreadIntroduction() {
	introduction1();
	// introduction2();
	introduction3();
	introduction4();
	introduction5();
}