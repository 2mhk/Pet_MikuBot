#ifndef QCOMPUTERINTERACTION_H
#define QCOMPUTERINTERACTION_H

#include <QObject>
#include "QMouseSimulation.h"

class QComputerInteraction : public QObject
{
    Q_OBJECT

public:
    QComputerInteraction();
    ~QComputerInteraction();

    void MovePointerTo(const QPoint& _point);
    void Click();
    void Click(const QPoint& _point);

private:
    void Initialize();

    QMouseSimulation* m_MouseSimulation = NULL;

};

#endif // QPATCHERCOMPUTERINTERACTION_H
