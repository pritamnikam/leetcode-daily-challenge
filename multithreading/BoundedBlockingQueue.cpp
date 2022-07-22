// Design Bounded Blocking Queue


#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>
#include <queue>

using namespace std;

namespace {
	class BoundedBlockingQueue {
		std::condition_variable no_full_cond_, no_empty_cond_;
		std::mutex m_mutex;
		int capacity;
		queue<int> queue;

	public:
		BoundedBlockingQueue(int capacity) : capacity(capacity) {
		}

		void enqueue(int element) {
			unique_lock<mutex> lock(m_mutex);
			no_full_cond_.wait(lock, [&] { return queue.size() < capacity; });

			queue.push(element);
			no_empty_cond_.notify_one();
		}

		int dequeue() {
			unique_lock<mutex> lock(m_mutex);
			no_empty_cond_.wait(lock, [&] { return !queue.empty(); });
			int val = queue.front();
			queue.pop();
			no_full_cond_.notify_one();
			return val;
		}

		int size() {
			return queue.size();
		}
	};
}

