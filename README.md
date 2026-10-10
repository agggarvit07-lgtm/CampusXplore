# CampusXplore – Graph-Based Campus Navigation System

## 1. Project Description
CampusXplore is a C++ project that helps users find the shortest route between campus locations. It uses graph data structures and Dijkstra's algorithm to calculate the shortest distance.

## 2. Problem Statement and Objective
Finding routes between campus buildings can be confusing for students and visitors. CampusXplore aims to make navigation easier by finding the shortest route between a selected source and destination.

## 3. Team Members
- Garvit Aggarwal – Team Leader
- Raj Maletha
- Ranveer Singh Bisht
- Arnav Chamoli

## 4. Technologies and Tools Used
- **Programming Language:** C++
- **Concepts:** Data Structures and Algorithms, Object-Oriented Programming
- **Data Structures:** Graph, Adjacency List, Vector, Priority Queue
- **Algorithm:** Dijkstra's Shortest Path Algorithm
- **Tools:** Visual Studio Code, GCC, GitHub

## 5. Installation and Execution

1. Clone or download this repository.
2. Open the project folder in your terminal.
3. Compile the program:

   ```bash
   g++ step7.cpp
   ```

4. Run the program:

   **Windows:**
   ```bash
   .\a.exe
   ```

   **Linux:**
   ```bash
   ./a.out
   ```

Make sure GCC is installed and the source file is named `step7.cpp`.

## 6. Major Features and Modules
- **Location Management:** Stores campus location details.
- **Graph Construction:** Connects locations using weighted edges.
- **Source and Destination Search:** Allows users to select their starting point and destination.
- **Shortest Distance Calculation:** Uses Dijkstra's algorithm.
- **Route Display:** Displays the shortest route and total distance.
- **Multi-Floor Navigation:** Includes stairs and elevators to connect different floors.
- **Accessibility Option:** Allows users to avoid stairs when finding a route.

## 7. Project Development Steps
1. Created the Location class.
2. Built the Graph class and added weighted connections.
3. Added source and destination search.
4. Implemented Dijkstra's algorithm for shortest distance calculation.
5. Added route reconstruction and display.
6. Added multi-floor navigation using stairs and elevators.
7. Integrated all features and added the accessibility option.

## 8. Current Project Status
The C++ program includes location management, weighted connections, source and destination selection, shortest-distance calculation, route display, multi-floor navigation, and an accessibility option.

## 9. Future Improvements
- Add a graphical user interface.
- Include a visual campus map.
- Add more campus locations and routes.
- Improve navigation features.

## 10. Learning Outcomes
This project helped us understand graph representation, weighted connections, Dijkstra's algorithm, priority queues, and object-oriented programming in C++.
