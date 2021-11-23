// LeetCode-4
// Partition is based on binary search logic

/* Time complexity is O( log(min(m,n) )
 * Space complexity is O(1)             */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        
	// Take minimum sized, input1 should be smaller
	if(m>n)  return findMedianSortedArrays(nums2,nums1);
		
        int low=0,high=m, indexSum=(m+n+1)/2;
        
        while(low<=high){
	   // cut first array at i, second array at indexSum- i
            int partX = (low+high)/2;
            int partY = indexSum-partX;
      
	    // if part=0, nothing is on left side. Use -INF for maxLeft
            // if part=input size, nothing is on right side. Use +INF for minRight
            int mxlftX = (partX==0)? INT_MIN:nums1[partX-1]; // -1 means left 
            int mnRghtX= (partX==m)? INT_MAX:nums1[partX];
            int mxlftY = (partY==0)? INT_MIN:nums2[partY-1];
            int mnRghtY= (partY==n)? INT_MAX:nums2[partY];
			
	    // CROSS-CHECK should be applied
            if( mxlftX<=mnRghtY && mxlftY<=mnRghtX ){
                if((m+n)%2==0) //Even, avg( max of lefts, min of rights )
                    return (double)( max(mxlftX,mxlftY) + min(mnRghtX,mnRghtY) )/2;
                else  // Odd items, max of left ones 
                    return (double)(max(mxlftX,mxlftY));
					
            }else if(mxlftX>mnRghtY) // X value is big, move left
                high=partX-1;
            else // X value is small, move right
                low=partX+1;
        }
        return -1.0;
    }
  
};
