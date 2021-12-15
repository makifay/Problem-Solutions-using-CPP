// LeetCode 305

/*You are given an empty 2D binary grid grid of size m x n. 
The grid represents a map where 0's represent water and 1's represent land. 
Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. 
You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.*/


// ----------------------------------
// Approach: UnionFind Structure 

class UnionFind {
	int cnt = 0;
	vector<int> size;   
	vector<int> roots; 
public:

  UnionFind(int n) {
    for (int i=0; i<n; ++i) {
      roots.push_back(-1);
      size.push_back(0);
    }
  }
  
  int findRoot(int id) { // with path compression
         if(id == roots[id]) return roots[id];
         
        return roots[id] = findRoot(roots[id]);
   }

 void unify(int id, int dir_id) { 
        int dirRoot = findRoot(dir_id); 
        int idRoot = findRoot(id);
                
		// it can't be equal but should be checked in implementation 
        if (dirRoot == idRoot) return;  
        
        if(size[idRoot] >= size[dirRoot] ){
            roots[dirRoot] = idRoot;
            size[idRoot] += size[dirRoot]; 
        }
        else{
            roots[idRoot] = dirRoot;
            size[dirRoot] += size[idRoot] ; 
        }
        --cnt;
    }
};


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> res;
        UnionFind uf (m * n);
        vector<vector<int>> dirs{{0,-1}, {-1,0}, {0,1}, {1,0}}; // up/down/right/left 
        
        for (auto& pos : positions) {
            int id = n*pos[0] + pos[1]; // array index of position 
            
            if (uf.roots[id] != -1) { 
				// it's not water, connected to an island
                res.push_back(uf.cnt);
                continue;
            }
            
            uf.roots[id] = id; // at first, root is itself
            ++uf.cnt; // at first, we assume it's a new island 
          
            // iteration over up/down/right/left 
            for (auto dir : dirs) {
                int x = pos[0] + dir[0]; 
                int y = pos[1] + dir[1];  
                int dir_id = n * x + y;
        
				// checking the edge conditions
                if (x<0 || x>=m || y<0 || y>=n || uf.roots[dir_id]==-1) 
					continue;
              
                uf.unify(id, dir_id ) ;
            }
            
            res.push_back(uf.cnt);
        }
          
        return res;
    }
};