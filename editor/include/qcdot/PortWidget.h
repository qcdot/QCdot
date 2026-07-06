#ifndef QCDOT_PORT_WIDGET_H
#define QCDOT_PORT_WIDGET_H

#include <qcdot/Port.h>
#include <QGraphicsEllipseItem>
#include <QPainterPath>

namespace qcdot {

class ConnectionWidget;
class NodeWidget;

/// Visual representation of a port on the node widget.
class PortWidget final : public QGraphicsEllipseItem {
public:
    PortWidget(Port* port, NodeWidget* parent);

    Port* port() const { return port_; }
    NodeWidget* nodeWidget() const { return nodeWidget_; }
    QPointF centerPos() const;

    // Connection management
    void addConnection(ConnectionWidget* conn);
    void removeConnection(ConnectionWidget* conn);
    const QList<ConnectionWidget*>& connections() const { return connections_; }

    bool isRemovable() const;

    enum { Type = QGraphicsItem::UserType + 1 };
    int type() const override { return Type; }

protected:
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    Port* port_;
    NodeWidget* nodeWidget_;
    QList<ConnectionWidget*> connections_;
    bool hoverDeleteButton_ = false;
    static constexpr float kRadius = 6.0f;
    static constexpr float kDeleteButtonSize = 14.0f;
};

} // namespace qcdot

#endif // QCDOT_PORT_WIDGET_H