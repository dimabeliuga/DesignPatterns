#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdexcept>

/// @brief pure virtual class that describes functions that every iterator must have
template<class T>
class Iterator {
    public:
        virtual ~Iterator() = default;
        virtual bool hasNext() const = 0;
        virtual T getNext() = 0;
};

#endif // ITERATOR_H

/* example of usage
template<typename T>
void outputTree(Iterator<T>* treeIterator) {
    while (treeIterator-> hasNext()) {
        std::cout << treeIterator -> getNext() << "  " ;
    }
    std::cout << std::endl;
}

template<typename T>
void outputList(Iterator<T>* listIterator) {
    while (listIterator-> hasNext()) {
        std::cout << listIterator -> getNext() << "  " ;
    }
    std::cout << std::endl;
}
int main() {
    NodeCollection<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Level order Iterator: " << std::endl;
    outputTree((bst.getLevelOrderIterator()).get());

    std::cout << "Pre order Iterator: " << std::endl;
    outputTree((bst.getPreOrderIterator()).get());

    std::cout << "In order Iterator: " << std::endl;
    outputTree((bst.getInOrderIterator()).get());

    std::cout << "Post order Iterator: " << std::endl;
    outputTree((bst.getPostOrderIterator()).get());

    std::cout << "Reverse order Iterator: " << std::endl;
    outputTree((bst.getReverseInOrderIterator()).get());

    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    ListCollection<int> list(vec);
    
    std::cout << "Normal list iterator:" << std::endl;
    outputList((list.getIterator()).get());

    std::cout << "Reverse list iterator: " << std::endl;
    outputList((list.getReverseIterator()).get());
}
*/