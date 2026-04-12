#include <string>
#include <chrono>
using namespace std;

class Timer {
    private:
    bool running;
    bool active;
    chrono::system_clock::time_point start_time;
    chrono::system_clock::time_point end_time;
    chrono::system_clock::time_point current;

    public:
    Timer();

    void start();
    void stop();
    string get_the_system_time();
    long long elapsed()const;

}
;