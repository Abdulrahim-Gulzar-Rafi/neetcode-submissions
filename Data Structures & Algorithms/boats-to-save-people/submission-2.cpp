class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int N = static_cast<int>(people.size());
        sort(people.begin(), people.end());
        int left = 0, right = N-1;
        int boats = 0;
        while (left <= right) {
            boats ++;
            if (left == right) {
                break;
            }
            if (people[right] == limit) {
                right --;
            } else {
                if (people[left] + people[right] > limit) {
                    right --;
                } else {
                    left ++;
                    right --;
                }
            }
        }
        return boats;
    }
};