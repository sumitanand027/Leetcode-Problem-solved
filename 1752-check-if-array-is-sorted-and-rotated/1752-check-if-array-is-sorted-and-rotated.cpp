class Solution {
public:
    
    bool check(vector<int>& nums) {
        
        int no = 0;
        for( int i = 1; i < nums.size() ; i++ )
            if( nums[i-1] > nums[i] ) {
                no++;
            }
        
        if( no > 1 )
            return 0;
        
        int flag = 1;
        
        for( int i = 1; i < nums.size() ; i++ )
        {
            if( nums[i-1] > nums[i] ) {
                if(nums[i] > nums[0] || nums[ nums.size() - 1] > nums[0]) 
                    flag = 0;
                break;
            }
        }
        
        return flag;
    }
};