class Solution {
public:
    int largestRectangleArea(vector<int>& h ) {
        int n = h.size();
        vector<int> left(n), right(n);
        
        stack<int> sk;
        int area = 0;
        for(int i = 0; i < n; i++ ) 
        {
            while( !sk.empty() && h[ sk.top() ] >= h[i] )
                sk.pop();
            
            if( sk.empty() ) left[i] = 0;
            else left[i] = sk.top() + 1;
            
            sk.push( i );
        }
        
        while( !sk.empty() ) sk.pop();
        
        for(int i = n-1; i >= 0; i-- ) 
        {
            while( !sk.empty() && h[ sk.top() ] >= h[i] )
                sk.pop();
            
            if( sk.empty() ) right[i] = n - 1;
            else right[i] = sk.top() - 1;
            
            area = max( area,  h[i] * ( right[i] - left[i] + 1 ) );
            sk.push( i );
        }
        return area;
    }
};