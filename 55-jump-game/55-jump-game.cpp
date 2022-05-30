class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++ )
        {
            step--;
            
            if( step < 0 )
                return false;
            if( nums[i] > step )
                step = max( nums[i] , step );
        }
        return true;
    }
};