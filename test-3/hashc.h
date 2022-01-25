#ifndef HASH_C
#define HASH_C

class HashCode {
    public:

        //! Overloaded operator () 
        /*!
            Return the hash code for the given floating-point number.
            \param num      floating-point number
            \return         the calculated hash code
         */
        long operator ()(const double& num);

        //! Overloaded operator () 
        /*!
            Return the hash code of the input string.
            \param carr     pointer to the char array
            \param len      number of chars 
            \return         the calculated hash code
         */
        long operator ()(const char *carr, int len);

    private:
        /*!< polynomial */ 
        static const int VAR;       
};

#endif