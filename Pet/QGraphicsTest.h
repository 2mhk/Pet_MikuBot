#ifndef QGRAPHICSTEST_H
#define QGRAPHICSTEST_H

#include <QWidget>
#include "ui_QGraphicsTest.h"

class QGraphicsTest : public QWidget
{
    Q_OBJECT

public:
    QGraphicsTest(QWidget *parent = 0);
    ~QGraphicsTest();

private:
    Ui::QGraphicsTest ui;
};

#endif // QGRAPHICSTEST_H
