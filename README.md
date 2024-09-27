# Toy Robot Simulator

This is a C++17 implementation of the Toy Robot Code Challenge.

## Description

The application simulates a toy robot moving on a 5x5 unit square tabletop. The robot can be placed on the table, moved, rotated, and it can report its position.

It has been built following SOLID principles and with the intention of using clean maintable and extensable code over peformance.

## How to Build

This project uses CMake for building.

### Requirements

- C++17 compatible compiler (e.g., GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10+

### Build Steps

1. Clone the repository or download the source code.

   ```sh
   git clone https://github.com/maddernd/Toy-Robot-Simulator.git
   cd Toy-Robot-Simulator

2. Create a build directory and navigate into it:
   mkdir build
   cd build

3. Configure the project using CMake:
   cmake ..

4. Build the project:
   make

5. run the Toy Robot Simulator:
   ./toy_robot

   The application will accept commands through standard input. You can use the following commands:

   PLACE X,Y,F: Place the robot at position (X, Y) facing F (NORTH, SOUTH, EAST, or WEST).

   MOVE: Move the robot one unit forward in the direction it is currently facing.
   
   LEFT: Rotate the robot 90 degrees to the left.
   
   RIGHT: Rotate the robot 90 degrees to the right.

### How to Run Tests
   You need to install Google Test if it's not already available on your system.
   git clone https://github.com/google/googletest.git googletest
 
1. Build test suite 
   make test_robot

2. Run Tests
   ./test_robot

### Notes
   1. Maintainability:
   By adhering to the Single Responsibility Principle (SRP), each class and module has a clear and focused purpose, making it easier to maintain and update without unintended side effects.
   The use of Command Pattern ensures that commands like Move, Place, and Turn are encapsulated in their own classes, making it easy to debug or update specific functionality.

   2. Extensibility:
   The program is designed to be open for extension but closed for modification (OCP). New commands can be added (e.g., JumpCommand, StopCommand) by simply creating new classes without modifying existing code.
   The Command abstraction and CommandParser allow the system to handle new functionality without breaking existing features.

   3. Code over Performance:
   The emphasis here has been on clean design and architecture rather than performance. For instance, using polymorphism through the Command interface introduces some overhead compared to a tightly coupled design but provides greater flexibility.
   Input parsing, command execution, and error handling are designed to prioritize robustness and clarity rather than raw speed, which aligns with the goal of producing easily maintainable code.

   4. Scalability:
   The design using Dependency Inversion ensures that the Robot class and Command classes are decoupled. This makes it easier to change the underlying implementation or add new features without breaking the core logic.
   The system is modular, and components can be swapped or extended as needed without impacting the overall structure.