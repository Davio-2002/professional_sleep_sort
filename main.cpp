#include <iostream>
#include <thread>
#include <chrono>
#include <type_traits>

using namespace std::chrono_literals;

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