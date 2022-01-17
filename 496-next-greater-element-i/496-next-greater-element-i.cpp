class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> sk;
        unordered_map<int,int> m;
        for( auto ele : nums2 ) 
        {
            while( sk.size() && sk.top() < ele ) {
                m[sk.top() ] = ele;
                sk.pop();
            }
            sk.push( ele );
        }
        vector<int> ans;
        for( auto ele : nums1 ) 
        {
            ans.push_back( m.count( ele ) ? m[ele] : -1 );
        }
        return ans;
    }
};