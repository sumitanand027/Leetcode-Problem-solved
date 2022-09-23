class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,-1), right(n,n);
        
        for( int i = 0; i < n; i++ ) {
            left[i] = i;
            right[i] = n - i - 1;
        }
        stack<int> sk;
        for( int i = 0; i < nums.size(); i++ ) {
            while( sk.size() && nums[sk.top()] > nums[i] ) {
                right[sk.top()] = i - sk.top() - 1;
                sk.pop();
            }
            sk.push(i);
        }
        
        while( sk.size() ) sk.pop();
        
        for( int i = n - 1; i >= 0; i-- ) {
            while( sk.size() && nums[sk.top()] >= nums[i] ) {
                left[sk.top()] = sk.top() - 1 - i;
                sk.pop();
            }
            sk.push(i);
        }
        
        int ans = 0;
        int mod = 1e9 + 7;
        for( int i = 0; i < n; i++ ) {
            ans += ( 1LL * nums[i] * ( left[i] + 1 ) * ( right[i] + 1 ) ) % mod;
            ans = ans % mod;
        }
        return ans;
    }
};