// Building H2O


#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>

using namespace std;


// H2O -> HHO
namespace {
    class H2O {
    public:
        H2O() = default;

        void hydrogen(function<void()> releaseHydrogen) {
            unique_lock<mutex> lock( m_mutex );
            cv.wait(lock, [&] { return m_state < 2; });

            releaseHydrogen();
            m_state++;

            cv.notify_all();
        }

        void oxygen(function<void()> releaseOxygen) {
            unique_lock<mutex> lock(m_mutex);
            cv.wait(lock, [&] { return m_state == 2; });

            releaseOxygen();
            m_state = 0;

            cv.notify_all();
        }

    private:
        std::condition_variable cv;
        std::mutex m_mutex;
        int m_state = 0;
    };


}

void testH2O() {
	function<void()> releaseHydrogen = []() {cout << "H" ; };
	function<void()> releaseOxygen = []() {cout << "O" ; };

	H2O h2o;
	thread t1([&]() { h2o.hydrogen(releaseHydrogen); });
	thread t2([&]() { h2o.oxygen(releaseOxygen); });

	t1.join(); t2.join();
}
