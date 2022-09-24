class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> preMin(n,-1), preMax(n,-1), postMin(n,n), postMax(n,n);
        stack<int> sk;
        
        for( int i = 0; i < nums.size(); i++ ) {
            while( sk.size() && nums[sk.top()] >= nums[i] ) {
                sk.pop();
            }
            if( sk.size() )
                preMin[ i ] = sk.top();
            sk.push(i);
        }
        
        while( sk.size() ) sk.pop();
        
        for( int i = n - 1; i >= 0 ; i-- ) {
            while( sk.size() && nums[sk.top()] > nums[i] ) {
                sk.pop();
            }
            if( sk.size() )
                postMin[ i ] = sk.top();
            sk.push(i);
        }
        
        while( sk.size() ) sk.pop();
        
        for( int i = 0; i < nums.size(); i++ ) {
            while( sk.size() && nums[sk.top()] <= nums[i] ) {
                sk.pop();
            }
            if( sk.size() )
                preMax[ i ] = sk.top();
            sk.push(i);
        }
        
        while( sk.size() ) sk.pop();
        
        
        for( int i = n - 1; i >= 0 ; i-- ) {
            while( sk.size() && nums[sk.top()] < nums[i] ) {
                sk.pop();
            }
            if( sk.size() )
                postMax[ i ] = sk.top();
            sk.push(i);
        }
        
        while( sk.size() ) sk.pop();
        
        long long sum = 0;
        for( int i = 0; i < n; i++ ) {
            long long leftMin=i-preMin[i],rightMin=postMin[i]-i;
            long long leftMax=i-preMax[i],rightMax=postMax[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
        }
        return sum;
    }
};