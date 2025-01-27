#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

class Widget;
class QMenu;
class QSystemTrayIcon;

class Application : public QObject
{
    Q_OBJECT
public:
    Application(QObject *parent = nullptr);
    ~Application();

private:
    QSystemTrayIcon *_tray_icon = nullptr;
    QMenu *_menu = nullptr;
    Widget *_widget = nullptr;
};

#endif // APPLICATION_H
