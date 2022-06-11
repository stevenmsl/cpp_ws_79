#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol54
{
    struct Node
    {
        bool isWord;
        vector<Node *> children;
        Node() : isWord(false), children(26, nullptr){};
    };
}
#endif