class Solution {
public:
    
    void helper( vector<int> nums , int j , vector< vector<int> > &ans  )
    {
        if( j == nums.size() )
        {
            ans.push_back( nums );
            return;
        }
        
        for( int i = j ; i < nums.size() ; i++ ) {
            if( i != j && nums[i] == nums[j] ) continue;
            swap( nums[i] , nums[j] );
            helper( nums , j + 1 , ans );
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int> > ans;
        sort( nums.begin() , nums.end() );
        helper( nums , 0 , ans );
        
        return ans;
    }
    
};