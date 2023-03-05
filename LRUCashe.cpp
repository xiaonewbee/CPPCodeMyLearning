#include <iostream>
#include <unordered_map>
#include <mutex>
#include <list>

template <typename K, typename V>
class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity) {}

    bool get(const K& key, V& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = map_.find(key);
        if (it == map_.end()) {
            return false;
        }

        auto& node = it->second;
        list_.splice(list_.begin(), list_, node);
        value = node->second;
        return true;
    }

    void put(const K& key, const V& value) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = map_.find(key);
        if (it != map_.end()) {
            it->second->second = value;
            list_.splice(list_.begin(), list_, it->second);
            return;
        }

        if (map_.size() == capacity_) {
            auto last = list_.back();
            map_.erase(last.first);
            list_.pop_back();
        }

        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }

private:
    int capacity_;
    std::list<std::pair<K, V>> list_;
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> map_;
    std::mutex mutex_;
};

int main()
{
    // City -> Population in millions (Max size 3)
    LRUCache<std::string, double> cache(3);


    return 0;
}