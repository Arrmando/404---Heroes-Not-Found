#ifndef CORROUTINES_HPP
#define CORROUTINES_HPP

#include <cppcoro/task.hpp>
#include <chrono>
#include <thread>

class Corroutines {
public:
    cppcoro::task<> delay(int seconds);
};


#endif