class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, maxCnt = 0;
        for( int i = 0; i < nums.size(); i++ ) {
            if( nums[i] == 0 )
                cnt = 0;
            else {
                cnt++;
                maxCnt = max( maxCnt , cnt );
            }
        }
        return maxCnt;
    }
};