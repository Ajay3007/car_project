#include "Engine.h"

Engine::Engine(std::string serial, Type type, int horsepower)
    : serial_(std::move(serial)), type_(type), horsepower_(horsepower), state_(State::STOPPED), rpm_(0)
{
    std::cout << "[Engine] created: serial=" << serial_ << ", type=" << static_cast<int>(type_) << ", horsepower=" << horsepower_ << "\n";
}

Engine::~Engine()
{
    std::cout << "[Engine] destroyed: serial=" << serial_ << "\n";
}

void Engine::start()
{
    if (state_ == State::RUNNING)
    {
        std::cout << "[Engine] already running: serial=" << serial_ << "\n";
        return;
    }
    state_ = State::RUNNING;
    rpm_ = 800; // Idle RPM
    std::cout << "[Engine] started: serial=" << serial_ << ", rpm=" << rpm_ << "\n";
}

void Engine::stop()
{
    if (state_ == State::STOPPED)
    {
        std::cout << "[Engine] already stopped: serial=" << serial_ << "\n";
        return;
    }
    state_ = State::STOPPED;
    rpm_ = 0;
    std::cout << "[Engine] stopped: serial=" << serial_ << "\n";
}

void Engine::diagnostics() const
{
    std::cout << "[Engine Diagnostics] Serial: " << serial_
              << ", Type: " << static_cast<int>(type_)
              << ", Horsepower: " << horsepower_
              << ", State: " << (state_ == State::RUNNING ? "RUNNING" : "STOPPED")
              << ", RPM: " << rpm_ << "\n";
}