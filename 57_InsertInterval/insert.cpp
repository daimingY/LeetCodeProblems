/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	    vector<Interval> ans;

		// find last interval smaller than "newInterl"'s
		int i = 0;
		for(; i < intervals.size() && intervals[i].start < newInterval.start; ++i){
			ans.emplace_back(intervals[i].start, intervals[i].end);
		}

		// help function for merging/inserting
		auto insert = [&ans] (Interval& interval){
			// non-empty ans vec
			if(ans.size() > 0 && ans.bakc().end >= interval.start){
				// renew last interval's back
				if(interval.end > ans.back().end){
					ans.back().end = interval.end;
				}
			}else{
				// insert another interval
                ans.emplace_back(interval.start, interval.end);
            }
		}

		// merge/insert "newInterval"
		insert(newInterval);
		
		// merge/insert other intervals
		for(; i < intervals.size(); ++i){
			insert(intervals[i]);
		}
		
		return ans;
    // add intervals whose `start` time is smaller than `newInterval`'s.
    int i = 0;
    for (; i < intervals.size() && intervals[i].start < newInterval.start; ++i) {
        ans.emplace_back(intervals[i].start, intervals[i].end);
    }

    // helper function for inserting/merging next interval into `ans` list.
    auto insert = [&ans] (Interval& interval) {
        if (ans.size() > 0 && ans.back().end >= interval.start) {
            if (interval.end > ans.back().end) {
                ans.back().end = interval.end;
            }
        } else {
            ans.emplace_back(interval.start, interval.end);
        }
    };

    // insert/merge `newInterval`
    insert(newInterval);

    // insert/merge the rest intervals.
    for (; i < intervals.size(); ++i) {
        insert(intervals[i]);
    }

    return ans;    }
};
