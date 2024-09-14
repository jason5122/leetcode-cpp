#include "debugging.h"
#include "leetcode.h"
using namespace std;

/*
USED SOLUTION
*/
class LRUCache {
public:
    LRUCache(int capacity) : n{capacity} {}

    int get(int key) {
        if (hmap.count(key)) {
            reAddToFront(key);
            return hmap[key].second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        // Update value of existing key.
        if (hmap.count(key)) {
            reAddToFront(key);
            hmap[key].second = value;
        }
        // Add new entry.
        else {
            order.push_front(key);
            hmap[key] = {order.begin(), value};

            if (order.size() > n) {
                hmap.erase(order.back());
                order.pop_back();
            }
        }
    }

private:
    unordered_map<int, pair<list<int>::iterator, int>> hmap;
    list<int> order;
    int n;

    void reAddToFront(int key) {
        order.push_front(key);
        order.erase(hmap[key].first);
        hmap[key].first = order.begin();
    }
};

int main() {
    {
        LRUCache lru_cache{2};
        lru_cache.put(1, 1);               // cache is {1=1}
        lru_cache.put(2, 2);               // cache is {1=1, 2=2}
        cout << lru_cache.get(1) << '\n';  // 1
        lru_cache.put(3, 3);               // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        cout << lru_cache.get(2) << '\n';  // -1
        lru_cache.put(4, 4);               // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        cout << lru_cache.get(1) << '\n';  // -1
        cout << lru_cache.get(3) << '\n';  // 3
        cout << lru_cache.get(4) << '\n';  // 4}
    }

    {
        LRUCache lru_cache{2};
        cout << lru_cache.get(2) << '\n';  // -1
        lru_cache.put(2, 6);
        cout << lru_cache.get(1) << '\n';  // -1

        lru_cache.put(1, 5);
        lru_cache.put(1, 2);

        cout << lru_cache.get(1) << '\n';  // 2
        cout << lru_cache.get(2) << '\n';  // 6
    }
}
