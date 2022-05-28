class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAns = nums[0];
        
        int curSum = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) {
            curSum += nums[i];
            
            maxAns = max( curSum , maxAns );
            if( curSum < 0 )
                curSum = 0;
            
        }
        
        return maxAns;
    }
};