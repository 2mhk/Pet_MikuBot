#include "QPatcherLabelImageDispaly.h"
#include "GeneralCode/Function.h"
#include "GeneralCode\GlobalControl.h"

#include "ResourcePlaceholder.h"

#include <QTimer>
#include <QLabel>

using namespace std;

QPatcherLabelImageDispaly::QPatcherLabelImageDispaly()
{
    //SetPlayList({ Function::GetQPixmapVector(Miku_ImageList_Stand_1), { 0, 0, 0 } });
    //SetPlayList({ Function::GetQPixmapVector(Miku_ImageList_Walk_2), { 0, 0, 0 } });
    //SetPlayList({ Function::GetQPixmapVector(Miku_ImageList_OpenFolder_5), { 0, 0, 0 } });
    SetPlayList({ Function::GetQPixmapVector(Miku_ImageList_Missing_7), { 0, 0, 0 } });

    m_Timer = new QTimer();
    connect(m_Timer, &QTimer::timeout, this, &QPatcherLabelImageDispaly::Play);
}

QPatcherLabelImageDispaly::~QPatcherLabelImageDispaly()
{
    Function::DeletePointer<QTimer>(m_Timer);
}

void QPatcherLabelImageDispaly::PatchTo(QLabel* label_toPatch)
{
    m_Label = label_toPatch;
    m_Timer->setInterval(m_Interval);
    Play();
    m_Timer->start();

}

void QPatcherLabelImageDispaly::SetPlayList(const AnimeGather& imageList)
{
    m_AnimeGather = imageList;
}

void QPatcherLabelImageDispaly::AddPlayList(const AnimeGather& imageList)
{




}



void QPatcherLabelImageDispaly::Play()
{
    int pixListCount = m_AnimeGather.pixmapList.size();
    if (pixListCount == 0 || m_Label == NULL)
        return;
    
    static int curPixCount = 0;
    m_Label->setPixmap(m_AnimeGather.pixmapList[curPixCount++ % pixListCount]);



}
