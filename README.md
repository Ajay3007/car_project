# Car Simulation Project

A modern C++17 project demonstrating object-oriented design, composition, smart pointers (`std::unique_ptr`, `std::shared_ptr`), move semantics, and clean architecture using separate header/source files.

This project contains a simulated **Car system** with:
- `Engine` — horsepower, RPM control, start/stop behavior.
- `Wheel` — tire pressure, inflation.
- `FuelTank` — fuel level, consumption, refueling.
- `Car` — owns engine, wheels, fuel tank, and provides driving logic.
- `Garage` — manages multiple cars using shared ownership.

All components are split across `.h` and `.cpp` files, following best practices.

---

## 🚗 Features

### ✔ Modern C++ Design
- Uses **smart pointers** (`unique_ptr`, `shared_ptr`) instead of raw pointers.
- Follows **Rule of 0**, **RAII**, clean memory safety.
- Move-only `Car` to reflect real-world ownership.

### ✔ Object-Oriented Architecture
- Composition (`Car HAS-A Engine` / `Wheel` / `FuelTank`).
- Aggregation (`Garage` stores shared cars).
- Clear ownership semantics.

### ✔ Realistic Simulation Logic
- Engine diagnostics (RPM, state, horsepower).
- Fuel consumption per km.
- Wheel pressure tracking.
- Car diagnostics that summarize all components.

---

## 📁 Project Structure

```
CarProject/
├── Engine.h
├── Engine.cpp
├── Wheel.h
├── Wheel.cpp
├── FuelTank.h
├── FuelTank.cpp
├── Car.h
├── Car.cpp
├── Garage.h
├── Garage.cpp
├── MyCarMain.cpp
└── README.md
```

---

## 🛠 Build Instructions

### Using g++ directly
```bash
g++ -std=c++17 Engine.cpp Wheel.cpp FuelTank.cpp Car.cpp Garage.cpp MyCarMain.cpp -o car_app.exe
./car_app.exe
```

### Using VS Code Task (recommended)
Press `Ctrl + Shift + B` to build using your configured `tasks.json`.
Run the app using:
```bash
./car_app.exe
```

---

## 📘 How It Works

### Engine
- Created with serial number and horsepower.
- Can be started/stopped.
- Tracks RPM and state.

### FuelTank
- Tracks capacity and remaining fuel.
- Responsible for consuming and refueling.

### Wheel
- Tracks tire pressure.
- Can be inflated.

### Car
- Owns engine, tank, and wheels using `unique_ptr`.
- Supports driving with fuel consumption.
- Provides system-wide diagnostics.

### Garage
- Holds `shared_ptr<Car>` allowing multiple systems to reference cars.

---

## 🧪 Example Output
```
[Engine] created: serial=ENG-0001, type=1, horsepower=150
[FuelTank] created: capacity=50 liters
[Car] created: VIN=VIN-1234567890
[Wheel] created: id=1, position=0, diameter=16, pressure=32
[Car] Added wheel: VIN=VIN-1234567890, Total Wheels=1
[Wheel] created: id=2, position=1, diameter=16, pressure=32
[Car] Added wheel: VIN=VIN-1234567890, Total Wheels=2
[Wheel] created: id=3, position=2, diameter=16, pressure=30
[Car] Added wheel: VIN=VIN-1234567890, Total Wheels=3
[Wheel] created: id=4, position=3, diameter=16, pressure=30
[Car] Added wheel: VIN=VIN-1234567890, Total Wheels=4
[Car Diagnostics] VIN: VIN-1234567890, Odometer: 0 km, Wheels: 4
[Engine Diagnostics] Serial: ENG-0001, Type: 1, Horsepower: 150, State: STOPPED, RPM: 0
[FuelTank Diagnostics] Capacity: 50 liters, Current Level: 50 liters
  [Wheel] ID: 1, Position: 0, Diameter: 16, Pressure: 32
  [Wheel] ID: 2, Position: 1, Diameter: 16, Pressure: 32
  [Wheel] ID: 3, Position: 2, Diameter: 16, Pressure: 30
  [Wheel] ID: 4, Position: 3, Diameter: 16, Pressure: 30
[Engine] started: serial=ENG-0001, rpm=800
[FuelTank] consumed: new level=43.3333 liters
[Car] Drove 100 km: VIN=VIN-1234567890, Odometer=100 km
[Car Diagnostics] VIN: VIN-1234567890, Odometer: 100 km, Wheels: 4
[Engine Diagnostics] Serial: ENG-0001, Type: 1, Horsepower: 150, State: RUNNING, RPM: 800
[FuelTank Diagnostics] Capacity: 50 liters, Current Level: 43.3333 liters
  [Wheel] ID: 1, Position: 0, Diameter: 16, Pressure: 32
  [Wheel] ID: 2, Position: 1, Diameter: 16, Pressure: 32
  [Wheel] ID: 3, Position: 2, Diameter: 16, Pressure: 30
  [Wheel] ID: 4, Position: 3, Diameter: 16, Pressure: 30
[Engine] stopped: serial=ENG-0001
[Garage] Parking car: VIN=VIN-1234567890
[Garage] Listing cars:
  - VIN: VIN-1234567890
[Garage] Retrieving car: VIN=VIN-1234567890
[Car Diagnostics] VIN: VIN-1234567890, Odometer: 100 km, Wheels: 4
[Engine Diagnostics] Serial: ENG-0001, Type: 1, Horsepower: 150, State: STOPPED, RPM: 0
[FuelTank Diagnostics] Capacity: 50 liters, Current Level: 43.3333 liters
  [Wheel] ID: 1, Position: 0, Diameter: 16, Pressure: 32
  [Wheel] ID: 2, Position: 1, Diameter: 16, Pressure: 32
  [Wheel] ID: 3, Position: 2, Diameter: 16, Pressure: 30
  [Wheel] ID: 4, Position: 3, Diameter: 16, Pressure: 30
Program completed successfully.
[Car] destroyed: VIN=VIN-1234567890
[Wheel] destroyed: id=1
[Wheel] destroyed: id=2
[Wheel] destroyed: id=3
[Wheel] destroyed: id=4
[FuelTank] destroyed
[Engine] destroyed: serial=ENG-0001
```

---

## 🧩 Future Enhancements (Ideas)
- Add `Vehicle` base class → derive `Car`, `Truck`, `Bike`.
- Add JSON configuration for cars.
- Add UI dashboard using ImGui.
- Add networking to simulate telemetry.
- Add unit tests using GoogleTest.

---

## 📄 License
This project is open for educational use.

---

## 👨‍💻 Author
Created by **Ajay Gupt** as part of C++ OOP learning and system design practice.
