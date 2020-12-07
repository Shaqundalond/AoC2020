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

string MakeHeadline(const string head, const char char_frame);
int ReadStrings(const string fn, vector<string>& v_s);
int ReadStrings4P04(const string fn, vector<string>& v_s);
int ReadMultilineStrings(const string fn, vector<string>& v_s, const string sep);

const vector<string> explode(const string& s, const string sep);
