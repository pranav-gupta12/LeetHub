class MyCalendar {
public:
      unordered_map<int,int> events;
    MyCalendar() {
      
    }
    
    bool book(int start, int end) {
              for (auto it : events) {
            int s = it.first;
            int e = it.second;
            // Check if there's an overlap
            if (!(end <= s || start >= e)) {
                return false;  // Overlap detected, return false
            }
        }
        // If no overlap, add the event
        events[start] = end;
        return true;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */