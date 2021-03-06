/**
 * @file AoC-Tools.h
 * @author Reinhard.Pfaff
 * @brief headerfile for AoC-Tools.cpp
 * @version 0.1
 * @date 2020-12-03
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// ==================================
// Function declarations
// ==================================

string MakeHeadline(const string head, const char char_frame);
int ReadStrings(const string fn, vector<string>& v_s);
int ReadMultilineStrings(const string fn, vector<string>& v_s, const string sep);

const vector<string> explode(const string& s, const string sep);
int count_cX(vector<string> &sList, char cX);
int count_char(const string ts, const char tc);
int count_surrounding(vector<string> &sa, int ii, int jj, char tc, int iMethod);
string LongToBitString(const long l);
