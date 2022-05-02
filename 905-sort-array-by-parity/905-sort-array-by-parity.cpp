class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        
        for( auto x : nums )
        {
            if( x % 2 == 0 )
                even.push_back( x );
            else
                odd.push_back( x );
       }
        
        vector<int> ans;
        for( auto x : even ) {
            ans.push_back( x );
        }
        for( auto x : odd ) {
            ans.push_back( x );
        }
        return ans;
    }
};