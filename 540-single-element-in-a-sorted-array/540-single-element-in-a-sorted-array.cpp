class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        
        while( l <= h ) 
        {
            int md = ( l + h ) >> 1;

            // check if md is the reqired num
            if( (md - 1 < 0 || nums[md - 1] != nums[md]) && (md + 1 >= nums.size() || nums[md + 1] != nums[md] )  ) {
                return nums[md];
            }
            
            // check if md is the first index or the second index
            if( md - 1 < 0 || nums[md-1] != nums[md] ) {
                if( md % 2 == 0 ) {
                    l = md + 1;
                } else {
                    h = md - 1;
                }
            } else {
                if( md % 2 == 1 ) {
                    l = md + 1;
                } else {
                    h = md - 1;
                }
            }
            
        }
        cout << nums[l];
        return nums[l];
    }
};
