class TimeMap {
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!mp.count(key)) {
            return "";
        }
        vector<pair<int,string>>& bin = mp[key];
        const int N = static_cast<int>(bin.size());
        int left = 0, right = N - 1;
        while (left <= right) {
            const int mid = (left + right) / 2;
            if (bin[mid].first == timestamp) {
                return bin[mid].second;
            }
            if (left == right) {
                if (bin[left].first < timestamp) {
                    return bin[left].second;
                }
                return "";
            }
            if (timestamp < bin[mid].first) {
                if (mid -1 >= 0 && bin[mid-1].first <= timestamp) {
                    return bin[mid-1].second;
                }
                right = mid - 1;
            } else {
                if (mid+1 < N && bin[mid+1].first > timestamp) {
                    return bin[mid].second;
                }
                left = mid + 1;
            }
        }
        return "";
    }

};
