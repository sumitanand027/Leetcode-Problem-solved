class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // not a two pointer question
        
        unordered_map< int, int> m;
        int sum = 0, ans = 0;
        m[ sum ] = 1;
        for( auto it : nums ) {
            sum += it;
            int find = sum - k;
            if( m.find( find ) != m.end() ) {
                ans += m[ find ];
            }
            m[ sum ]++;
        }
        return ans;
    }
    
};