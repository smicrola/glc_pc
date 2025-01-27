#include "setting_widget.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QSlider>
#include <QSpinBox>
#include <QDialogButtonBox>

SettingWidget::SettingWidget(QWidget *parent)
    : QDialog{parent}
{
    setWindowTitle(tr("Settings"));

    QFormLayout *ml = new QFormLayout;
    setLayout(ml);

    _host_edit = new QLineEdit();
    _login_edit = new QLineEdit;
    _pass_edit = new QLineEdit;
    _pass_edit->setEchoMode(QLineEdit::Password);

    ml->addRow(tr("Host: "), _host_edit);
    ml->addRow(tr("Login: "), _login_edit);
    ml->addRow(tr("Password: "), _pass_edit);

    _update_time_glucose = new QSpinBox;
    _update_time_glucose->setRange(1, 60);
    _update_time_glucose->setValue(5);
    ml->addRow(tr("Update glucose, min: "), _update_time_glucose);

    _point_count = new QSpinBox;
    _point_count->setRange(0, 250);
    _point_count->setValue(120);
    ml->addRow(tr("Point count: "), _point_count);


    _transparent_slider = new QSlider(Qt::Horizontal);
    _transparent_slider->setRange(0, 255);
    _transparent_slider->setValue(127);
    ml->addRow(tr("Transperent: "), _transparent_slider);

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                           | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    ml->addWidget(buttonBox);
}

void SettingWidget::setConfig(const SettingParams &params)
{
    _host_edit->setText(params.host);
    _login_edit->setText(params.login);
    _pass_edit->setText(params.password);
    _update_time_glucose->setValue(params.update_time_min);
    _point_count->setValue(params.point_count);
    _transparent_slider->setValue(params.transparent_widget);
}

SettingParams SettingWidget::config() const
{
    SettingParams params;
    params.host = _host_edit->text();
    params.login = _login_edit->text();
    params.password = _pass_edit->text();
    params.update_time_min = _update_time_glucose->value();
    params.point_count = _point_count->value();
    params.transparent_widget = _transparent_slider->value();

    return params;
}
