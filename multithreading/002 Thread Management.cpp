#include <iostream>
#include <thread>

using namespace std;

namespace {
	void funtion_1() {
		cout << "Beauty is only skin-deep" << endl;
	}


	int worker() {
		thread t1(funtion_1);


		// this (try-catch) make sure t1 will join with or without exection
		try {
			for (int i = 0; i < 10; ++i) 
				cout << "from maint: " << i << endl;
		}
		catch (...) {
			t1.join();
			throw;
		}

		t1.join();
	}


	class Fctor {
	public:
		void operator()() {
			for (int i = 0; i > -100; --i) {
				cout << "from t1: " << i << endl;
			}
		}
	};

	// Resorce aqusition is initialization (RAII) approach
	void workerRAII() {
		
		// create a wrapper class and thread t1 will be warapped inside
		// when destructor of wrapper is called, t1 will be join
		// Wrapper w(t1); // when w get out of scope, automatically t1 will join

		Fctor fct;
		thread t(fct);


		// thread t2(Fctor()); // this will not work - known as most vexing syntax in c++
		// thread t2((Fctor()));  // solution is to add another pair of parenthesis
		
		// this (try-catch) make sure t1 will join with or without exection
		try {
			for (int i = 0; i < 10; ++i)
				cout << "from maint: " << i << endl;
		}
		catch (...) {
			t.join();
			throw;
		}

		t.join();
	}


	class Fctor2 {
	public:
		void operator()(string& str) {
			cout << "from t: " << str << endl;
			str = "Trust is the mother of decit.";
		}
	};

	void workerRAII2() {
		string str = "Where is no trust, there is no love.";
		// thread t((Fctor2()), str); // |str| is passwed by value
		// t.join();
		cout << "from main: " << str << endl;
	}

	void workerRAII3() {
		string str = "Where is no trust, there is no love.";
		cout << "this_thread id: " << this_thread::get_id() << endl;
		thread t((Fctor2()), std::ref(str)); // creates a reference wrapper of |str|, to be pass by reference
		
		cout << "thread id: " << t.get_id() << endl;

		t.join();
		cout << "from main: " << str << endl;

		
	}

	void workerRAII4() {
		string str = "Where is no trust, there is no love.";
		// thread t((Fctor2()), std::move(str)); // creates a reference wrapper of |str|, to be pass by reference
		// t.join();
		// cout << "from main: " << str << endl;
	}

}  // namespace 


void testThreadManagement() {

	cout << "hardware_concurrency: " << thread::hardware_concurrency() << endl;

	worker();
	workerRAII();
	workerRAII2();
	workerRAII3();
}