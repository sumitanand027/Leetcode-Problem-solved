class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0] , temp_sum = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++ )
        {
            temp_sum += nums[i];
            if( temp_sum < nums[i] )
            {
                temp_sum = nums[i];
            }
            if( temp_sum >= max_sum )
            {
                max_sum = temp_sum;
            }
        }
        return max_sum;
    }
};