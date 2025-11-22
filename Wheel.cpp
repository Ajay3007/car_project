#include "Wheel.h"

Wheel::Wheel(Position position, double diameter, int id, double pressure)
    : position_(position), diameter_(diameter), id_(id), pressure_(pressure)
{
    std::cout << "[Wheel] created: id=" << id_ << ", position=" << static_cast<int>(position_)
              << ", diameter=" << diameter_ << ", pressure=" << pressure_ << "\n";
}

Wheel::~Wheel()
{
    std::cout << "[Wheel] destroyed: id=" << id_ << "\n";
}

void Wheel::inflate(double amount)
{
    pressure_ += amount;
    std::cout << "[Wheel] inflated: id=" << id_ << ", new pressure=" << pressure_ << "\n";
}

