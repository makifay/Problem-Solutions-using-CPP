// LeetCode 1146 

// storing values in the unordered_map for each snap id

/*Time Complexity: (n:number of "set+snap", m:number of "get")
    Set: O(1) single operation, and total O(n).
    Get: O(log n) for a single operation, and total O(m log n).
	
  Space Complexity: O(n)  */

class SnapshotArray {
public:
    SnapshotArray(int length) {}
    // Hashmap   < index, <snap_id, val>  >
    unordered_map<int, vector<pair<int, int>> > um;
    int cur_snap = 0;
    
    int snap() { return cur_snap++; }
    
    void set(int index, int val) {
        if (um[index].empty() || um[index].back().first != cur_snap)
			um[index].push_back({ cur_snap, val });
        else um[index].back().second = val;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(begin(um[index]), end(um[index]), 
							  pair<int, int>(snap_id, INT_MAX));
        return it == begin(um[index]) ? 0 : prev(it)->second;
    }
};