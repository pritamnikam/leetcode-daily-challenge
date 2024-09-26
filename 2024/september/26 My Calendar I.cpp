// 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i

struct Interval {
    int start;
    int end;
};

class MyCalendar {
    vector<Interval> intervals;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& interval: intervals) {
            if (interval.start < end && interval.end > start) {
                return false;
            }
        }
        intervals.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
