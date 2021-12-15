// LeetCode 1834

/* >> Approach: Min-Heap
Use a min-heap pq to keep track of available tasks, 

Sort the input array in ascending order of enqueue time.

If current time >= A[i][0], keep pushing A[i] into the min-heap.

Then we pop a task from the min-heap and handle it. 

Increase the time by the proc time of this task and add its index to the answer.  
*/

// Time: O(NlogN)
// Space: O(N)

class Solution {
    typedef pair<int, int> ti; // <processing time, index>
	
public:         
    // A: [enqueueTime, processingTime]
    vector<int> getOrder(vector<vector<int>>& A) {
        // min heap of tasks
        priority_queue< ti, vector<ti>, greater<> > pq; 
		
        long N = A.size(), curTime = 0, i = 0; 
        
        // append the index to each task
        for (int i=0; i<N; ++i) A[i].push_back(i); 

        // sort the input array by enqueueTime
        // we can take the tasks of small enqueueTime first
        sort(begin(A), end(A)); 
        
        vector<int> ans;
        // stop the loop when we exhausted the input array and the tasks in the heap.
        while (i<N || pq.size()) { 
            if (pq.empty()) {
                // check the updating of the curTime using the proc time of the next task
                curTime = max(curTime, (long)A[i][0]); 
            }
             // push all the tasks whose enqueueTime <= currentTime into the heap
            while ( i<N &&  A[i][0]<=curTime ) {
                pq.emplace(A[i][1], A[i][2]); // processingTime, index
                ++i;
            }
            auto [proc, index] = pq.top();
            pq.pop();
			
            curTime += proc; // handle this task and increase the curTime by it
            ans.push_back(index);
        }
        return ans;
    }
};