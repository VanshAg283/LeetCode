class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int> mymap;
    
    int book(int startTime, int endTime) {
        mymap[startTime]++;
        mymap[endTime]--;
        int clashes = 0;
        int max_clashes = 0;
        for(auto it : mymap){
            clashes += it.second;
            max_clashes = max(max_clashes,clashes);
        }
        return max_clashes;    
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */