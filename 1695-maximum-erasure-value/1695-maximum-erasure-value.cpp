class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int l = 0 ;
        unordered_map<int,int> m;
        int ans = 0;
        int h;
        int curSum = 0;
        
        for( h = 0 ; h < nums.size() ; h++ )
        {
            curSum += nums[h];
            m[ nums[h] ]++;
            while( m[ nums[h] ] > 1 ) {
                m[ nums[l] ]--;
                curSum -= nums[l];
                l++;
            }
            
            ans = max( ans , curSum );
        }
        
        // cout << m[ nums[4] ] << endl;
        // cout << h << " " << l << endl;
        return ans;
    }
};