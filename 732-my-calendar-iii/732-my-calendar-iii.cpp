class MyCalendarThree{
public:
    MyCalendarThree() {
        // Add -1 as a guardian entry, so later on we don't have to worry the --lower_bound(..) operation will cross the map's boundary.
        events_.emplace(-1, 0);
    }
    
    int book(int start, int end) {
        // Insert start event, copy existing event's count.
        auto exist_ev = prev(events_.lower_bound(start));
        auto start_it = events_.emplace(start, exist_ev->second).first; 
        // Insert end event, copy existing event's count.
        // Though the end point is exclusive, we should still copy previous event's count:
        // Either it falls into some event's range, so the count should be this event's count;
        // Or it's not in any existing event's range, so it should copy previous event's end point, hence 0.
        // And we need end event in the map to let following event know the previous event has ended.
        exist_ev = prev(events_.lower_bound(end));
        auto end_it = events_.emplace(end, exist_ev->second).first;
        for(auto it = start_it; it != end_it; it++){
            count_ = max(count_, ++(it->second)); // increase the counter for all events inside the range, update max overbook count.
        }
        return count_;
    }
    
private:
    map<int, int> events_;
    int count_ = 0;
};
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */