#ifndef CORROUTINES_H
#define CORROUTINES_H

#include <cppcoro/task.hpp>
#include <chrono>
#include <thread>

class Corroutines {
public:
    cppcoro::task<> delay(int seconds);
};


#endif