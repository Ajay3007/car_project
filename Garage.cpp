#include "Garage.h"
#include "Car.h"
#include <iostream>
#include <algorithm>

void Garage::parkCar(std::unique_ptr<Car> car)
{
    if (car)
    {
        std::cout << "[Garage] Parking car: VIN=" << car->vin() << "\n";
        cars_.push_back(std::move(car));
    }
    else
    {
        std::cout << "[Garage] Cannot park null car\n";
    }
}

std::unique_ptr<Car> Garage::retrieveCar(const std::string &vin)
{
    auto it = std::find_if(cars_.begin(), cars_.end(),
                           [&vin](const std::unique_ptr<Car> &car) { return car->vin() == vin; });
    if (it != cars_.end())
    {
        std::cout << "[Garage] Retrieving car: VIN=" << vin << "\n";
        std::unique_ptr<Car> car = std::move(*it);
        cars_.erase(it);
        return car;
    }
    else
    {
        std::cout << "[Garage] Car not found: VIN=" << vin << "\n";
        return nullptr;
    }
}

void Garage::listCars() const
{
    std::cout << "[Garage] Listing cars:\n";
    for (const auto &car : cars_)
    {
        std::cout << "  - VIN: " << car->vin() << "\n";
    }
}
