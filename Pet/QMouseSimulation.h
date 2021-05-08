#ifndef QMOUSESIMULATION_H
#define QMOUSESIMULATION_H

#include <QWidget>
#include "ui_QMouseSimulation.h"

#include "QPatcherFramelessMovement.h"

class QMouseSimulation : public QWidget
{
    Q_OBJECT

public:
    QMouseSimulation(QWidget *parent = 0);
    ~QMouseSimulation();


    void SetPoint(const QPoint& _point);
    
    void ShowTemporary(int _microSeconds);
    void ShowFlash(int _microSeconds);

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::QMouseSimulation ui;

    void Initialize();
    
    QPatcherFramelessMovement m_PatcherMovement;
};

#endif // QMOUSESIMULATION_H
