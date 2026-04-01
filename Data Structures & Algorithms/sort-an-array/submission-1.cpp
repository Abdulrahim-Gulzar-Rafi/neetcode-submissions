class Solution {
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            vector<int> temp;
            int p1 = left, p2 = mid + 1;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    temp.push_back(nums[p2]);
                    p2 ++;
                } else if (p2 > right) {
                    temp.push_back(nums[p1]);
                    p1 ++;
                } else {
                    if (nums[p1] < nums[p2]) {
                        temp.push_back(nums[p1]);
                        p1 ++;
                    } else {
                        temp.push_back(nums[p2]);
                        p2 ++;
                    }
                }
            }
            for (int i = left, j = 0; i <= right; i++, j++) {
                nums[i] = temp[j];
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
