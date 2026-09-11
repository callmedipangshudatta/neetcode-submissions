class LRUCache {
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        auto it = mp[key];
        int val = it->second;
        l.splice(l.end(),l,it);
        return val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            auto it = mp[key];
            it->second = value;
            l.splice(l.end(), l, it);
            return;
        }

        if (l.size() == cap) {
            mp.erase(l.front().first);
            l.pop_front();
        }

        l.push_back({key, value});
        mp[key] = prev(l.end());
        
    }
};
