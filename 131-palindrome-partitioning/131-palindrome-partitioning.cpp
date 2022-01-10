class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
          if (s[start++] != s[end--])
            return false;
        }
        return true;
  }
    
    void helper( string s, int ind, vector< vector<string>> &res, vector<string> &r ) {
        if( ind == s.size() ) {
            res.push_back( r );
            return;
        }
        
        for( int i = ind ; i < s.size(); ++i ) {
            if( isPalindrome(s, ind, i ) ) {
                r.push_back( s.substr( ind , i - ind + 1 ) );
                helper( s , i + 1 , res , r );
                r.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector< vector<string> > res;
        vector<string> r;
        helper( s, 0, res , r );
        return res;
    }
};