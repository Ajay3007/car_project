#pragma once
#include <iostream>
#include <string>

class Engine
{
public:
    enum class Type
    {
        DIESEL,
        PETROL,
        ELECTRIC,
        HYBRID
    };
    enum class State
    {
        STOPPED,
        RUNNING
    };
    Engine(std::string serial, Type type, int horsepower);
    ~Engine();
    void start();
    void stop();
    State getState() const noexcept { return state_; }
    std::string getSerial() const noexcept { return serial_; }
    Type getType() const noexcept { return type_; }
    int getHorsepower() const noexcept { return horsepower_; }
    int rpm() const noexcept { return rpm_; }

    // Additional member functions can be declared here
    // diagnostic info, etc.
    void diagnostics() const;

private:
    std::string serial_;
    Type type_;
    int horsepower_;
    State state_;
    int rpm_;
};
