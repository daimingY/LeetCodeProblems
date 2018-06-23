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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> retVal;
        int size = intervals.size();

        // sort
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        // merge
        for(int i = 0; i < size; ++i){
            Interval temp(intervals[i].start, intervals[i].end);
            int tempEnd = intervals[i].end;
            // as along as the current end overlaps the next start, merge intervals.
            while((i+1) < size && tempEnd >= intervals[i + 1].start){
                tempEnd = max(tempEnd, intervals[i+1].end);
                i++;
            }
            temp.end = tempEnd;
            retVal.push_back(temp);
        }
        return retVal;
    }
};
