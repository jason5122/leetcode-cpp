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
