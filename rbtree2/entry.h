#ifndef ENTRY_H
#define ENTRY_H

//! Entry base class
/*!
    Provides get and set functionalities for key and value pair
*/
template <typename K, typename V>
class Entry {
    public:
        typedef K Key;
        typedef V Value;
    public:
        //! Constructor
        /*!
            Constructs entry with a key and a value
            \param k      key value
            \param v      data value
        */
        Entry(const K& k = K(), const V& v = V()) : _key(k), _value(v) {}

        //! Get key
        /*!
            Get key
            \return       key
        */
        const K& key() const { return _key; }

        //! Get value
        /*!
            Get value
            \return       value
        */
        const V& value() const { return _value; }

        //! Set a key
        /*!
            Set a key
            \param k      key value
        */
        void setKey(const K& k) { _key = k; }

        //! Set a value
        /*!
            Set a value
            \param v      data value
        */
        void setValue(const V& v) { _value = v; }
    private:
        K _key;
        V _value;
};

#endif