#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

template <class T>

class TreeNode
{
private:
    TreeNode <T> *left;
    TreeNode <T> *right;

public:
    T data;

    TreeNode(const T &item, TreeNode <T> *lptr = NULL, TreeNode <T> *rptr = NULL)
    {
        data = item;
        left = lptr;
        right = rptr;
    };

    TreeNode <T> * Left()
    {
        return left;
    }

    TreeNode <T> * Right()
    {
        return right;
    }

    void SetLeft(TreeNode <T> *lptr = NULL)
    {
        left = lptr;
    }

    void SetRight(TreeNode <T> *rptr = NULL)
    {
        right = rptr;
    }
};

#endif // TREENODE_H
