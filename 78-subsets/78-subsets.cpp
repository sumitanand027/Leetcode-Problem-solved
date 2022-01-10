class Solution {
public:
    
    void subset( vector<int> &nums, int j, vector<int> &sub, vector< vector<int> > &subs ) {
        if( j == nums.size() ) {
            subs.push_back( sub );
            return;
        }
        
        subset( nums, j + 1, sub, subs );
        sub.push_back( nums[j] );
        subset( nums, j + 1, sub, subs );
        sub.pop_back();
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > subs;
        vector<int> sub;
        subset( nums, 0 , sub, subs );
        return subs;
    }
};
