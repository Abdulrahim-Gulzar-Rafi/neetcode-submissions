class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int N = static_cast<int>(arr.size());
        auto it = lower_bound(arr.begin(), arr.end(), x);
        deque<int> answer;
        if (it == arr.end()) {
            for (int i = N-k; i < N; i++) {
                answer.push_back(arr[i]);
            }
            return vector<int>(answer.begin(), answer.end());
        }
        if (it == arr.begin()) {
            for (int i = 0; i < k; i++) {
                answer.push_back(arr[i]);
            }
            return vector<int>(answer.begin(), answer.end());
        }
        int index = it - arr.begin();
        if (index -1 >= 0) {
            if (abs(arr[index-1] - x) <= abs(arr[index] - x)) {
                index --;
            }
        }
        int left = index, right = index;
        while (k --) {
            if (left < 0) {
                answer.push_back(arr[right]);
                right ++;
            } else if (right >= N) {
                answer.push_front(arr[left]);
                left --;
            } else {
                int left_diff = abs(arr[left] - x), right_diff = abs(arr[right] - x);
                if (left_diff <= right_diff) {
                    answer.push_front(arr[left]);
                    if (left == right) {
                        right ++;
                    }
                    left --;
                } else {
                    answer.push_back(arr[right]);
                    if (left == right) {
                        left --;
                    }
                    right ++;
                }
            }
        }
        return vector<int>(answer.begin(), answer.end());
    }
};