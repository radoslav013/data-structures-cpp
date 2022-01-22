#ifndef ENTRY_H
#define ENTRY_H

template <typename K, typename V>
class Entry {
    protected:
        typedef K Key; // key type
        typedef V Value; // value type
    public:
        Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}
        const K& key() const { return _key; }
        const V& value() const { return _value; }
        void setKey(const K& k) { _key = k; }
        void setValue(const V& v) { _value = v; }

        // Entry& operator =(const Entry& pos);
    private:
        K _key;
        V _value;
};

// template <typename K, typename V>
// Entry<K, V>& Entry<K, V>::operator =(const Entry& entry) {
//     _key = entry.key();
//     _value = entry.value();
//     return *this;
// }

#endif