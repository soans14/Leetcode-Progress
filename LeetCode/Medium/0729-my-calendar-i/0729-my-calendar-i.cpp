class MyCalendar {
public:
    set<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it=events.begin();
        while(it!=events.end()){
            if(startTime<it->second&&it->first<endTime){
                return false;
            }
            it++;
        }
        events.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */