class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> sk;
        unordered_map<int,int> m;
        
        for( auto ele : nums2 )
        {
            while( sk.empty() == false && sk.top() < ele ) {
                m[ sk.top() ] = ele;
                sk.pop();
            }
            sk.push( ele );
        }
        
        vector<int> ans;
        for( auto ele : nums1 ) 
        {
            if( m.find( ele ) == m.end() ) {
                ans.push_back( -1 );
            } else {
                ans.push_back( m[ ele ] );
            }
        }
        return ans;
    }
    
};