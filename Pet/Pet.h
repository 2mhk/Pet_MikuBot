#ifndef PET_H
#define PET_H

#include <QtWidgets/QWidget>
#include "ui_Pet.h"

#include "QPatcherFramelessMovement.h"
#include "QPatcherLabelImageDispaly.h"
#include "QPatcherWindowsTrayIcon.h"

class QTimer;
class QComputerInteraction;

class Pet : public QWidget
{
    Q_OBJECT

public:
    Pet(QWidget *parent = 0);
    ~Pet();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::PetClass ui;

    void Initialize();

    QPatcherFramelessMovement m_Patcher_WidgetMovement;
    QPatcherLabelImageDispaly m_Patcher_LabelImageAnime;
    QPatcherWindowsTrayIcon m_Patcher_WindowsTrayIcon;

    QTimer* m_Timer_DropButton = NULL;
    QComputerInteraction* m_ComputerInteraction = NULL;
};

#endif // PET_H
