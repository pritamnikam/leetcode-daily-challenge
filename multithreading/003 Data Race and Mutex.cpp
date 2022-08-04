#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>      // std::ofstream

using namespace std;


/*
Avoiding data races:
1. use mutexes to synchronize the data access
2. never leak a handle of the data outside 
3. Design interfaces appropreatly
*/
namespace {

	class LogFile {
		mutex mut;
		std::ofstream ofs;

	public:
		LogFile() {
			
			ofs.open("output.txt", std::ofstream::out | std::ofstream::app);
		} // destructor to close

		void sharedPrint(string id, int value) {
			lock_guard<mutex> guard(mut);
			ofs << "From " << id << ": " << value << endl;
		}

		// never return f to outside world
		// ofstream& getStream() { return f; } // <- bad idea

		// never pass f as an argument to the user provided function
		/*
		void processf(void fun(ostream& f)) {
			fun(f);
		}
		*/
	};

	mutex mt;
	void shared_function(string msg, int count) {
		lock_guard<mutex> guard(mt); // RAII -> // Resorce aqusition is initialization (RAII) approach
		// mt.lock();

		cout << msg << " " << count << endl;
		// mt.unlock();
	}

	void function1() {
		for (int i = 0; i > -100; --i)
			// cout << "From thread: " << i << endl;
			shared_function("From thread:", i);
	}

	void mainThred() {
		thread t(function1);
		for (int i = 0; i < 100; ++i)
			// cout << "From main: " << i << endl;
			shared_function("From main:", i);

		t.join();
	}

	void function_2(LogFile& lf) {
		for (int i = 0; i > -100; --i)
			lf.sharedPrint("From thread", i);
	}

	void logger() {
		LogFile lf;
		std::thread t(function_2, std::ref(lf));
		for (int i = 0; i < 100; ++i)
			lf.sharedPrint("From main", i);
		t.join();
	}
}  // namespace

void testDataRaceAndMutex() {
	// mainThred();
	logger();
}
