class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if( nums.size() == 1 )
            return 1;
        
        int diff = nums[1] - nums[0];
        int cnt = diff != 0 ? 2 : 1;
        
        for( int i = 2 ; i < nums.size() ; i++ ) {
            int cur = nums[i] - nums[i-1];
            if( ( diff <= 0 && cur > 0 ) || ( diff >= 0 && cur < 0 )) {
                diff = cur;
                cnt++;
            }
        }
        return cnt;
    }
};