#ifndef LIST_COLLECTION_H
#define LIST_COLLECTION_H

/// @brief there is a collection for storing and convinient interaction with list collection

#include "ListIterator.h"
#include <vector>


template <class T>
class ListCollection {
    private:
        std::vector<T> listCollection;
    public:
        explicit ListCollection(const std::vector<T>& _listCollection)
                : listCollection(_listCollection)
            {
            }
        
        std::unique_ptr<ListIterator<T>> getIterator() const {
            return std::make_unique<ListIterator<T>>(listCollection);
        }
        std::unique_ptr<ListReverseIterator<T>> getReverseIterator() const {
            return std::make_unique<ListReverseIterator<T>>(listCollection);
        }

};

#endif //LIST_COLLECTION_H