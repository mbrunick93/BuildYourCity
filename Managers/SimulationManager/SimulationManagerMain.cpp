
#include "SimulationManager.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

int main() {
    Manager::SimulationManager manager;

    for(;;)
    {
        manager.run();
        std::this_thread::sleep_for (std::chrono::milliseconds(500));
    }
}