#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>      // std::ofstream


using namespace std;

/*
unique_lock are more flexible than lock_guard

however, the flexibility of unique_lock is free, it comes with an overhead.
So performance may get a hit.

*/


namespace {

	class LogFile {
		mutex mut;
		mutex mut_open;
		std::once_flag flag;
		std::ofstream ofs;

	public:
		LogFile() {

			ofs.open("output.txt", std::ofstream::out | std::ofstream::app);
		} // destructor to close

		~LogFile() {
			if (ofs.is_open()) ofs.close();
		}

		void sharedPrint(string id, int value) {
			// lock_guard<mutex> guard(mut);
			// ofs << "From " << id << ": " << value << endl;

			unique_lock<mutex> lock(mut);
			ofs << "From " << id << ": " << value << endl;
		}

		void sharedPrint2(string id, int value) {
			unique_lock<mutex> locker(mut, std::defer_lock);
			// do something

			locker.lock();
			ofs << "From " << id << ": " << value << endl;
			locker.unlock();

			// do something else

			locker.lock();
			//.....
			locker.unlock();


			// move ownership
			unique_lock<mutex> locker2 = std::move(locker);

		}


		void sharedPrint3(string id, int value) {
			// lazy initialization -> initialization upon first use idiom
			{
				// thread-safe file opening
				// however, this lead to bad design/implementation 
				// as every time mutext locking and unlocking will happen
				unique_lock<mutex> locker2(mut_open);
				if (!ofs.is_open()) {
					ofs.open("output.txt", std::ofstream::out | std::ofstream::app);
				}
			}

			unique_lock<mutex> locker(mut);
			ofs << "From " << id << ": " << value << endl;
		}



		void sharedPrint4(string id, int value) {
			// lazy initialization -> initialization upon first use idiom
			// thread-safe file opening with std::once_flag and std::call_once
			std::call_once(
				flag,
				[&]() {
					// file will be open only once by one thread.
					if (!ofs.is_open()) {
						ofs.open("output.txt",
								  std::ofstream::out | std::ofstream::app);
					}
				}
			);

			unique_lock<mutex> locker(mut);
			ofs << "From " << id << ": " << value << endl;
		}
	};
}