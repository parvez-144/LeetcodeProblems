class RandomizedSet {
public:
set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool flag =false;
        if(!s.count(val))flag=true;
        s.insert(val);
        return flag;
    }
    
    bool remove(int val) {
        if(s.count(val)){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand()%s.size();
      auto it = s.begin();
       for (int i = 0; i < idx; i++)
       {
             it++;
      }
            return *it;
    }   
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */