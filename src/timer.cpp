#include <string>
using namespace std;
#include "timer.hpp"
#include <chrono>
#include <iostream>
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

void Timer::pretty_print() const {
     long long total_time = elapsed();
     if (total_time == 0) {
          cout <<"No time has passed." << endl;
          return;
     }

     int hours = total_time / 3600;
     int minutes = (total_time % 3600) / 60;
     int seconds = total_time % 60;

     if (hours > 0) {
          cout << hours <<" hour";
          if (hours > 1) {
               cout << "s";
          }
          if (minutes > 0 || seconds > 0) {
               cout <<", ";
          }
     }
     if (minutes > 0) {
          cout << minutes << " minute";
          if (minutes > 1) {
               cout << "s";
          }
          if (seconds > 0) {
               cout <<" and ";
          }
     }
     if (seconds > 0) {
          cout << seconds << " second";
          if (seconds > 1) {
               cout << "s";
          }
     }
     if (total_time == 1) {
          cout <<" has passed."<<endl;
     }
     else {
          cout << " have passed." << endl;
     }

}



