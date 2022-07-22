// Traffic Light Controlled Intersection

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

#include <functional>

using namespace std;

namespace {

	class TrafficLight {
		mutex locker;
		int currentDirection;
	public:
		TrafficLight() {
			currentDirection = 1;
		}

		void carArrived(int carId,                   // ID of the car
						int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
						int direction,               // Direction of the car
						function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
						function<void()> crossCar    // Use crossCar() to make car cross the intersection
					) {

			locker.lock();

			// if the current car road ID is the same as the traffic light, then just cross
			if (direction == currentDirection) {
				crossCar();
			}
			else {
				currentDirection = direction;
				turnGreen();
				crossCar();
			}

			locker.unlock();
		}
	};

}  // namespace

