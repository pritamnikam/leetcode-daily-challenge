// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/description/

using namespace std;

namespace {
class MyHashMap {
  struct KV {
    int key;
    int value;
  };

  const int kMax = 1000011;
  KV db[kMax];


public:
  MyHashMap() {
    for (int i = 0; i < kMax; i++) db[i] = -1;
  }

  void put(int key, int value) {
    int id = key % kMax;
    db[id].key = key;
    db[id].value = value;
  }

  int get(int key) {
    int id = key % kMax;
    if (db[id].key == -1) return -1;
    return db[id].value;
  }

  int remove(int key) {
    int id = key % kMax;
    db[id].key = -1;
  }
};

}
