#include <iostream>
#include <thread>
#include <chrono>
#include "src/timer.hpp"

int main() {
 Timer timer;
 timer.start();
 this_thread::sleep_for(chrono::seconds(3));
 timer.stop();
 cout << timer.elapsed() << endl;

cout << timer.get_the_system_time();

}
