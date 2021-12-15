// LeetCode 200 

/* Method: Do DFS in case has not been visited and there is land
- land 1: not visited; 
- visited:0 : when visiting turn land to water
 
 Time: O(V^2) */

class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        // edge conditions checking
        if(i < 0 || i >= grid.size() || j<0 || j >= grid[0].size())
            return;
        
        // return if current position is of water or is already visited
        if(grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '0';
        
        // do DFS in all 4 directions
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
     
        for(int i=0; i<grid.size(); ++i) {
            for(int j=0; j<grid[0].size(); ++j) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};