#include "application.h"
#include "setting_widget.h"
#include "widget.h"

#include <QApplication>
#include <QMenu>
#include <QSystemTrayIcon>

Application::Application(QObject *parent) : QObject(parent)
{
    _widget = new Widget;
    _tray_icon = new QSystemTrayIcon(this);
    _tray_icon->setIcon(QIcon(":/img/blood-drop.png"));

    _menu = new QMenu();
    QAction * setting_action = new QAction(QObject::tr("Settings"), _menu);
    QAction * quit_action = new QAction(QObject::tr("Exit"), _menu);

    connect(setting_action, &QAction::triggered, this, [this](){
        SettingWidget d(_widget);
        d.exec();
    });
    connect(quit_action, &QAction::triggered, qApp, &QApplication::quit);

    _menu->addAction(setting_action);
    _menu->addAction(quit_action);

    _tray_icon->setContextMenu(_menu);


    _tray_icon->show();

    _widget->show();
}

Application::~Application()
{
    delete _menu;
}
