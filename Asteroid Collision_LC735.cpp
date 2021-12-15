// LeetCode 735 

// >> Method: 
// make positive values as fixed and negative values now moving, 
//  - Iterate left to right:
// 	When see a positive value, we don't have to do anything
// 	when see a negative value, it's gonna attack to previous positive values.

// Time Complexity: O(N), N:number of asteroids
// Space Complexity: O(N), In the worst case

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; 
      
        for (int v : a) {
            // Collision only when "+-" ; 
            if (s.empty() || v>0 )
                s.push_back(v);
            else { 
                // collision and pos value will explode
                while ( !s.empty() && s.back()>0 && s.back()<-v )z
                      s.pop_back();
                
                 // both will explode when abs values are eq
                 if ( !s.empty() && s.back()==-v ){
                    s.pop_back();
                 } // push if s is empty or pre is neg.
                 else if ( s.empty() || s.back()<0 ) 
                        s.push_back(v);         
            }    
        }
		
        return s;
    }
};