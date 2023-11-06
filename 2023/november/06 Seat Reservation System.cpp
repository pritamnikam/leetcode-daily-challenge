// 1845. Seat Reservation System
// https://leetcode.com/problems/seat-reservation-manager

namespace {

class SeatManager {
    // min heap to store all unreserved seats.
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // initialize min heap
        for (int i = 1; i <= n; i++) {
            availableSeats.push(i);
        }       
    }
    
    int reserve() {
        // get the smallest-number unreserved seat from the min heap.
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }
    
    void unreserve(int seatNumber) {
        // push the unreserved seat in min heap
        availableSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

}
