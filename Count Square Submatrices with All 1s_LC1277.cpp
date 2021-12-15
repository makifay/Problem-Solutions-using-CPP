// LeetCode 1277 

// Approach: righ-bottom corner, check 3 neighbor (up/left/up-left-cross ) 
// Time O(M*N), Matrix Dimensions: M*N
// Space O(1)

class Solution {
public:
   int countSquares(vector<vector<int>>& A) {
        int res = 0;
       
        for (int i=0; i<A.size(); ++i)
            for (int j=0; j<A[0].size(); ++j ){
                // Enter if value:1 and not edge (i and j not 0)
                // Edge cells can not be bottom-right of square 2x2
                 if (A[i][j]>0 && i && j) {
					  // take min of 3 cells: up, left, up-left-cross 
                     A[i][j] = 1+ min({ A[i-1][j], 
                                        A[i][j-1],
                                        A[i-1][j-1] });
                 }
                 res += A[i][j];
            }
        return res;
    }
};
