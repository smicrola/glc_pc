#ifndef SETTING_WIDGET_H
#define SETTING_WIDGET_H

#include "const_and_struct.h"

#include <QDialog>
class QLineEdit;
class QSlider;
class QSpinBox;

class SettingWidget : public QDialog
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = nullptr);

    void setConfig(const SettingParams &params);
    SettingParams config() const;

private:
    QLineEdit *_host_edit = nullptr;
    QLineEdit *_login_edit = nullptr;
    QLineEdit *_pass_edit = nullptr;
    QSpinBox *_update_time_glucose = nullptr;
    QSpinBox *_point_count = nullptr;
    QSlider *_transparent_slider = nullptr;
};

#endif // SETTING_WIDGET_H
