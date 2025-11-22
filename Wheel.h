#pragma once
#include <iostream>

class Wheel
{
public:
    enum class Position
    {
        FRONT_LEFT,
        FRONT_RIGHT,
        REAR_LEFT,
        REAR_RIGHT
    };

    explicit Wheel(Position position, double diameter, int id, double pressure);
    ~Wheel();
    Position getPosition() const noexcept { return position_; }
    double getDiameter() const noexcept { return diameter_; }
    int getId() const noexcept { return id_; }
    double getPressure() const noexcept { return pressure_; }

    // Additional member functions can be declared here
    // e.g., inflate, deflate, diagnostics, etc.
    void inflate(double amount);
    
private:
    Position position_;
    double diameter_;
    int id_;
    double pressure_;
};