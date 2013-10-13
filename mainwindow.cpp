#include "mainwindow.h"
#include <math.h>
#define _USE_MATH_DEFINES

MainWindow::MainWindow(QWidget *parent)
    : QGLWidget(parent),
      _board(10, 3),
      _wndSize(800, 480),
      _radius(30)
{
    _colors.push_back(QColor(0, 0, 0, 255));
    _colors.push_back(QColor(255, 0, 0, 255));
    _colors.push_back(QColor(0, 255, 0, 255));
    _colors.push_back(QColor(0, 0, 255, 255));
    _colors.push_back(QColor(255, 255, 255, 255));
    ResetState();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initializeGL()
{
    qglClearColor(Qt::black);
}

void MainWindow::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
    _wndSize.setWidth(nWidth);
    _wndSize.setHeight(nHeight);
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,_wndSize.width(),_wndSize.height(),0,1,0);

    qglColor(Qt::white);
    QPoint pt(_radius, _radius);
    paintBoard(pt);
    swapBuffers();
}

void MainWindow::paintBoard(const QPoint& pt)
{
    size_t count = _board.GetSize();
    QPoint curPoint;
    float xCoef = 1.92;
    float yCoef = 1.6;
    for (unsigned i = 0; i < count; i++)
    {
        for (unsigned j = 0; j < count; j++)
        {
            curPoint = pt + QPoint(i * xCoef * _radius, j * yCoef * _radius);
            if (j % 2)
            {
                curPoint.rx() += xCoef * _radius / 2;
            }
            paintHexagon(curPoint, _board.GetData()[i][j]);
            qglColor(Qt::white);
            renderText(curPoint.x(), curPoint.y(), 0, QString::fromUtf8("%1:%2").arg(i).arg(j), QFont());
        }
    }
}

void MainWindow::paintHexagon(const QPoint& pt, const Board::HEXAGON_CELL& cell)
{
    size_t count = 6;
    glBegin(GL_POLYGON);
    qglColor(_colors[cell[0]]);
    for (unsigned i = 0; i < count; i++)
    {
        QPoint ptVertex = pt;
        ptVertex.rx() += _radius * sin(i * 2 * M_PI / count);
        ptVertex.ry() -= _radius * cos(i * 2 * M_PI / count);
        glVertex2f(ptVertex.x(), ptVertex.y());
        if (i && i % 2 == 0)
        {
            glVertex2f(pt.x(), pt.y());
            glEnd();
            glBegin(GL_POLYGON);
            qglColor(_colors[cell[i / 2]]);
            glVertex2f(ptVertex.x(), ptVertex.y());
        }
    }
    glVertex2f(pt.x(), pt.y() - _radius);
    glVertex2f(pt.x(), pt.y());
    glEnd();
}

void MainWindow::InitBoard()
{

}

void MainWindow::ResetState()
{
    InitBoard();
    _board.RandomFill();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent* me)
{
    ResetState();
    updateGL();
}

void MainWindow::mousePressEvent(QMouseEvent* me)
{

}
