#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QGLWidget>
#include <QtOpenGL>
#include <QTimer>
#include <QPolygonF>
#include <vector>
#include "board.h"

class MainWindow : public QGLWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int nWidth, int nHeight);
    virtual void paintGL();

    void paintHexagon(const QPoint& pt, const Board::HEXAGON_CELL &cell);
    void paintBoard(const QPoint& pt);

    void ResetState();
    void InitBoard();
    void mouseDoubleClickEvent(QMouseEvent* me);
    void mousePressEvent(QMouseEvent *me);
private:
    QSize _wndSize;
    size_t _radius;
    std::vector<QColor> _colors;
    std::vector<QPolygonF> _boardPolygons;
    Board _board;
};

#endif // MAINWINDOW_H
