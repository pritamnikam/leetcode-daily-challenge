// 380. Insert Delete GetRandom in O(1).
// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
    vector<int> elements;
    unordered_map<int, int> elementPositionMap;
public:
    RandomizedSet() { 
    }
    
    bool insert(int val) {
        if (elementPositionMap.count(val))
            return false;
        
        elementPositionMap[val] = elements.size();
        elements.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!elementPositionMap.count(val))
            return false;
        
        int index = elementPositionMap[val];
        elements[index] = elements.back();
        elements.pop_back();
        elementPositionMap[elements[index]] = index;
        elementPositionMap.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand() % elements.size();
        return elements[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
