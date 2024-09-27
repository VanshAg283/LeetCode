class MyCalendarTwo {
public:
    vector<pair<int,int>> cal1;  // stores all intervals
    vector<pair<int,int>> cal2;  // stores overlapping intervals
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Check for triple bookings
        for (auto& time : cal2) {
            int s2 = time.first;
            int e2 = time.second;
            if (start < e2 && end > s2) {
                return false;
            }
        }
        for (auto& time : cal1) {
            int s1 = time.first;
            int e1 = time.second;
            if (start < e1 && end > s1) {
                int overlap_start = max(start, s1);
                int overlap_end = min(end, e1);
                cal2.push_back(make_pair(overlap_start, overlap_end));
            }
        }
        cal1.push_back(make_pair(start, end));
        return true;
    }
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */