#ifndef TREE_ITERATOR_H
#define TREE_ITERATOR_H

#include "Iterator.h"
#include "Node.h"
#include <queue>
#include <stack>


/// @brief class that creates an iterator that help to get an element of the tree in level-order way
/// @exception exception can be thrown only in getNext function, if user tries to get elements that doesn't exist
template<class T>
class LevelOrderTreeIterator : public Iterator<T> {
    private:
        std::queue<Node<T>*> q;
    public:
        explicit LevelOrderTreeIterator(const ptrNode<T>& root)
        {
            q.push(root.get());
        }
        bool hasNext() const override {
            return !q.empty();
        }
        T getNext() override {
            if(q.empty()) {
                throw std::out_of_range("There are no more elements left. You try to get a non-excistent element");
            }
            Node<T>* tempNode = q.front();
            q.pop();
            if(tempNode->left != nullptr) {
                q.push((tempNode->left).get());
            } 
            if(tempNode -> right != nullptr) {
                q.push((tempNode -> right).get());
            }
            return tempNode -> value;
        }
};


/// @brief class that creates an iterator that help to get an element of the tree in pre-order way
/// @exception exception can be thrown only in getNext function, if user tries to get elements that doesn't exist
template<class T>
class PreOrderTreeIterator : public Iterator<T>{
    private:
        std::stack<Node<T>*> stack;
    public:
        explicit PreOrderTreeIterator(const ptrNode<T>& root)
        {
            stack.push(root.get());
        }
        bool hasNext() const override {
            return !stack.empty();
        }
        T getNext() override {
            if(stack.empty()) {
                throw std::out_of_range("There are no more elements left. You try to get a non-excistent element");
            }
            Node<T>* tempNode = stack.top();
            stack.pop();
            if(tempNode -> right != nullptr) {
                stack.push((tempNode -> right).get());
            }
            if(tempNode -> left != nullptr) {
                stack.push((tempNode -> left).get());
            }
            return tempNode -> value;
        }
};

/// @brief the class that creates an iterator, that helps to get elements of the tree in-order way
/// @exception exception can be thrown only in getNext function, if user tries to get elements that doesn't exist
template<typename T>
class InOrderTreeIterator : public Iterator<T> {
    private:
        std::stack<Node<T>*> stack;

        void pushLeftSideOfTheTree(Node<T>* node) {
            while(node) {
                stack.push(node);
                node = (node->left).get();
            }
        }
    public:
        explicit InOrderTreeIterator(const ptrNode<T>& root)
        {
            pushLeftSideOfTheTree(root.get());
        }
        bool hasNext() const override {
            return !stack.empty();
        }
        T getNext() override {
            if(!hasNext()){
                throw std::out_of_range("There are no more elements left. You try to get a non-excistent element");
            }
            Node<T>* tempNode = stack.top();
            stack.pop();

            pushLeftSideOfTheTree((tempNode -> right).get());
            return tempNode -> value;
        }
};


/// @brief the class that creates an iterator that allows to get elements in post-order way
/// @exception the class can throw an exception if: 
/// < 1) the user tries to get next element that doesn't exist
/// < 2) the function getNext will terminate execution unexpectedly 
template<class T>
class PostOrderTreeIterator : public Iterator<T> {
    private:
        std::stack<Node<T>*> stack;
        Node<T>* lastViewed = nullptr;

        void pushAllLeft(Node<T>* node) {
            while (node)
            {
                stack.push(node);
                node = node -> left.get();
            }
        }
    public:
        explicit PostOrderTreeIterator(const ptrNode<T>& root) 
        {
            pushAllLeft(root.get());
        }
        bool hasNext() const override {
            return !stack.empty();
        }
        T getNext() override {
            if(!hasNext()) {
                throw std::out_of_range("There are no more elements left. You try to get a non-excistent element");
            }
            while(!stack.empty()) {
                Node<T>* tempNode = stack.top();

                if(tempNode -> right && lastViewed != tempNode -> right.get()) {
                    pushAllLeft(tempNode->right.get());
                } else {
                    stack.pop();
                    lastViewed = tempNode;
                    return tempNode -> value; 
                }
            }
            throw std::logic_error("UB of getNext function in PostOrderTreeIterator class");
        }
};

/// @brief class that creates an iterator, that allows to get elements in reverse order
/// @param the constructor of the class takes a pointer to the root of the tree 
template<class T>
class ReverseInOrderTreeIterator : public Iterator<T> {
    private:
        std::stack<Node<T>*> stack;

        void pushAllRight(Node<T>* node) {
            while(node) {
                stack.push(node);
                node = (node -> right).get();
            }
        }
    public:
        explicit ReverseInOrderTreeIterator(const ptrNode<T>& root)
        {
            pushAllRight(root.get());
        }
        bool hasNext() const override {
            return !stack.empty();
        }
        T getNext() override {
            Node<T>* tempNode = stack.top();
            stack.pop();
            pushAllRight((tempNode -> left).get());
            return tempNode -> value;
        }
};

#endif // TREE_ITERATOR_H