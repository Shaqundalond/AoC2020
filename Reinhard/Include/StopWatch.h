// ==================================
// classes
// ==================================

/**
 * @brief Stopwatch
 * 
 * uses std::chrono
 * 
 */

class StopWatch
{
public:
    StopWatch();
    ~StopWatch();

    void Start();
    double Stop();      // Duration in Seconds
    double Lap();       // Duration in Seconds

private:
    std::chrono::steady_clock::time_point m_TP_Start;
    std::chrono::steady_clock::time_point m_TP_StartLap;

};