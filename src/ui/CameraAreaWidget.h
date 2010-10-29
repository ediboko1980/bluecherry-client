#ifndef CAMERAAREAWIDGET_H
#define CAMERAAREAWIDGET_H

#include <QFrame>
#include <QList>

class QGridLayout;
class LiveFeedWidget;
class DVRCamera;

class CameraAreaWidget : public QFrame
{
    Q_OBJECT

public:
    explicit CameraAreaWidget(QWidget *parent = 0);

    int rows() const { return m_rowCount; }
    int columns() const { return m_columnCount; }
    void setGridSize(int rows, int columns);

    QByteArray saveLayout() const;
    bool loadLayout(const QByteArray &data);

    void addCamera(const DVRCamera &camera);

public slots:
    void setRows(int rows) { setGridSize(rows, m_columnCount); }
    void addRow() { setGridSize(m_rowCount+1, m_columnCount); }
    void removeRow() { setGridSize(m_rowCount-1, m_columnCount); }

    void setColumns(int columns) { setGridSize(m_rowCount, columns); }
    void addColumn() { setGridSize(m_rowCount, m_columnCount+1); }
    void removeColumn() { setGridSize(m_rowCount, m_columnCount-1); }

    void setGridSize(int size) { setGridSize(size, size); }

    void openFullScreen();
    void closeFullScreen();
    void toggleFullScreen();

signals:
    void gridSizeChanged(int rows, int columns);
    void cameraChanged(LiveFeedWidget *widget);

private slots:
    void onCameraChanged();

protected:
    virtual void dragEnterEvent(QDragEnterEvent *ev);
    virtual void dragLeaveEvent(QDragLeaveEvent *ev);
    virtual void dragMoveEvent(QDragMoveEvent *ev);
    virtual void dropEvent(QDropEvent *ev);

private:
    QList<QList<LiveFeedWidget*> > m_cameraWidgets;
    QList<LiveFeedWidget*> m_dragWidgets;
    QGridLayout *mainLayout;
    int m_rowCount, m_columnCount;

    void removeColumn(int c);
    void removeRow(int r);
};

#endif // CAMERAAREAWIDGET_H
