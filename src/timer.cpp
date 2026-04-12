#include <string>
using namespace std;
#include "timer.hpp"
#include <chrono>
#include <format>
Timer::Timer() {
     running = false;
}

void Timer::start() {
     start_time = chrono::system_clock::now();
     running = true;
}

void Timer::stop() {

     end_time = chrono::system_clock::now();
     running = false;
}
string Timer::get_the_system_time() {
     auto now = chrono::system_clock::now();
string s = format("{:%F %T}", now);
     return s;
}

long long Timer::elapsed() const{
     auto duration = end_time - start_time;
     return chrono::duration_cast<chrono::seconds>(duration).count();
}

