void touch(unordered_map<int, pair<int, int>>::iterator it, int f){
        int key = it->first;
        record[f].erase(location[key]);
        if(record[f].size() == 0) record.erase(f);
        record[f+1].push_front(key);
        location[key] = record[f+1].begin();
        return;
    }
    
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cap == 0) return -1;
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        touch(it, it->second.second);
        it->second.second += 1;
        return it->second.first;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        auto it = cache.find(key);
        if(it != cache.end()){
            it->second.first = value;
            touch(it, it->second.second);
            it->second.second += 1;
        }
        else{
            if(cache.size() == cap){
                int LFLR = record.begin()->second.back();
                record.begin()->second.pop_back();
                cache.erase(LFLR);
                location.erase(LFLR);
            }
            cache[key] = {value, 1};
            record[1].push_front(key);
            location[key] = record[1].begin();
        }
        return;
    }