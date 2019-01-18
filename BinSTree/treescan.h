#ifndef TREESCAN_H
#define TREESCAN_H

#include "TreeNode.h"
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
void FreeTreeNode(TreeNode <T> *&t)
{
    delete t;
    t = NULL;
}

template <class T>
void CountLeaf(TreeNode<T> *t, int &count)
{
    if (t!=NULL)
    {
        CountLeaf(t->Left(), count);
        CountLeaf(t->Right(), count);
        if (t->Left() == NULL && t->Right() == NULL)
            count++;
    }
}

template <class T>
int Depth(TreeNode <T> *t)
{
    int DepthLeft, DepthRight, DepthVal;
    if (t == NULL)
        DepthVal = -1;
    else
    {
        DepthLeft = Depth(t->Left());
        DepthRight = Depth(t->Right());
        DepthVal = 1 + (DepthLeft > DepthRight ? DepthLeft: DepthRight);
    }
    return DepthVal;
}

#endif // TREESCAN_H
