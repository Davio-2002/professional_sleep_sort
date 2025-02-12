#pragma once

#include <thread>
#include <atomic>

namespace CML {
    struct Thread {
    std::thread thread;
    std::atomic<bool> is_working;
};

class ThreadPool {

};

}
