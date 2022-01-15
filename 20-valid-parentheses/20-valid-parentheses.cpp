class Solution {
public:
    bool isValid(string s) {
        stack <char> sk;
        
        for( auto c : s ) {
            if( c == '(' || c == '{' || c == '[' ) {
                sk.push( c );
            } else if( c == ')' ) {
                if( sk.empty() || sk.top() != '(' ) 
                    return 0;
                sk.pop();
            } else if( c == '}' ) {
                if( sk.empty() || sk.top() != '{' ) 
                    return 0;
                sk.pop();
            } else if( c == ']' ) {
                if( sk.empty() || sk.top() != '[' ) 
                    return 0;
                sk.pop();
            }
        }
        if( sk.empty() ) 
            return true;
        return false;
    }
};