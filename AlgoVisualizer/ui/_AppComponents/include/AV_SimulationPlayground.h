/**
 * @file   SimulationPlayGround.h
 * @brief  SimulationPlayGround class implementation
 * @author M Zaki <zaki.x86@gmail.com>
 * @version 0.1
 * @date   2023-03-12
 * @note   This class is the main class for the simulation playground.
 *         It contains the simulation canvas and the simulation output.
 *         This class should be plugged in the central section of the window grid.
*/

#ifndef __AV_SIMULATION_PLAYGROUND_H
#define __AV_SIMULATION_PLAYGROUND_H

#include "AV_Config.h"
#include "AV_Utils.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QTime>
#include <QTextEdit>
#include <QThread>    
#include <QRadioButton>

#include <QDebug>

#define MIN 0
#define MAX 100

_BEGIN_ALGOVIZ_UI

enum class SimState { RUNNING = 0, PAUSE = 1, IDLE=2 };

class SimulationPlayGround : public QWidget
{
protected:  

public:
    explicit SimulationPlayGround(QWidget* parent = nullptr);
    ~SimulationPlayGround();
    

    SimState state() const;
    void setState(SimState);

 private:
    QGridLayout* _layout;

    static const int LENGTH = 10;
    int _SleepDuration_ms;

    int _data[LENGTH];
    SimState _state;

    void setSleepDuration_ms(int);


    // utility functions
public:
    QPushButton *button[LENGTH];
    /* create dealy in the qt */
    void delay();
    /* filling array with random numbers */
    void updateArray();
    /* set the background of button to yellow to attract view */
    void highlightButton(QPushButton * button);
    /* set the button to normal color */
    void unhighlightButton(QPushButton * button);
    /* swap value of a and b */
    void swap(int *a, int *b);
    /* set button */
    void setButtonValue( QPushButton *button, int data);
    /* run selection sort algorith and update ui */
    void bubbleSort(QPushButton *button[]);
    /* run selection sort algorith and update ui */
    void selectionSort(QPushButton *button[]);
    /* set button value corresponding to position data equivalent to zip in python */
    void updateButton(QPushButton *button[]);
};

_END_ALGOVIZ_UI

#endif // __AV_SIMULATION_PLAYGROUND_H