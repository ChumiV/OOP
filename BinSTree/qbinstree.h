#ifndef QBINSTREE_H
#define QBINSTREE_H

#include <QObject>
#include "binstree.h"
#include "node.h"
#include "treenode.h"
#include "treescan.h"
#include <QString>

class QBinSTree : public QObject
{
    Q_OBJECT

    void draw(TreeNode <int> *t, int x, int y, int d);

public:
    BinSTree <int> b;
    QVector <Node *> widgets;
    QWidget *parent;

    QBinSTree(QWidget *&new_parent);

    //QObject::connect(this, SIGNAL(treeIsChange()), this, SLOT(DrawIt()));

signals:
    void treeIsChange();


public slots:
    void DrawIt();

    void find(int item);

    void insertElement(int item);

    void deleteElement(int item);

    void deleteAll();
};


#endif // QBINSTREE_H
