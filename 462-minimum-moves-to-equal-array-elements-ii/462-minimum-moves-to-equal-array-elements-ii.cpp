class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        
        // for( auto &a : nums ) {
        //     sum += a;
        // }
        sort( nums.begin(), nums.end() );
        
        int med = nums[ nums.size() / 2 ];
        int ans = 0;
        int temp = 0;
        for( auto &a : nums ) {
            temp += abs( a - med );
        }
        
        ans = temp;
        temp = 0;
        med++;
        
        for( auto &a : nums ) {
            temp += abs( a - med );
        }
        
        ans = min( ans , temp );
        return ans;
    }
};