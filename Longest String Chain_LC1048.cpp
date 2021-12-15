// LeetCode 1048

// Bottom-Up Dynamic Programming; unordered_map and sort 

// N:num. of words, L: max possible length of a word
// Time: O(N (logN + L^2) )
// Space: O(N) : umap

/* Steps: 
- Sort the words by word's length. 
- For each word, loop on all possible previous word with 1 letter missing.
- If previous word has seen, update the longest chain for the current word. */

class Solution {
public :
    int longestStrChain(vector<string> &words) {
        // key: word 
        // value: longest seq. possible with the key as the end
        unordered_map<string, int> um;

        // Sorting the list by word length.
        std::sort(words.begin(), words.end(), 
				  [](const std::string &w1, const std::string &w2) {
				  return w1.size() < w2.size(); // increasing order 
        });

        int longest = 1;

        for (const string &word : words) {
            int currLen = 1;
            int wsize = word.size(); 
            // Find all possible predecessors for the current word 
			// by removing one letter at a time.
            for (int i = 0; i < wsize; i++) {
                // Delete the character at i'th pos 
                string prdcs = word.substr(0,i) + word.substr(i+ 1, wsize+1);
				
                // Check whether um contains predecessor.
                if (um.find(prdcs) != um.end()) 
                    currLen = max(currLen,  um[prdcs]+1);
                
            }
            um[word] = currLen;
            longest = max(longest, currLen);
        }
        return longest;
    }
};