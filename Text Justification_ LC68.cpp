// LeetCode 68 

// 2 pointer approach, 1 main loop and 2 small inner loop 
// Time: O( lines * maxWidth ) 
// Space: O( lines * maxWidth )

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int wsize = words.size() ; 
         // 2 pointer for process: i and j 

        for(int i = 0, j; i < wsize; i = j) {
            int width = 0;
            // advance j pointer
            for(j = i; j < wsize && (width + words[j].size() + j - i <= maxWidth) ; j++) {
                width += words[j].size();
            }
            
            int space = 1; // default space=1
            int extra = 0; // default extra=0
            // don't enter if single word or it's last line 
             if( j-i!=1 && j!=wsize ) {
                // j - i - 1: spaces count 
                space = (maxWidth - width) / (j-i-1);
                extra = (maxWidth - width) % (j-i-1);
            }
            
            // >> composing the line string
            string line(words[i]); 
            for(int k = i + 1; k < j; k++) {
                line += string(space, ' ');
                if(extra-- > 0) {
                    line += " ";
                }
                line += words[k];
            }
            
            line += string(maxWidth - line.size(), ' ');
            // push the line str to result vector 
            result.push_back(line);
        }
        return result;
    }
};