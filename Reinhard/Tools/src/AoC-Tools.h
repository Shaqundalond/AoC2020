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
int ReadStrings4P04(const string fn, vector<string>& v_s);
int ReadMultilineStrings(const string fn, vector<string>& v_s, const string sep);

const vector<string> explode(const string& s, const string sep);
int count_cX(vector<string> &sList, char cX);
int count_surrounding(vector<string> &sa, int ii, int jj, char tc, int iMethod);
int count_surrounding_v0(vector<string> &sa, int ii, int jj, char tc);
int count_char(const string ts, const char tc);
string LongToBitString(const long l);


// ==================================
// classes
// ==================================

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> tp_sec;

class StopWatch
{
public:
    StopWatch();
    ~StopWatch();

    void Start();
    double Stop();      // Duration in Seconds

private:
    tp_sec m_Start;
    tp_sec m_StartRound;

    long Now_ms();
}