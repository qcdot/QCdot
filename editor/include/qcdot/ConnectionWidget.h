#ifndef QCDOT_CONNECTION_WIDGET_H
#define QCDOT_CONNECTION_WIDGET_H

#include <qcdot/Connection.h>
#include <QGraphicsPathItem>
#include <QObject>

namespace qcdot {

class PortWidget;

class ConnectionWidget final : public QObject, public QGraphicsPathItem {
    Q_OBJECT
public:
    ConnectionWidget(PortWidget* source, PortWidget* target, Connection* conn = nullptr,
                     QGraphicsItem* parent = nullptr);

    PortWidget* sourcePort() const { return source_; }
    PortWidget* targetPort() const { return target_; }
    Connection* connection() const { return conn_; }

    void updatePath();
    void setTarget(PortWidget* target);

    enum { Type = QGraphicsItem::UserType + 2 };
    int type() const override { return Type; }

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

signals:
    void arrowDragged(ConnectionWidget* conn, const QPointF& scenePos);

private:
    PortWidget* source_;
    PortWidget* target_;
    Connection* conn_;
};

/// Temporary connection drawn while dragging from a port.
class TempConnectionWidget final : public QGraphicsPathItem {
public:
    explicit TempConnectionWidget(PortWidget* source, QGraphicsItem* parent = nullptr);
    void updateEndPoint(const QPointF& pos);

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    PortWidget* source_;
    QPointF endPoint_;
};

} // namespace qcdot

#endif // QCDOT_CONNECTION_WIDGET_H