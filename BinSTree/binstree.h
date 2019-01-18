#ifndef BINSTREE_H
#define BINSTREE_H

#include <iostream>
#include "TreeNode.h"
#include "TreeScan.h"

using namespace std;

template <class T>

class BinSTree
{
private:
    unsigned int size;
    TreeNode <T> *root;
    TreeNode <T> *current;

    void del(TreeNode <T> *p)//удаление TreeNode
    {
        if (p != NULL)
        {
            del(p->Left());
            del(p->Right());

            delete p;
            p = NULL;
        }
    }

public:
    BinSTree()
    {
        size = 0;
        root = NULL;
        current = NULL;
    };

    unsigned int ListSize() const
    {
        return size;
    }

    bool ListEmpty() const
    {
        return (size == 0);
    }

    void ClearList()
    {
        del(root);
        root = NULL;
    }

    bool Find(T &item)
    {
        TreeNode <T> *parent;
        current = FindNode(item, parent);

        if (current != NULL)
            return true;
        else
            return false;
    }

    TreeNode <T> * FindNode(const T &item, TreeNode <T> *&parent)
    {
        TreeNode <T> *t = root;

        parent = NULL;

        while (t != NULL)
        {
            if (item == t->data)
                break;
            else
            {
                parent = t;

                if (item < t->data)
                    t = t->Left();
                else
                    t = t->Right();
            }
        }

        return t;
    }

    TreeNode <T> * GetTreeNode(const T &item, TreeNode <T> *lptr = NULL, TreeNode <T> *rptr = NULL)
    {
        TreeNode <T> *p;
        p = new TreeNode<T>(item, lptr, rptr);

        if (p == NULL)
        {
            cerr << "memory allocation error" << endl;
            exit(1);
        }

        return p;
    }

    void Insert(const T &item)
    {
        TreeNode <T> *t = root, *parent = NULL, *newnode;

        newnode = GetTreeNode(item);

        while (t != NULL)
        {
            parent = t;

            if (item < t->data)
                t = t->Left();
            else
                t = t->Right();
        }

        if (parent == NULL)
            root = newnode;
        else
        {
            if (item < parent->data)
                parent->SetLeft(newnode);
            else
                parent->SetRight(newnode);
        }

        current = newnode;
        size++;
    }

    void Insert(const TreeNode <T> *newnode)
    {
        TreeNode <T> *t = root, *parent = NULL;

        while (t != NULL)
        {
            parent = t;

            if (newnode->data < t->data)
                t = t->Left();
            else
                t = t->Right();
        }

        if (parent == NULL)
            root = newnode;
        else
        {
            if (newnode->data < parent->data)
                parent->SetLeft(newnode);
            else
                parent->SetRight(newnode);
        }

        current = newnode;
        size++;
    }

    TreeNode <T> * Root() const
    {
        return root;
    }

    void MakeBinSTree()
    {
        int n, item;

        cout << "enter the number" << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "enter the element" << endl;
            cin >> item;
            Insert(item);
        }
    }

    int NodeLevel(const T &item)
    {
        TreeNode <T> *t = root;
        int i = -1;

        while (t != NULL)
        {
            i++;
            if (t->data == item)
                break;
            else
            {
                if (item < t->data)
                    t = t->Left();
                else
                    t = t->Right();
            }

        }

        if (t == NULL)
            i = -1;

        return i;
    }

    void Delete(const T &item)
    {
        TreeNode <T> *DNodePtr, *PNodePtr = NULL, *RNodePtr = NULL; //D- удаляемый узел, P-родитель удаляемого узла, R- узел для замены удаленного (изначально предполагаем, что удаляемый узел- листовой)

        if ((DNodePtr = FindNode(item, PNodePtr)) == NULL) //если удаляемый узел не найден- выходим
            return;

        if ((DNodePtr->Left() == NULL) && (DNodePtr->Right() != NULL)) //если удаляемый узел имеет только правое поддерево, то на его месте будет правый потомок
            RNodePtr = DNodePtr->Right();

        if ((DNodePtr->Left() != NULL) && (DNodePtr->Right() == NULL)) //если удаляемый узел имеет только левое поддерево, то на его месте будет левый потомок
            RNodePtr = DNodePtr->Left();

        if ((DNodePtr->Left() != NULL) && (DNodePtr->Right() != NULL)) //если удаляемый узел имеет и правое, и левое поддерево, то
        {
            TreeNode <T> *PofRNodePtr = DNodePtr;

            RNodePtr = DNodePtr->Left();	//cпускаемся в левое поддерево

            while (RNodePtr->Right() != NULL) //находим самый большой элемент
            {
                PofRNodePtr = RNodePtr;
                RNodePtr = RNodePtr->Right();
            }

            if (PofRNodePtr != DNodePtr) //если этот элемент- не левый потомок удаляемого узла, то
            {
                PofRNodePtr->SetRight(RNodePtr->Left()); //правый потомок родительского узла искомого элемента = левому потомку искомого элемента
                RNodePtr->SetLeft(DNodePtr->Left());	 //левым потомком искомого узла становится левое поддерево удаляемого узла
                RNodePtr->SetRight(DNodePtr->Right());	 //правым потомком искомого узла становится правое поддерево удаляемого узла
            }
            else    //если искомый узел- левый потомок удаляемого
                RNodePtr->SetRight(DNodePtr->Right());	//его правым потомком становится правое поддерево удаляемого узла
        }

        if (PNodePtr != NULL)	//если удаляемый узел- не корень
        {
            if (DNodePtr->data < PNodePtr->data)   //вставляем в правильное место от родительского элемента
                PNodePtr->SetLeft(RNodePtr);
            else
                PNodePtr->SetRight(RNodePtr);
        }
        else           //если корень, то новый элемент становится корнем
            root = RNodePtr;

        FreeTreeNode(DNodePtr);		//удаляем узел
        size--;						//уменьшаем размер
    }
};



#endif // BINSTREE_H
