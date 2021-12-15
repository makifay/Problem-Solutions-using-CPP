// LeetCode 792

/* >> Method:
No extra container and push_back vs. operations,
just iterate on the words and apply find on S with pos value */

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        // iteration over words 
        for(int i=0; i<words.size(); i++) {
            int wsize = words[i].size(); 
            int pos=0, j=0; 
            // apply find on S using pos value
            for(; j<wsize; j++) {
                auto ix = s.find(words[i][j], pos);
                if(ix == string::npos) break;
                pos=ix+1;
            }
			
            if(j==wsize) ans++; // all items of word is found
        }
        return ans;
    }
};
