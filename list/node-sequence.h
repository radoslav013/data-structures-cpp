#ifndef NODE_SEQUENCE_H
#define NODE_SEQUENCE_H

template <typename T>
class NodeSequence : public NodeList<T> {
    public:
        typename NodeSequence<T>::Iterator atIndex(int i) const;
        int indexOf(const typename NodeSequence<T>::Iterator& e) const;
};

template <typename T>
typename NodeSequence<T>::Iterator NodeSequence<T>::atIndex(int i) const {
    typename NodeSequence<T>::Iterator r = this->begin();
    for(int c = 0; c < i; c++) {
        ++r;
    }
    return r;
}


template <typename T>
int NodeSequence<T>::indexOf(const typename NodeSequence<T>::Iterator& e) const {
    typename NodeSequence<T>::Iterator p = this->begin();
    int r = 0;

    while(p != e) {
        ++p; ++r;
    }

    return r;
}

#endif