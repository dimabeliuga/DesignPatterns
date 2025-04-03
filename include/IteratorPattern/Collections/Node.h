#ifndef NODE_H
#define NODE_H

#include <memory>

/// @brief structure that imitates a node of the binary tree
/// @tparam T - type of the value that Node stores
template<class T>
struct Node {
    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(const T& _value) : left(nullptr), right(nullptr), value(_value) {}
};

/// @brief convinient abbreviation for std::unique_ptr<Node<T>>
template<typename T>
using ptrNode = std::unique_ptr<Node<T>>;


#endif // NODE_H