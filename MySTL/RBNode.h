#pragma once
#include <utility>

namespace mystl {
    enum Color { red, black };

    template<typename Key, typename Value>
    class RBNode
    {
    public:
        pair<const Key, Value> value;
        Color color;
        RBNode* left;
        RBNode* right;
        RBNode* parent;

        RBNode() : value(Key(), Value()), color(red), left(nullptr), right(nullptr), parent(nullptr) {}
   
        RBNode(const Key& k, const Value& v, Color c = red)
            : value(k, v), color(c), left(nullptr), right(nullptr), parent(nullptr) {}

        RBNode(Key&& k, Value&& v, Color c = red)
            : value(std::move(k), std::move(v)), color(c), left(nullptr), right(nullptr), parent(nullptr) {}
    };
}