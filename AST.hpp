#ifndef AST_HPP
#define AST_HPP
#include <memory>
#include "string.hpp"

class AST
{
public:
    class Node
    {
    public:
        explicit Node(const String &val) : value(val) {}

        void addChild(std::unique_ptr<Node> child)
        {
            children.push_back(std::move(child));
        }

        // Getters
        const String &getValue() const { return value; }
        const std::vector<std::unique_ptr<Node>> &getChildren() const { return children; }

        // Recursively print the node and its children
        void print(int depth = 0) const
        {
            for (int i = 0; i < depth; ++i)
                std::cout << " ";
            std::cout << value << "\n";
            for (const auto &child : children)
            {
                child->print(depth + 1);
            }
        }

    private:
        String value;
        std::vector<std::unique_ptr<Node>> children;
    };

private:
    std::unique_ptr<Node> root; // root of the tree
public:
    explicit AST(const String &rootValue)
    {
        root = std::make_unique<Node>(rootValue);
    }
    Node *getRoot() { return root.get(); }

    void print() const
    {
        if (root)
        {
            root->print();
        }
    }
};

#endif