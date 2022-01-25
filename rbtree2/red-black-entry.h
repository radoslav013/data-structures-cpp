#ifndef RB_ENTRY_H
#define RB_ENTRY_H

//! Color enum (RED, BLACK)
/*!
    Color enum (RED, BLACK)
*/
enum Color {RED, BLACK}; // node colors


//! RBEntry class extending Entry class
/*!
    Red black entry class, adding a color to the key and value of Entry
*/
template <typename E>
class RBEntry : public E { // a red-black entry
    private:
        Color col; // node color
    protected: // local types
        typedef typename E::Key K; // key type
        typedef typename E::Value V; // value type

        //! Get color
        /*!
            Get color
            \return       BLACK / RED
        */
        Color color() const { return col; } // get color

        //! Checks if red
        /*!
            Checks if red
            \return       true is red
        */
        bool isRed() const { return col == RED; }

        //! Checks if black
        /*!
            Checks if black
            \return       true if black
        */
        bool isBlack() const { return col == BLACK; }

        //! Set the color
        /*!
            Sets the color RED/BLACK
            \param c      color value
        */
        void setColor(Color c) { col = c; }
    public: // public functions
        //! Constructor
        /*!
            Constructs entry with a key and a value, sets the color to black initially
            \param k      key value
            \param v      data value
        */
        RBEntry(const K& k = K(), const V& v = V()) : E(k,v), col(BLACK) { }

    friend class RBTree<E>; // allow RBTree access
};

#endif