#ifndef TREE_COLLECTION_H
#define  TREE_COLLECTION_H

#include "TreeIterator.h"
#include "Node.h"
#include <memory>

template<class T>
class NodeCollection {
    private:
        ptrNode<T> root;

        /// @brief insert function. It will be called via other function in public section
        void insert(ptrNode<T>& node, const T& value) {
            if(!node) {
                node = std::make_unique<Node<T>>(value);
            } else if(value < node -> value) {
                insert(node -> left, value);
            } else { //value > node -> value 
                insert(node -> right, value);
            }
        }
        /// @brief function for searching whether there is an element that equals the value or not
        /// @return true - there is a value in the tree, false - there is not a value in the tree
        bool search(ptrNode<T>& node, const T& value) {
            if(!node) {
                return false;
            } else if(node -> value == value) {
                return true;
            } else if(value < node -> value) {
                return search(node -> left, value);
            } else {
                return search(node -> right, value);
            }
        }
        /// @brief just function that deletes an element from the tree 
        void remove(ptrNode<T>& node, const T& value) {
            if(!node) {
                return ;
            } else if(value < node -> value) {
                remove(node -> left, value);
            } else if(value > node -> value) {
                remove(node -> right, value);
            } else {
                if(!node->left && !node->right) {
                    node.reset();
                } else if(node -> left && !node -> right) {
                    node = std::move(node->left);
                } else if(node -> right && !node -> left) {
                    node = std::move(node->right);
                } else {
                    ptrNode<T>* minLeaf = &node -> left;
                    while (!(*minLeaf) -> left){
                        minLeaf = &(*minLeaf) -> left;
                    }
                    node -> value = (*minLeaf) -> value;
                    (*minLeaf).reset();
                }
            }
        }

    public:
        // It is obvious what this functions do 
        void insert(T value) {
            insert(root, value);
        }
        void search(T value) {
            search(root, value);
        }
        void remove(T value) {
            remove(root, value);
        }
        void inorder() const {
            inorder(root);
        }

        // functions that allows to get std::unique_ptr pointer to any iterator in the TreeIterator file 
        std::unique_ptr<LevelOrderTreeIterator<T>> getLevelOrderIterator() const {
            return std::make_unique<LevelOrderTreeIterator<T>>(root);
        }
        std::unique_ptr<PreOrderTreeIterator<T>> getPreOrderIterator() const {
            return std::make_unique<PreOrderTreeIterator<T>>(root);
        }
        std::unique_ptr<InOrderTreeIterator<T>> getInOrderIterator() const {
            return std::make_unique<InOrderTreeIterator<T>>(root);
        }
        std::unique_ptr<PostOrderTreeIterator<T>> getPostOrderIterator() const {
            return std::make_unique<PostOrderTreeIterator<T>>(root);
        }
        std::unique_ptr<ReverseInOrderTreeIterator<T>> getReverseInOrderIterator() const {
            return std::make_unique<ReverseInOrderTreeIterator<T>>(root);
        }
};

#endif // TREE_COLLECTION_H