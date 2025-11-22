#include "FuelTank.h"

FuelTank::FuelTank(double capacity_liters)
    : capacity_liters_(capacity_liters), level_liters_(capacity_liters)
{
    std::cout << "[FuelTank] created: capacity=" << capacity_liters_ << " liters\n";
}

FuelTank::~FuelTank()
{
    std::cout << "[FuelTank] destroyed\n";
}

void FuelTank::refuel(double amount)
{
    if (amount < 0)
    {
        std::cout << "[FuelTank] refuel amount must be positive\n";
        return;
    }
    level_liters_ += amount;
    if (level_liters_ > capacity_liters_)
    {
        level_liters_ = capacity_liters_;
    }
    std::cout << "[FuelTank] refueled: new level=" << level_liters_ << " liters\n";
}

bool FuelTank::consume(double amount)
{
    if (amount < 0)
    {
        std::cout << "[FuelTank] consume amount must be positive\n";
        return false;
    }
    if (level_liters_ >= amount)
    {
        level_liters_ -= amount;
        std::cout << "[FuelTank] consumed: new level=" << level_liters_ << " liters\n";
        return true;
    }
    else
    {
        std::cout << "[FuelTank] not enough fuel to consume " << amount << " liters\n";
        return false;
    }
}

void FuelTank::diagnostics() const
{
    std::cout << "[FuelTank Diagnostics] Capacity: " << capacity_liters_
              << " liters, Current Level: " << level_liters_ << " liters\n";
}