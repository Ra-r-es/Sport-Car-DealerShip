# Sport Car DealerShip Project

This project implements a car exhibition management system for different types of sports cars using C++. The system allows users to add, sell, display, and obtain details about various types of sports cars, including COUPE, CABRIO, HOTHATCH, and SUPERSPORT.

## Project Structure

The project consists of the following main components:

- **MasiniSport.h**: Base class for sports cars with basic properties and methods.
- **CABRIO.h, COUPE.h, HOTHATCH.h, SUPERSPORT.h**: Derived classes inheriting from `MasiniSport` with additional specific properties and methods for each type of car.
- **Expozitie.h**: Template class for managing collections (`vector`) of different types of sports cars (`COUPE`, `CABRIO`, `HOTHATCH`, `SUPERSPORT`), allowing addition, display, and sale of cars.
- **main.cpp**: Main program file implementing a command-line interface for interacting with the car exhibition system.

## Properties of Different Car Types

- **COUPE**: 2-door sports cars.
- **CABRIO**: Convertible sports cars with different roof types.
- **HOTHATCH**: Compact sports cars with high-performance engines.
- **SUPERSPORT**: High-performance sports cars with very high top speeds.

## Menu Commands

The program supports the following commands through a command-line interface:

- **ADD**: Adds a new car to the exhibition based on user input.
- **SELL**: Removes a car from the exhibition based on its index and type.
- **DISPLAY**: Displays all cars currently in the exhibition.
- **DETALII**: Displays details such as the total number of cars in the exhibition and the number of SUPERSPORT cars sold.

## How to Use

1. **Compilation**: Compile the program using a C++ compiler.
   
   Example:
   ```bash
   g++ main.cpp -o masini
1. **Commands**: Enter one of the supported commands (ADD, SELL, DISPLAY, DETALII, STOP) at the command prompt to interact with the system. Follow the prompts to provide necessary details for adding or selling cars.
Example:
   ```plaintext
   ADD
   Introduceti ce tip de masina doriti: COUPE
   Marca masini este: BMW
   Modelul este: M5
   In ce an a fost fabricata: 2024
   Pretul este: 80000
   Cati cai are motorul: 473

   SELL
   Introduceti numarul masinii:1
   Introduceti tipul masinii:COUPE
