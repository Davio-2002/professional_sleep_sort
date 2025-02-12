#include <iostream>
#include <thread>
#include <chrono>
#include <type_traits>

#include <Task.h>

/*
    CML stands for Custom Multithreading Library [ only thead pool for now :) ]
*/

using namespace std::chrono_literals;
using namespace CML;

void sayHello() {
    std::cout << "Hello World!" << std::endl;
    std::this_thread::sleep_for(1s);
    std::cout << "Goodbye World!" << std::endl;
}

int main() {
    std::thread t(sayHello);
    t.join();

    return 0;
}