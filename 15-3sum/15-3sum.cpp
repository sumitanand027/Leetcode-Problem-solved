class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort( nums.begin() , nums.end() );
        int n = nums.size();
        
        vector< vector<int> > ans;
        
        for( int i = 0 ; i < n ; i++ )
        {   
            
            if( i > 0 && nums[i] == nums[i-1] )
                continue;
            
            int l = i + 1;
            int h = n - 1;

            while( l < h )
            {
                if( nums[l] + nums[h] + nums[i] == 0 ) {
                    ans.push_back( {nums[i] , nums[l] , nums[h] } );
                    while ( l < h && nums[l] == nums[l+1] ) l++;
                    while( l < h && nums[h] == nums[h-1] ) h--;
                    l++;
                    h--;
                } else if( nums[l] + nums[h] + nums[i] > 0 ) {
                    h--;
                } else {
                    l++;
                }
            }
        }
        
        return ans;
    }
};