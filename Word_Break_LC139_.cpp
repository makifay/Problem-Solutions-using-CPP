// LeetCode: 139. Word Break
//  Optimized with Hashset

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
       
        vector<bool> validExcl(s.size() + 1, false);
        validExcl[0] = true;
        
        unordered_set<string> words;
        int maxLen = 0;
        
        for (const auto& word : wordDict) {
            words.insert(word);
            maxLen = max(maxLen, (int)word.size());
        }
        
        for (int i = 0; i <= s.size(); ++i) {
            if (validExcl[i]) 
                for (int j = 1;  j<=maxLen && i+j <= s.size(); ++j) 
                    if ( words.count(s.substr(i, j)) )  validExcl[i + j] = true;
        }
        return validExcl[s.size()];
    }
};
