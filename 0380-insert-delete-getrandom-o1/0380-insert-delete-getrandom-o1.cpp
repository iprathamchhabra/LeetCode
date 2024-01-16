class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        auto a = s.insert(val);
        return a.second;
    }
    
    bool remove(int val) {
        auto b = s.erase(val);
        return b;
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */