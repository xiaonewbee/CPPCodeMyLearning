// Note: c++17 required.

template<typename K, typename V, std::size_t Capacity> class LRUCache
{
public:
    // Assert that Max size is greater than 0
    static_assert(Capacity > 0);

    // Adds a <key, Val> item, Returns false if key already exists
    bool put(const K& k, const V& v);

    // Gets the value for a key.
    // Returns empty std::optional if not found.
    // The returned item becomes most-recently-used
    std::optional<V> get(const K& k);

    // Erases an item
    void erase(const K& k);

    // Utility function.
    // Calls callback for each {key, value}
    template<typename C> void forEach(const C& cb) const
    {
        for (auto& [k, v] : items) {
            cb(k, v);
        }
    }

private:
    // std::list stores items (pair<K, V>) in most-recently-used to least-recently-used order
    std::list<std::pair<K, V>> items;

    // unordered_map acts as an index to the items store above.
    std::unordered_map<K, typename std::list<std::pair<K, V>>::iterator> index;
};
