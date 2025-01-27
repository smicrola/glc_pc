#include "widget.h"

#include "libre_client.h"

#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::Window
                   | Qt::FramelessWindowHint
                   | Qt::WindowStaysOnTopHint);
    setFixedSize(400, 200);

    LibreClient *a = new LibreClient;
    a->auth("https://api-de.libreview.io", "s.microla@gmail.com", "noomoo7Xnoomoo7X");

}

Widget::~Widget()
{

}

void Widget::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    _drag_enable = true;
    _mouse_pos = event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    _drag_enable = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    if (_drag_enable) {
        const auto event_mouse_pos = mapToGlobal(event->pos());
        move(event_mouse_pos.x() - _mouse_pos.x(), event_mouse_pos.y() - _mouse_pos.y());
    }
}
