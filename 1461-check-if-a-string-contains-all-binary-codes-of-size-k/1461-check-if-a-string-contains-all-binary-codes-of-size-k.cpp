class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if( k > s.size() )
            return false;
        
        unordered_set<string> st;
                
        for( int i = 0 ; i <= (s.size() - k) ; i++ )
        {
            string t = s.substr( i , k );
            st.insert( t );
        }
        
        int tot = 1 << k;
        // cout << tot << endl;
        
        if( tot == st.size() )
            return true;
        
        return false;        
    }
};