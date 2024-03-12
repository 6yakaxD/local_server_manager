#pragma once

// +-------------------------[ Content ]-------------------------+
#include "SettingsPage.h"

// +-------------------------[ Qt Lib ]--------------------------+
#include <QtWidgets/QMainWindow>
#include <QMainWindow>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

// +-------------------------[ Other ]---------------------------+


#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 500

#pragma warning(disable : 4828)
#pragma warning(disable : 26495)



class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  MainWindow(QWidget* parent = nullptr)
  {

    setWindowIcon(QIcon(":/MainWindow/resource/ava.png"));

    setWindowFlags(Qt::Tool);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    trayIconMenu = new QMenu(this);
    sysTrayIcon = new QSystemTrayIcon(QIcon(":/MainWindow/resource/ava.png"), this);
    sysTrayIcon->setContextMenu(trayIconMenu);
    sysTrayIcon->setToolTip("My Application");
    sysTrayIcon->show();

    //exitAction->setEnabled(false);

    infoAction = trayIconMenu->addAction("Settings");
    connect(infoAction, &QAction::triggered, [this]() {
      this->show();
      m_MainPage = new SettingsPage(this);
      m_MainPage->move(0, 0);
      m_MainPage->resize(this->width(), this->height());
      m_MainPage->Init();
      m_MainPage->show();
      });
    exitAction = trayIconMenu->addAction("Exit");
    connect(exitAction, &QAction::triggered, [this]() {
      QApplication::quit();
      });

    connect(sysTrayIcon, &QSystemTrayIcon::activated, [this](QSystemTrayIcon::ActivationReason reason) {
      if (reason == QSystemTrayIcon::Trigger || reason == QSystemTrayIcon::Context) {
        trayIconMenu->exec(QCursor::pos());
      }
      });

  }

  void paintEvent(QPaintEvent* paint_event) override
  {
    QPainter MainWidget_painter(this);

    MainWidget_painter.setBrush(QColor(255, 255, 255, 255));
    MainWidget_painter.drawRect(QRect(0, 0, this->width(), this->height()));

  }

  void keyPressEvent(QKeyEvent* event) override
  {
    if (event->key() == Qt::Key_Escape)
    {
      QApplication::exit();
    }
  }

  void mousePressEvent(QMouseEvent* event) override
  {
    m_LastMousePosition = event->pos();
    switch (event->button())
    {
    case Qt::LeftButton:
    {
      m_IsLeftMButtonPressed = true;
    }
    break;

    default:
    {
      m_IsLeftMButtonPressed = false;
    }
    break;
    }
    QMainWindow::mousePressEvent(event);
  }

  void mouseReleaseEvent(QMouseEvent* event) override
  {
    m_IsLeftMButtonPressed = false;
    QMainWindow::mouseReleaseEvent(event);
  }

  void mouseMoveEvent(QMouseEvent* event) override
  {
    if (m_IsLeftMButtonPressed)
    {
      QPoint shift = event->pos() - m_LastMousePosition;
      this->move(this->pos() + shift);

    }
    QMainWindow::mouseMoveEvent(event);
  }


  SettingsPage* m_MainPage;

  bool              m_IsLeftMButtonPressed; /*    [Handle for mouse]    */
  QPoint            m_LastMousePosition;    /* [Handle mouse position]  */
  QPoint            WindowSize;             /*       [Window Size]      */

  QMenu* trayIconMenu;
  QSystemTrayIcon* sysTrayIcon;

  QAction* infoAction;
  QAction* exitAction;


};