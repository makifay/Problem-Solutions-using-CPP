// LeetCode 833 

// >> Approach: Hashmap, No Sorting

// Time: O(n), n:string size 
//     - umap find is constant(average case) 
// Space: O(m), m: size of indexes

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // hashmap, < index, <size, target> >
        unordered_map<int, pair<int, string> > um;
        
        for(int i=0; i<indexes.size(); ++i)
            if( S.substr(indexes[i], sources[i].size()) == sources[i] )
				um[indexes[i]] = make_pair(sources[i].size(), targets[i]);
        
        string ans="";
        for(int i=0; i<S.size(); ++i){
            // if found, add target to ans, advance i with (size-1)
            if(um.find(i)!=um.end()){
                ans += um[i].second;
                i = i+um[i].first-1;
            }
            else // not found, directly add normal char of str 
                ans += S[i];
        }
		
        return ans;
    }
};

