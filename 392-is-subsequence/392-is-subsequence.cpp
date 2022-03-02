class Solution {
public:
    
    bool helper( int i , int j , string s , string t )
    {
        if( i == s.size() ) return true;
        if( j == t.size() ) return false;
        
        bool ans;
        if( s[i] == t[j] )
        {
            ans = helper( i + 1 , j + 1 , s , t );
        } 
        else {
            ans = helper( i , j + 1 , s , t );
        }
        return ans;
    }
    
    bool isSubsequence(string s, string t) {
        return helper( 0 , 0 , s , t );
    }
};