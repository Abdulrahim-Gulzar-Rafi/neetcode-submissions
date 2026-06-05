class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int N = static_cast<int>(people.size());
        sort(people.begin(), people.end());
        unordered_set<int> checked;
        int boats = 0;
        for (int i = 0; i < N; i++) {
            if (!checked.count(i)) {
                int target = limit - people[i];
                auto it = upper_bound(people.begin() + i, people.end(), target);
                if (it != people.begin()) {
                    --it;
                    int index = it - people.begin();
                    while (index > i && checked.count(index)) {
                        index --;
                    }
                    if (index > i) {
                        checked.insert(index);
                        checked.insert(i);
                    }
                }
                boats ++;
            }
        }
        return boats;
    }
};