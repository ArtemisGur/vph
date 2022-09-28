#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *quitBtn = new QPushButton("Quit", this);
    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    label = new QLabel(text, this);
    label->move(10, 50);
    label->resize(1000, 50);

    moveLabel = new QLabel("Move info", this);
    moveLabel->move(10, 30);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimerAlarm()
{
    MainWindow::setWindowTitle(QTime::currentTime().toString());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    textLen += 1;
    if (countCheck == 0)
    {
       text.clear();
       countCheck++;
       textLen = 0;
    }
    text.resize(textLen);
    text.push_back(event->text());
    label->setText(text);
}

void MainWindow::moveEvent(QMoveEvent *event){
    int x = event->pos().x();
    int y = event->pos().y();
    QString position = QString::number(x) + ", " + QString::number(y);
    moveLabel->setText(position);
}
