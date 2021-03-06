#ifndef CHATMESSAGEDELEGATE_H
#define CHATMESSAGEDELEGATE_H

#include <QStyledItemDelegate>
#include <QItemDelegate>
#include <QTimer>
#include <QTime>

class ChatMessageView;

class ChatMessageDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ChatMessageDelegate(QObject *parent = 0);




    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent,
                           const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const;

    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const;

    bool createInRealTime() const;
    void setCreateInRealTime(bool createInRealTime);

protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model,
                     const QStyleOptionViewItem &option, const QModelIndex &index);
signals:


public slots:

private slots:
    void timerCheck();

private:
    ChatMessageView *m_parent;

    mutable QMap<QModelIndex, qint64> m_mapIndexClock;

    struct PrivateData
    {
        QWidget *editor;
        QSize   lastSize;
    };
    mutable QMap<QModelIndex, PrivateData> m_mapEditor;
    QTimer m_timerCheck;
    bool   m_createInRealTime;
};

#endif // CHATMESSAGEDELEGATE_H
