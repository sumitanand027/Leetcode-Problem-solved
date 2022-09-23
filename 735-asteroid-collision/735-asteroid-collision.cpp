class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast ) {
        stack<int> sk;
        
        for( auto a : ast ) {
            while( sk.size() && sk.top() >= 0 && a < 0 && sk.top() < abs(a) ) {
                sk.pop();
            } 
            
            if( sk.empty() ) {
                sk.push( a );
            } else {
                if( sk.top() < 0 ) {
                    sk.push( a );
                } else if( sk.top() >= 0 && a >= 0) {
                    sk.push( a );
                } else {
                    if( abs( sk.top() == abs(a) ) ) {
                        sk.pop();
                    }
                }
            }
        }
        
        vector<int> ans;
        
        while( sk.size() ) {
            ans.push_back( sk.top() );
            sk.pop();
        }
        
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};