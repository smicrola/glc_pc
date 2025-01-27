#ifndef CONST_AND_STRUCT_H
#define CONST_AND_STRUCT_H

#include <QString>
#include <QtGlobal>

struct SettingParams
{
    QString host = "https://api-de.libreview.io";
    QString login = nullptr;
    QString password = nullptr;
    quint32 update_time_min = 5;
    quint32 point_count = 120;
    quint32 transparent_widget = 127;
};

#endif // CONST_AND_STRUCT_H
