class Solution {

private:
    double two_pointer_approach(vector<int>& a, vector<int>& b) {
        int n = static_cast<int>(a.size());
        int n2 =  static_cast<int>(b.size());
        int i = 0, j = 0;
        int u = 0;
        bool odd = (n+n2 & 1);
        int mid = (n+n2) / 2;
        int med = odd ? mid : mid-1;
        int k = 0;
        int l = 0;
        bool kset = false;
        while (u <= mid) {
            if (i < n) {
                if (j < n2) {
                    if (u == med) {
                        if (odd) {
                            return min(a[i], b[j]);
                        } else {
                            k = min(a[i], b[j]);
                            kset = true;
                            if (a[i] <= b[j]) {
                                i++;
                            } else {
                                j++;
                            }
                            u++;
                            continue;
                        }
                    }
                    if (a[i] <= b[j]) {
                        if (kset) {
                            l = min(a[i], b[j]); break;
                        }
                        i++;
                    } else {
                        if (kset) {
                            l = b[j]; break;
                        }
                        j++;
                    }
                } else {
                    if (u == med) {
                        if (odd) {
                            return a[i];
                        } else {
                            k = a[i];
                            kset = true;
                            i++;
                        }
                    } else {
                        if (kset) {
                            l = a[i]; break;
                        }
                        i++;
                    }
                }
            } else {
                if (j < n2) {
                    if (u == med) {
                        if (odd) {
                            return b[j];
                        } else {
                            k = b[j];
                            kset = true;
                        }
                    } else {
                        if (kset) {
                            l = b[j]; break;
                        }
                    }
                    j++;
                }
            }
            u++;
        }
        return (double)(k+l) / 2;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return two_pointer_approach(nums1, nums2);
    }
};