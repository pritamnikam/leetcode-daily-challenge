// 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/

class MyCalendarTwo {
public:
   vector<pair<int, int>>Booking; //stores intervals of  all eligible bookings
   vector<pair<int, int>>doubleBooking; //stores intervals of only those bookings which have some intervals is common in 2 events
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        //Check if the new booking overlaps with double-booked region
        for(auto &a :doubleBooking ){
            //check for overlap
            //if  there is overlap , then new booking can't be done because it leads to triple booking
            if(max(start, a.first) < min(end , a.second))
                return false;
        }
        
        
        // check if the new booking overlap with current bookings
        //if it overlaps, then it leads to double booking: so we have to push overlap region in double-booking
        for(auto& a: Booking){
            if(max(start, a.first) < min(end, a.second)) {
                int start_overlap = max(start , a.first);
                int end_overlap = min(end , a.second);
                doubleBooking.push_back({start_overlap, end_overlap});
            }
        }
        
        Booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
