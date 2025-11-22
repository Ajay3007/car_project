#include "Car.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Wheel.h"

#include <iostream>
#include <algorithm>

Car::Car(std::string vin, std::unique_ptr<Engine> engine, std::unique_ptr<FuelTank> fuelTank)
    : vin_(std::move(vin)), engine_(std::move(engine)), fuelTank_(std::move(fuelTank))
{
    std::cout << "[Car] created: VIN=" << vin_ << "\n";
}

Car::~Car()
{
    std::cout << "[Car] destroyed: VIN=" << vin_ << "\n";
}

Car::Car(Car&& other) noexcept
    : vin_(std::move(other.vin_)),
      engine_(std::move(other.engine_)),
      fuelTank_(std::move(other.fuelTank_)),
      wheels_(std::move(other.wheels_)),
      odometer_km_(other.odometer_km_)
{
    std::cout << "[Car] moved: VIN=" << vin_ << "\n";
}

Car& Car::operator=(Car&& other) noexcept
{
    if (this != &other)
    {
        vin_ = std::move(other.vin_);
        engine_ = std::move(other.engine_);
        fuelTank_ = std::move(other.fuelTank_);
        wheels_ = std::move(other.wheels_);
        odometer_km_ = other.odometer_km_;
        std::cout << "[Car] move-assigned: VIN=" << vin_ << "\n";
    }
    return *this;
}

void Car::start()
{
    if (engine_)
    {
        engine_->start();
    }
    else
    {
        std::cout << "[Car] No engine to start: VIN=" << vin_ << "\n";
    }
}

void Car::stop()
{
    if (engine_)
    {
        engine_->stop();
    }
    else
    {
        std::cout << "[Car] No engine to stop: VIN=" << vin_ << "\n";
    }
}

bool Car::drive(double distance_km)
{
    if (!engine_ || engine_->getState() != Engine::State::RUNNING)
    {
        std::cout << "[Car] Cannot drive, engine not running: VIN=" << vin_ << "\n";
        return false;
    }

    double fuel_needed = distance_km * 0.1 * 100.0 / std::max(1, engine_->getHorsepower()); // Simplified fuel consumption formula
    if (fuelTank_ && fuelTank_->consume(fuel_needed))
    {
        odometer_km_ += distance_km;
        std::cout << "[Car] Drove " << distance_km << " km: VIN=" << vin_ << ", Odometer=" << odometer_km_ << " km\n";
        return true;
    }
    else
    {
        std::cout << "[Car] Not enough fuel to drive " << distance_km << " km: VIN=" << vin_ << "\n";
        return false;
    }
}

void Car::addWheel(std::unique_ptr<Wheel> wheel)
{
    if (wheel)
    {
        wheels_.push_back(std::move(wheel));
        std::cout << "[Car] Added wheel: VIN=" << vin_ << ", Total Wheels=" << wheels_.size() << "\n";
    }
    else
    {
        std::cout << "[Car] Cannot add null wheel: VIN=" << vin_ << "\n";
    }
}

void Car::diagnostics() const
{
    std::cout << "[Car Diagnostics] VIN: " << vin_
              << ", Odometer: " << odometer_km_ << " km, Wheels: " << wheels_.size() << "\n";
    if (engine_)
    {
        engine_->diagnostics();
    }
    if (fuelTank_)
    {
        fuelTank_->diagnostics();
    }
    for (const auto& wheel : wheels_)
    {
        std::cout << "  [Wheel] ID: " << wheel->getId()
                  << ", Position: " << static_cast<int>(wheel->getPosition())
                  << ", Diameter: " << wheel->getDiameter()
                  << ", Pressure: " << wheel->getPressure() << "\n";
    }
}

