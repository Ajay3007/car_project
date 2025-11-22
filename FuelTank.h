#pragma once
#include <iostream>

class FuelTank
{
public:
    explicit FuelTank(double capacity_liters_);
    ~FuelTank();
    double getCapacity() const noexcept { return capacity_liters_; }
    double getCurrentLevel() const noexcept { return level_liters_; }

    // Additional member functions can be declared here
    // e.g., refuel, consume, diagnostics, etc.
    void refuel(double amount);
    // consume returns true if enough fuel, reduces level, else false
    bool consume(double amount);
    void diagnostics() const;

private:
    double capacity_liters_;
    double level_liters_;
};