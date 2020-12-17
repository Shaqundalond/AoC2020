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
    std::chrono::time_point<std::chrono::high_resolution_clock> m_TP_Start;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_TP_StartLap;

};