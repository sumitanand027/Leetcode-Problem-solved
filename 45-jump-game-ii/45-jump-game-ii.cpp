class Solution {
public:
    int jump(vector<int>& nums) {
        
        int start = 0 , end = 0 , steps = 0;
        
        while( end < nums.size() - 1 )
        {
            steps++;
            int maxs = end + 1;
            
            for( int j = start ; j < nums.size() && j <= end; j++ )
            {
                if( nums[j] + j >= nums.size() )
                    return steps;
                maxs = max( maxs , nums[j] + j );
            }
            start = end + 1;
            end = maxs;
        }
        
        return steps;
    }
};