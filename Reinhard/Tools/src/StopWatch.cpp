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


StopWatch::StopWatch_ms()
{
    Start();
}
StopWatch::~StopWatch_ms()
{

}

void Start()
{
    m_Start = m_StartRound = Now();
}


double Stop()
{
    long n = Now_ms();
    long d = n - m_Start;
    m_Start = m_StartRound = 0L;

    return d;
}

double Now()
{
    double n = 0.0;


    return n;
}

