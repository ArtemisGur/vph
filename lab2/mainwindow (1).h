#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QKeyEvent>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);
    void moveEvent(QMoveEvent *e);

private slots:
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QLabel *label;
    QString text = "Hello";
    QLabel *moveLabel;

    int textLen = 5;
    int countCheck = 0;
};

#endif // MAINWINDOW_H
