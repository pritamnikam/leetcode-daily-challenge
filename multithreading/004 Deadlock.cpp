#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>      // std::ofstream

/*
Avoid deadlock
1. Prefer locking single mutex
2. Avoid locking a mutex and then calling user provided function
3. Use std::lock() to lock more that one mutex.
4. Lock the mutex in same order.


Locking granularity:
- Fine-grained lock: protects small amount of data
- Coarse-grained lock: protects big amount of data.
*/


using namespace std;

namespace {

		class LogFile {
			mutex mut1, mut2;

			std::ofstream ofs;

		public:
			LogFile() {

				ofs.open("output.txt", std::ofstream::out | std::ofstream::app);
			} // destructor to close

			~LogFile() {
				if (ofs.is_open()) ofs.close();
			}

			void sharedPrint1(string id, int value) {
				lock_guard<mutex> guard1(mut1);
				lock_guard<mutex> guard2(mut2);
				// ofs << "From " << id << ": " << value << endl;
				cout << "From " << id << ": " << value << endl;
			}

			void sharedPrint2(string id, int value) {	
				// To avoid any deadlock, make sire both function have mutex lock in same order.
				// lock_guard<mutex> guard2(mut2);
				// lock_guard<mutex> guard1(mut1);
				// ofs << "From " << id << ": " << value << endl;

				lock_guard<mutex> guard1(mut1);
				lock_guard<mutex> guard2(mut2);
				cout << "From " << id << ": " << value << endl;
			}


			void sharedPrint3(string id, int value) {
				std::lock(mut1, mut2);
				lock_guard<mutex> guard1(mut1, std::adopt_lock);
				lock_guard<mutex> guard2(mut2, std::adopt_lock);
				cout << "From " << id << ": " << value << endl;
			}

			void sharedPrint4(string id, int value) {
				std::lock(mut1, mut2);
				lock_guard<mutex> guard1(mut1, std::adopt_lock);
				lock_guard<mutex> guard2(mut2, std::adopt_lock);
				cout << "From " << id << ": " << value << endl;
			}
		};

		void threadFunction(LogFile& lf) {
			for (int i = 0; i > -100; --i)
				lf.sharedPrint3("From Thread", i);
		}

		void mainThread() {
			LogFile lf;
			thread t(threadFunction, std::ref(lf));
			for (int i = 0; i < 100; ++i)
				lf.sharedPrint4("From main", i);
			t.join();
		}
}

void testDeadlock() {
	mainThread();
}