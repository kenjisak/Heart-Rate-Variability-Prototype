#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QListWidget>
#include <QGraphicsView>
#include <QTime>
#include <QStatusBar>
#include <QVector>
#include <QtGlobal>
#include <QTimer>
#include "menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Menu* masterMenu;
    Menu* mainMenuOG;

    Ui::MainWindow *ui;
    QListWidget *activeQListWidget;

    void updateMenu(const QString, const QStringList);
    void initializeMainMenu(Menu*);

    double batteryLvl;
    int currentTimerCount;
    int maxPowerLevel;
    bool powerStatus;
    QTimer* timer;
    QTimer* pacetimer;
    QTimer* coherencetimer;
    void initializeTimer(QTimer*);
    void initializepaceTimer();
    void initializecoherenceTimer();
    void changePowerStatus();
    void drainBattery();

    int challengelevel = 1;
    int breathint = 10;
    void sessionTexts(bool);
    void setBreathInt(int);
    void setChallengelevel(int);
    void makePlot(double);
    double xData[101], yData[101];
    void updateCoherenceLabels();
    int numData;
    int progressDirection = 1;

    double yVal;
    double xStep =1;
    QVector<double> xValues;
    QVector<double> yValues;

private slots:
    void updateTimer();
    void navigateDownMenu();
    void navigateUpMenu();
    void navigateSubMenu();
    void navigateToMainMenu();
    void navigateBack();
    void rechargeBattery();
    void changeBatteryLevel(double);
    void powerChange();
    void beginSession();
    void breathpacer();
    void coherenceUpdate();
};
#endif // MAINWINDOW_H
