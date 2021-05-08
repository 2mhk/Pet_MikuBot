#pragma once

#include <vector>
#include <QPixmap>

class QLabel;
class QTimer;

#include <map>
using namespace std;


struct MoodType
{
    static const int typeMax = 32767;
    static const int typeMin = -32768;
    short happy : 16;
    short madness : 16;
    short sadness : 16;
    //short fearness : 16;
    friend MoodType operator+(const MoodType &_first, const MoodType &_later)
    {
        MoodType _ret;
        _ret.happy = _first.happy + _later.happy;
        _ret.madness = _first.madness + _later.madness;
        _ret.sadness = _first.sadness + _later.sadness;
    }
    friend MoodType operator-(const MoodType &_first, const MoodType &_later)
    {
        MoodType _ret;
        _ret.happy = _first.happy - _later.happy;
        _ret.madness = _first.madness - _later.madness;
        _ret.sadness = _first.sadness - _later.sadness;
    }
};

struct AnimeGather 
{
    std::vector<QPixmap> pixmapList;

    //std::map<string, std::vector<QPixmap>> index;

    MoodType mood;
};

class AnimeGatherEncapsulation
{
    void GetImage();

private:
    AnimeGather m_list;

    
};


class QPatcherLabelImageDispaly : public QObject
{
    Q_OBJECT
public:
    QPatcherLabelImageDispaly();
    ~QPatcherLabelImageDispaly();

    int m_Interval = 600;

    void PatchTo(QLabel* label_toPatch);

    void SetPlayList(const AnimeGather& imageList);
    void AddPlayList(const AnimeGather& imageList);

private:
    QLabel* m_Label = NULL;
    QTimer* m_Timer = NULL;

    AnimeGather m_AnimeGather;
    QPixmap m_CurrentPixmap;


    void Play();
};

