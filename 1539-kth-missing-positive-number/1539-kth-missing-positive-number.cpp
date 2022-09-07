class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int l = 0, r = A.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (A[m] -m - 1 < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
    
};