#include <cppcoro/task.hpp>
#include <chrono>
#include <thread>
#include <cppcoro/static_thread_pool.hpp>

class Corroutines {
public:
    cppcoro::task<> delay(int seconds) {
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        co_return;
    }
};
