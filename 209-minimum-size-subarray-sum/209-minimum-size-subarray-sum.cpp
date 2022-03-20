class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int sum = 0;
        int ans = INT_MAX;
        int i = 0;
        
        for( int j = 0 ; j < nums.size() ; j++ )
        {
            sum += nums[j];
            while( i <= j && sum >= target )
            {
                if( j - i + 1 < ans ) {
                    ans = j -i + 1;
                }
                sum -= nums[i++];
            }
            
        }
        
        if( ans == INT_MAX )
            return 0;
        return ans;
    }
};