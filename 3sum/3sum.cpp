class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() < 3 ) return {};
        sort( nums.begin(), nums.end() );
        
        vector< vector<int> > ans;
        for( int i = 0; i < nums.size() - 2; i++ )
        {
            for( int j = i + 1; j < nums.size()- 1; j++ )
            {
                int req = -(nums[i] + nums[j]);
                int l = j + 1;
                int h = nums.size() - 1;
                while( l <= h )
                {
                    int m = ( l + h ) / 2;
                    if( nums[m] == req ) {
                        ans.push_back( {nums[i] , nums[j] , nums[m]} );
                        break;
                    } else if( nums[m] < req ) {
                        l = m + 1;
                    } else {
                        h = m - 1;
                    }
                }
                while( j < nums.size() - 1 && nums[j] == nums[j+1]) j++;
            }
            while( i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};