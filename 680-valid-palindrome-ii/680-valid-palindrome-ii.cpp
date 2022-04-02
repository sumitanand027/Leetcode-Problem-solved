class Solution {
public:
    
    bool checkPal( string s , int i , int j ) {
        while( i < j ) {
            if( s[i] == s[j] ) i++ , j--;
            else return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int del = 1;
        int i = 0 , j = s.size() - 1;
        while( i < j ) {
            if( s[i] != s[j] ) {
                if( del > 0 ) {
                    del--;
                     if( checkPal( s , i + 1 , j ) || checkPal( s, i , j - 1 ) ) {
                         return true;
                     } else {
                        return false;
                     }
                } else {
                    return false;
                }
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
};