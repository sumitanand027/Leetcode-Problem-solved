class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack <char> sk , st;
        
        for( auto a : s )
        {
            if( a != '#' ) {
                sk.push( a );
            } else {
                if( !sk.empty() )
                    sk.pop();
            }
        }
        
        for( auto a : t ) {
            if( a != '#' ) {
                st.push( a );
            } else {
                if( !st.empty() )
                    st.pop();
            }
        }
        
        while( !sk.empty() && !st.empty() )
        {
            char t1 = sk.top();
            char t2 = st.top();
            
            if( t1 != t2 ) return false;
            
            sk.pop();
            st.pop();
        }
        
        if( !sk.empty() || !st.empty() )
            return false;
        
        return true;
    }
};



