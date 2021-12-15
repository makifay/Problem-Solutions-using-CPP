// LeetCode 871 

// Approach: Priortiy Queue 

// Time:  O(NlogN)

/* >> at each loop:
- add all reachable stat to pq.
- pop out the largest gas from pq and refuel once.
- If we can't refuel, can not go  */

class Solution {
public:
    int minRefuelStops(int target, int cur, vector<vector<int>>& stat) {
        int i = 0, res;
        priority_queue<int>pq;
	
        // i: iterate over stats pos
        // res: refueling count
        for (res = 0; cur<target; ++res) {
            // Continue and push fuel of stats into pq
            while (i < stat.size() && stat[i][0] <= cur)
                pq.push(stat[i++][1]); 
		
            // if no fuel in queue, can't arrive
            if (pq.empty()) return -1;
            
            // take the max of previous stat's fuels
            cur += pq.top();
            pq.pop();
        }
		
        return res;
    }
};