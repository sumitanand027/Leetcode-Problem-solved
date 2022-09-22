class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack< int > sk;
        vector<int> ans( nums.size(), -1);
        
        for( int i = 0; i < 2 * nums.size()- 1; i++ )
        {
            while( !sk.empty() && nums[sk.top()] < nums[i%nums.size()] ) {
                ans[sk.top()] = nums[i%nums.size()];
                sk.pop();
            }
            sk.push( i % nums.size() );
        }
        
        return ans;
        
    }
};