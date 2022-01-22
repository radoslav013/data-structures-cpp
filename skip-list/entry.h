#ifndef ENTRY_H
#define ENTRY_H

//! Entry class
/*!
    Entry class holding key and value
*/
template <typename K, typename V>
class Entry {
    protected:
        //! Key and Value
        /*!
            Key and Value to be accessible in derived classes
         */
        typedef K Key; // key type
        typedef V Value; // value type
    public:
        //! Default constructor
        /*!
            Constructs entry
            \param k      key value
            \param v      data value
         */
        Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}

        //! Get key
        /*!
            Returns key
            \return key
         */
        const K& key() const { return _key; }

        //! Get value
        /*!
            Returns value
            \return value
         */
        const V& value() const { return _value; }

        //! Sets key
        /*!
            Sets the key
            \param k Key
         */
        void setKey(const K& k) { _key = k; }

        //! Sets value
        /*!
            If an entry with the provided key already exists, replace the provided data value.
            Otherwise, append the new key-data value pair in the map list.
            \param val Value
         */
        void setValue(const V& v) { _value = v; }
    private:
        K _key;
        V _value;
};

#endif