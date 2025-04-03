#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Iterator.h"
#include <vector>
#include <memory>

template<class T>
class ListBaseIterator : public Iterator<T> {
    protected:
        const std::vector<T>& collection;
        size_t curentIndex;
    public:
        explicit ListBaseIterator(const std::vector<T>& _collection)
                        : collection(_collection), curentIndex(0)
                {
                }
        virtual bool hasNext() const override {
            return curentIndex < collection.size();
        }
        T getNext() override {
            return collection.at(curentIndex++);
        }
};
template<class T>
class ListIterator : public ListBaseIterator<T> {
    public:
        using ListBaseIterator<T>::ListBaseIterator;
};

template<typename T>
class ListReverseIterator : public ListBaseIterator<T> {
    public:
        using ListBaseIterator<T>::ListBaseIterator;

        T getNext() override {
            // it doesn't need extra check, because std::vector<T>::at will throw this exception anyway
            // if(!this->hasNext()) throw std::out_of_range("Error");
            return collection.at((collection.size() - 1) - (curentIndex++));
        }
}; 
#endif // LIST_ITERATOR_H