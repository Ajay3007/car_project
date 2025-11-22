#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

class Engine;
class FuelTank;
class Wheel;

class Car
{
public:
    Car(std::string vin_, std::unique_ptr<Engine> engine, std::unique_ptr<FuelTank> fuelTank);
    ~Car();
    // Car is movable but not copyable (unique ownership of engine/tank/wheels)
    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;
    Car(Car&&) noexcept;
    Car& operator=(Car&&) noexcept;

    const std::string& vin() const noexcept { return vin_; }

    // actions
    void addWheel(std::unique_ptr<Wheel> wheel);
    void start();
    void stop();
    bool drive(double distance_km);

    // diagnostics
    void diagnostics() const;
private:
    std::string vin_;
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<FuelTank> fuelTank_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    double odometer_km_ = 0.0;
};
