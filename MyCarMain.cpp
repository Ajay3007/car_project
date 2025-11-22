#include "Car.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Wheel.h"
#include "Garage.h"

#include <iostream>
#include <memory>

int main()
{
    // build a car and components (unique ownership)
    auto engine = std::make_unique<Engine>("ENG-0001", Engine::Type::PETROL, 150);
    auto fuelTank = std::make_unique<FuelTank>(50.0); // 50 liters capacity
    auto car = std::make_unique<Car>("VIN-1234567890", std::move(engine), std::move(fuelTank));

    // add wheels
    car->addWheel(std::make_unique<Wheel>(Wheel::Position::FRONT_LEFT, 16.0, 1, 32.0));
    car->addWheel(std::make_unique<Wheel>(Wheel::Position::FRONT_RIGHT, 16.0, 2, 32.0));
    car->addWheel(std::make_unique<Wheel>(Wheel::Position::REAR_LEFT, 16.0, 3, 30.0));
    car->addWheel(std::make_unique<Wheel>(Wheel::Position::REAR_RIGHT, 16.0, 4, 30.0));

    // diagnostics before starting
    car->diagnostics();

    // start the car
    car->start();
    // drive some distance
    car->drive(100.0); // drive 100 km
    // diagnostics after driving
    car->diagnostics();
    // stop the car
    car->stop();

    // demonstrate garage shared ownership
    Garage garage;
    garage.parkCar(std::move(car)); // move car into garage, garage and main both have shared_ptr
    garage.listCars();
    auto retrievedCar = garage.retrieveCar("VIN-1234567890");
    if (retrievedCar)
    {
        retrievedCar->diagnostics();
    }
    std::cout << "Program completed successfully.\n";
    // after main ends, shared_ptr counts drop and car destroyed automatically
    return 0;
}

