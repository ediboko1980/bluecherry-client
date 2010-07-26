#include "CameraAreaWidget.h"
#include <QGridLayout>

CameraAreaWidget::CameraAreaWidget(QWidget *parent)
    : QWidget(parent), m_rowCount(0), m_columnCount(0)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainLayout = new QGridLayout(this);
    mainLayout->setMargin(0);

    setGridSize(3, 3);
}

void CameraAreaWidget::setGridSize(int rows, int columns)
{
    if (rows == m_rowCount && columns == m_columnCount)
        return;

    m_rowCount = rows;
    m_columnCount = columns;

    /* Create a new set of placeholder widgets.. */
    qDeleteAll(m_cameraWidgets);
    m_cameraWidgets.clear();

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            QWidget *widget = new QWidget;
            widget->setMinimumSize(50, 50);
            widget->setStyleSheet(QLatin1String("background-color: black;"));
            mainLayout->addWidget(widget, r, c);
            m_cameraWidgets.append(widget);
        }
    }

    emit gridSizeChanged(rows, columns);
}
