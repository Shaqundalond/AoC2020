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
    m_p2 = 0;
}

MyCPU_Instruction::~MyCPU_Instruction()
{

}


void MyCPU_Instruction::FromString(string s)
{
    vector<string> ts = explode(s," ");
    if (ts[0] == "nop")
        m_Code = nop;
    else if (ts[0] == "acc")
        m_Code = acc;
    else if (ts[0] == "jmp")
        m_Code = jmp;
    else
        m_Code = nop;

    // Arguments
    if (ts.size() > 1)
        m_p1 = atoi(ts[1].c_str());

    if (ts.size() > 2)
        m_p2 = atoi(ts[2].c_str());

    return;
}


MyCPU::MyCPU()
{

}

MyCPU::~MyCPU()
{

}


int MyCPU::OneOp( MyCPU_Instruction &op)
{
    switch (op.m_Code)
    {
        case nop:
            // nothing to do
            m_ip++;
            break;
        case acc:
            m_acc += op.m_p1;
            m_ip++;
            break;
        case jmp:
            m_ip += op.m_p1;
    }

    // kill this op
    op.m_Code = -1;

    return 0;
}

int MyCPU::Run( MyProgram &prog)
{
    m_ip = 0;
    while (prog[m_ip].m_Code >= 0)
    {
        OneOp(prog[m_ip]);
    }
 
    return m_acc;
}
