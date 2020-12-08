/**
 * @file MyCPU.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;
#include "AoC-Tools.h"

#include "MyCPU.h"


MyCPU_Instruction::MyCPU_Instruction()
{
    m_Code = 0;
    m_p1 = 0;
    m_p2 =
}

MyCPU_Instruction::~MyCPU_Instruction()
{

}


void MyCPU_Instruction::FromString(string s)
{
    vector<string> ts = explode(s," ");
    if (ts[0] == "nop")
        m_op = nop;
}
