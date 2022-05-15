class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0 , hi = nums.size() - 1;
        
        
        while( lo <= hi )
        {
            int mid = ( hi - lo ) / 2 + lo;
            
            if( nums[lo] <= nums[hi] )
                return nums[lo];
            
            if( nums[lo] <= nums[mid] ) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return nums[lo];
    }
};