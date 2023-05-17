class TimeMap {
public:
    // TimeMap is a map of key to (time, val) pairs
    unordered_map<string, vector<pair<int, string>>> KeyMap;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        KeyMap[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        // if key doesn't exist
        if (KeyMap.find(key) == KeyMap.end()) return "";
        
        // if timestamp occurs before first entry
        if (timestamp < KeyMap[key][0].first) return "";

        int lo = 0;
        int hi = KeyMap[key].size();

        // find rightmost occurence
        while (lo < hi) {
            // cout << "lo: " << lo << " hi: " << hi << "\n";
            int mid = (hi + lo) / 2;

            if (KeyMap[key][mid].first <= timestamp) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        // hi >= 1 because otherwise the second if would have caught

        // we actually looked for one more than the max
        return KeyMap[key][hi - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */