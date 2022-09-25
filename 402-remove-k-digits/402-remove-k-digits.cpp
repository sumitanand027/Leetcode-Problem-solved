class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> sk;
        string res;
        
        for( auto a : num )
        {
            
            while(k && sk.size() && sk.top() > a ) {
                k--;
                sk.pop();
            }
            sk.push( a );
        }

        while( sk.size() ) {
            res.push_back( sk.top() );
            sk.pop();
        }
        
        reverse( res.begin(), res.end() );
        
        while( res.size() && k > 0 ) {
            res.pop_back();
            k--;
        }
        
        int i = 0;
        for( i = 0 ; i < num.size(); i++ ) {
            if( res[i] != '0' ) break;
        }
        
        res = res.substr( i, res.size() -i );
        
        if( res.size() == 0 )
            res.push_back( '0' );
        
        return res;
    }
};