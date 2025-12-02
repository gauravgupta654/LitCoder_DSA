#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Interval {
    int start;
    int end;
    bool valid;
    bool overlaps;
    
    Interval(int s, int e) : start(s), end(e) {
        valid = (start < end);
        overlaps = false;
    }
};

vector<pair<int, int>> mergeIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), 
         [](const Interval& a, const Interval& b) {
             return a.start < b.start;
         });
    
    vector<pair<int, int>> merged;
    
    if (intervals.empty()) return merged;
    
    vector<pair<int, int>> validIntervals;
    for (const auto& interval : intervals) {
        if (interval.valid) {
            validIntervals.push_back({interval.start, interval.end});
        }
    }
    
    if (validIntervals.empty()) return merged;
    
    pair<int, int> current = validIntervals[0];
    
    for (size_t i = 1; i < validIntervals.size(); i++) {
        if (validIntervals[i].first <= current.second) {
            current.second = max(current.second, validIntervals[i].second);
        } else {
            merged.push_back(current);
            current = validIntervals[i];
        }
    }
    
    merged.push_back(current);
    
    return merged;
}

bool doOverlap(const Interval& a, const Interval& b) {
    if (!a.valid || !b.valid) return false;
    return max(a.start, b.start) <= min(a.end, b.end);
}

int main() {
    string line;
    vector<int> startTimes, endTimes;
    
    getline(cin, line);
    stringstream ss1(line);
    int num;
    while (ss1 >> num) {
        startTimes.push_back(num);
    }
    
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> num) {
        endTimes.push_back(num);
    }
    
        vector<Interval> intervals;
    int invalidCount = 0;
    
    int n = min(startTimes.size(), endTimes.size());
    for (int i = 0; i < n; i++) {
        Interval interval(startTimes[i], endTimes[i]);
        intervals.push_back(interval);
        
        if (!interval.valid) {
            invalidCount++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!intervals[i].valid) continue;
        
        for (int j = 0; j < n; j++) {
            if (i == j || !intervals[j].valid) continue;
            
            if (doOverlap(intervals[i], intervals[j])) {
                intervals[i].overlaps = true;
                intervals[j].overlaps = true;
            }
        }
    }
    
    int nonOverlapCount = 0;
    for (const auto& interval : intervals) {
        if (interval.valid && !interval.overlaps) {
            nonOverlapCount++;
        }
    }
    
    vector<pair<int, int>> merged = mergeIntervals(intervals);
    
    if (!merged.empty()) {
        for (size_t i = 0; i < merged.size(); i++) {
            cout << merged[i].first << " " << merged[i].second;
            if (i != merged.size() - 1) {
                cout << " ";
            }
        }
    }
    cout << endl;
    
   cout << nonOverlapCount << endl;
    
    cout << invalidCount << endl;
    
    return 0;
}
