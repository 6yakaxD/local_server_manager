#pragma once

#define WIN32_LEAN_AND_MEAN

// +-------------------------[ Content ]-------------------------+



// +-------------------------[ Qt Lib ]--------------------------+
#include <QApplication>
#include <QPropertyAnimation>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include <QFont>
#include <QFontDatabase>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QToolButton>
#include <QIcon>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QErrorMessage>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QMainWindow>

// +-------------------------[ Other ]---------------------------+
#include <iostream>

class MainPage : public QWidget
{
  Q_OBJECT

public:

  MainPage(QWidget* parent = nullptr) : QWidget(parent)
  {

  }


  void Init()
  {

    menu_bar = new QMenuBar(this);

    QMenu* windowMenu = new QMenu("General", this);
    QMenu* windowMenu1 = new QMenu("Server", this);


    menu_bar->addMenu(windowMenu);
    menu_bar->addMenu(windowMenu1);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setMenuBar(menu_bar);


  }


  void paintEvent(QPaintEvent* paint_event) override
  {
    QPainter MainWidget_painter(this);

    MainWidget_painter.setBrush(QColor(255, 255, 255, 255));
    MainWidget_painter.drawRect(QRect(0, 0, this->width(), this->height()));

  }


  QMenuBar* menu_bar;


private slots:
  void showWindow1() {
    // Code to show Window 1
  }


};












