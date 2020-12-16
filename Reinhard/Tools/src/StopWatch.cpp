/**
 * @file StopWatch.cpp
 * @author Reinahrd Pfaff
 * @brief Implementation of a stopwatch
 * @version 0.1
 * @date 2020-12-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
#include "AoC-Tools.h"

using namespace std::chrono;
#include "StopWatch.h"

StopWatch::StopWatch()
{
    Start();
}
StopWatch::~StopWatch()
{

}

void Start()
{
    time_point tp = steady_clock::now();
    m_TP_Start = m_TP_StartLap = tp;
}


/**
 * @brief Returning the Duration since Start
 * 
 * @return double 
 */
double Stop()
{
    time_point tp = steady_clock::now();
    steady_clock::duration d = tp - m_TP_Start;

    double dur = d.count();
    return dur;
}

double Lap()
{
    time_point tp = steady_clock::now();
    steady_clock::duration d = tp - m_TP_StartLap;
    m_TP_StartLap = tp;

    double dur = d.count();
    return dur;
}