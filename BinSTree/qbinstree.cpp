#include "qbinstree.h"

QBinSTree::QBinSTree(QWidget *&new_parent)
{
    parent = new_parent;
}

void QBinSTree::draw(TreeNode<int> *t, int x, int y, int d)
{
    if (t != NULL)
    {
       Node *temp = new Node(QBinSTree::parent, QString::number(t->data));
       temp->show();
       temp->move(x, y);
       widgets.push_back(temp);
       draw(t->Left(), x-(50*pow(2, d-1)-15), y+30, d-1);
       draw(t->Right(), x+(50*pow(2, d-1)-15), y+30, d-1);
    }
}

void QBinSTree::DrawIt()
{
    int w = pow(2, Depth(b.Root())+1)*50+10;
    int h = (Depth(b.Root())+1)*30+10;

    int d;
    d = Depth(b.Root());

    parent->resize(w, h);
    parent->move(350-w/2, 0);

    for (int i = 0; i < widgets.size(); i++)
    {
        widgets[i]->background->hide();
    }

    widgets.clear();

    draw(b.Root(), (w - 40) / 2, 10, d);
}

void QBinSTree::insertElement(int item)
{
    QBinSTree::b.Insert(item);
    emit treeIsChange();
}

void QBinSTree::deleteElement(int item)
{
    int temp = b.ListSize();

    b.Delete(item);

    if (temp != b.ListSize())
        emit treeIsChange();
}

void QBinSTree::deleteAll()
{
    b.ClearList();
    emit treeIsChange();
}

void QBinSTree::find(int item)
{
    for (int i = 0; i < widgets.size(); i++)
    {
        if (widgets[i]->value->text().toInt() == item)
            widgets[i]->highlight();
    }
}
