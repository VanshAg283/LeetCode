class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto& time : events) {
            int s = time.first;
            int e = time.second;

            if (start < e && end > s) {
                return false;
            }
        }
        events.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */