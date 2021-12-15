// LeetCode 366

// Without Sorting, placing item to res in dfs function 
// > Time Complexity: O(N) 
//     tree traversing:O(N) + storing all the pairs:O(N) = O(2N)=O(N)
// > Space Complexity: O(N), solution array 

class Solution {
private:
    int dfs(TreeNode* node, vector<vector<int>>& res){
        if(!node) return 0; 
        // Call dfs on left and right childs, level=(max of them)+1
        int level = max(dfs(node->left, res), 
                        dfs(node->right, res)) + 1;
        
        // level values: 1,2,3, ... 
        if(level > res.size() ) // add level if not found 
            res.push_back(vector<int>());
        
        res[level - 1].push_back(node->val);
        return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res; 
        dfs(root, res);
        return res;
    }
};
