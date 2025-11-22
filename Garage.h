#pragma once
#include <memory>
#include <vector>

class Car;

class Garage
{
public:
    void parkCar(std::unique_ptr<Car> car);
    std::unique_ptr<Car> retrieveCar(const std::string &vin);
    void listCars() const;
private:
    std::vector<std::unique_ptr<Car>> cars_;
};