/* LeetCode 540 with XOR usage
TiO(logn)  */

int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right){
            mid = left + (right-left)/2;    
            if(nums[mid]==nums[mid^1])  left=mid+1; 
            else right = mid; 
        }
        return nums[left];
}
