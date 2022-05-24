class Solution {
public:
    
    int helper( int pre , int ind , vector<int> &nums , vector< vector<int> > &dp )
    {
        if( ind == nums.size() )
            return 0;
        
        if( dp[pre + 1][ind] != -1 )
            return dp[pre + 1][ind];
        
        int ans1 = 0;
        int ans2 = 0; 
        
//         if( nums[ind] <= nums[pre] )
//             ans1 = helper( ind , ind + 1 , 1  , nums , dp );
//         else {
//             ans1 = helper( ind , ind + 1 , count + 1 , nums , dp );
//         }
        
//         ans2 = helper( pre , ind + 1 , count , nums , dp );
        
        ans1 = helper( pre , ind + 1 , nums , dp );
        
        if( pre == -1 || nums[ind] > nums[pre] )
            ans2 = 1 + helper( ind , ind + 1 , nums , dp );
        
        return dp[ pre + 1 ][ind] = max( ans1 , ans2 );
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector< vector<int> > dp( nums.size() + 1 , vector<int> ( nums.size() + 1 , -1 ) );
        return helper( -1 , 0  , nums , dp );
    }
};