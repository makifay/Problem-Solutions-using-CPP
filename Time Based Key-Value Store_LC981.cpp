// LeetCode 981 

/* number of set operations:n, number of get operations:m

Time Complexity:
Set: O(1) single operation, total O(n).
Get: O(log n) for a single operation, and total O(m log n).

Space Complexity: O(n) */

typedef  pair<int,string> p_is;
 
class TimeMap {
  unordered_map<string, vector<p_is> > m;
public:
    TimeMap() {  }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({ timestamp, value });
    }
 
    string get(string key, int timestamp) {
        auto it = upper_bound(begin(m[key]), end(m[key]), p_is(timestamp, ""), 
                              []( const p_is& a, const p_is& b){return a.first < b.first;} );
  
        return it == m[key].begin() ? "" : prev(it)->second;
    }   
};

