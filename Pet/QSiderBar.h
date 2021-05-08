#ifndef QSIDERBAR_H
#define QSIDERBAR_H

#include <QWidget>
#include "ui_QSiderBar.h"

#include "QPatcherAnimationWidgetSlide.h"

class QSiderBar : public QWidget
{
    Q_OBJECT

    friend class Pet;

signals:

public:
    QSiderBar(QWidget *parent = 0);
    ~QSiderBar();

    QPatcherAnimationWidgetSlide m_AnimationPatcher_ShowSlide;

protected:
    void resizeEvent(QResizeEvent* event);

private:
    Ui::QSiderBar ui;

    void Initialize();
};

#endif // QSIDERBAR_H
