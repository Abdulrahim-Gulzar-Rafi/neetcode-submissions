class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int> pq;
        for (const int& i: nums) {
            pq.insert(i);
        }
        return vector(pq.begin(), pq.end());
    }
};