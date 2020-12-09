/**
 * @file MyCPU.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

enum opCode {
    nop = 0,
    jmp = 1,
    acc = 2
};

class MyCPU_Instruction
{
public:
    MyCPU_Instruction();
    ~MyCPU_Instruction();

    int m_Code;
    int m_p1;       // performs better than a vector
    int m_p2;

    void FromString(string s);
};

typedef vector<MyCPU_Instruction> MyProgram;

class MyCPU
{
public:

    MyCPU();
    ~MyCPU();

    int m_acc;      // accumulator
    int m_ip;       // instruction pointer

    int OneOp( MyCPU_Instruction &op);
    int Run( MyProgram &prog);
};