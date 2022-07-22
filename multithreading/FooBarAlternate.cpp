// Print FooBar Alternately

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>

using namespace std;

namespace {
    class FooBar {
        int n;
        bool isFoo;
        mutex mutex_;
        condition_variable cv_;

    public:
        FooBar(int n) : n(n), isFoo(true) {
        }

        void foo(function<void()> printFoo) {
            for (int i = 0; i < n; i++) {
                unique_lock<mutex> lock(mutex_);
                cv_.wait(lock, [&] {return isFoo == true; });
                printFoo();
                isFoo = false;
                cv_.notify_all();
            }
        }

        void bar(function<void()> printBar) {
            for (int i = 0; i < n; i++) {
                unique_lock<mutex> lock(mutex_);
                cv_.wait(lock, [&] {return isFoo != true; });
                printBar();
                isFoo = true;
                cv_.notify_all();
            }
        }
    };
} // namespace


void testPrintFooBarAlternately() {
    function<void()> printFoo = []() {cout << "foo" << endl; };
    function<void()> printBar = []() {cout << "bar" << endl; };

    FooBar foobar(3);
    thread t1([&] (){ foobar.foo(printFoo); });
    thread t2([&] (){ foobar.bar(printBar); });

    t1.join(); t2.join();
}

