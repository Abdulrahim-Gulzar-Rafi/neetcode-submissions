class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int u = m-1, v = n-1;
        while (u >= 0 && nums1[u] == 0) {
            u--;
        }
        for (int i = m + n -1; i >= 0; i--) {
            if (u >= 0 && v >= 0) {
                if (nums1[u] > nums2[v]) {
                    nums1[i] = nums1[u];
                    u--;
                } else {
                    nums1[i] = nums2[v];
                    v--;
                }
            } else if (u >= 0) {
                nums1[i] = nums1[u];
                u--;
            } else {
                nums1[i] = nums2[v];
                v--;
            }
        }
    }
};