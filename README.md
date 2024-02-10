# Lab 5: Binary I/O Files

## Overview
Lab 5 is a C++ project demonstrating binary file input/output (I/O) operations, focusing on reading and writing structured data to and from binary files. It simulates managing spacecraft information stored in binary format, showcasing efficient data serialization and deserialization techniques.

## Repository Structure
- **main.cpp:** Implements the logic for reading and writing spacecraft data to binary files. It features classes for storing ship and weapon information and functions to perform various binary file operations.
- **main.h:** The header file for main.cpp, declaring the classes and functions used.
- **enemyships.shp & friendlyships.shp:** Binary files containing serialized data for enemy and friendly spacecraft, respectively.
- **Lab 5.pdf:** Documentation providing detailed instructions and specifications for the binary I/O operations project.

## Key Features
- **Class Serialization:** Demonstrates how to serialize complex objects into a binary file and deserialize them back into objects in C++.
- **Binary File Management:** Showcases reading from and writing to binary files using C++ stream classes std::ifstream and std::ofstream in binary mode.
- **Data Structures:** Utilizes custom data structures (ShipInfo and WeaponType classes) to represent spacecraft and their armaments, illustrating object-oriented programming principles.

## Usage
To run the project:
1. Compile main.cpp using a C++ compiler supporting C++11 or later.
2. Execute the compiled program. The application will prompt you to choose between reading enemy ship data, friendly ship data, or both, and perform operations such as listing all ships or finding the strongest ship based on its armament.

## Getting Started
Ensure you have a C++ development environment set up. Compile the source code as follows (example using g++):
```
g++ -o binary_io main.cpp
./binary_io
```
## Follow the on-screen prompts to interact with the binary files and explore the functionalities implemented.

## Contributing
Contributions to enhance the functionality, improve documentation, or fix bugs are welcome. Please fork the repository, make your changes, and submit a pull request for review.

## License
This project is open-source and available under the MIT License. See the LICENSE file for more information.

## Acknowledgments
This project was created as part of a computer science course to teach students about binary file operations in C++. Special thanks to all contributors and educators who have provided feedback and improvements.
