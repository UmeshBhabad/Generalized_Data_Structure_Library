📚 Data Structures Library — CUI Based Interactive Application

Data Structures Library CLI is a menu-driven C++ application designed to interactively demonstrate and test a custom-built, generalized data structures library.

The project is inspired by the concept of the Standard Template Library (STL), where reusable, generic data structures and their associated operations are encapsulated into a unified library for ease of use.

---

📌 Project Overview

This project focuses on building a custom data structures library from scratch, similar in spirit to the STL, and providing a CLI-based interface to interact with it.

The library exposes various data structures along with their core operations (insert, delete, traversal, etc.), while the CLI application acts as a testing and demonstration layer.

It helps in understanding:

    - Internal working of data structures
    - Design of reusable libraries
    - Separation between implementation and interface

---

⚙️ Features
    ✅ Custom-built data structures library inspired by STL design principles
    ✅ Generic (template-based) implementations for reusability
    ✅ Menu-driven Command Line Interface (CUI)
    ✅ Modular design for each data structure
    ✅ Supports multiple linear and non linear data structures:
        Singly Linear Linked List
        Singly Circular Linked List
        Doubly Linear Linked List
        Doubly Circular Linked List
        Stack
        Queue
        Binary Search Tree
        Graph(working on graphs)
        Sorting algorithms
        Searching algorithms

✅ Encapsulated operations:
    Insert
    Delete
    Display
    Count
✅ Dynamic memory management
✅ Real-time feedback after each operation
✅ Scalable architecture for adding new structures

---

🛠️ Tech Stack

Language: C++
Concepts Used:
    - Object-Oriented Programming (OOP)
    - Templates (Generic Programming)
    - Dynamic Memory Allocation
    - Modular Design
    - CLI Interaction Handling

---

📂 Project Structure

    ds-library-cli/
    │
    ├── menu.cpp              # CLI application (menu-driven interface)
    ├── library_ds.h          # Custom STL-like data structures library
    ├── README.md             # Project documentation

---

🚀 Installation

    1️⃣ Clone the Repository
    git clone https://github.com/your-username/ds-library-cli.git
    cd ds-library-cli

    2️⃣ Compile the Program
    g++ menu.cpp -o ds_app

    ▶️ Usage
    Run the application:
        ./ds_app

---

🖥️ How It Works
    1. User selects a data structure from the main menu
    2. A dedicated submenu is displayed
    3. User performs operations such as:
        Insert
        Delete
        Display
        Count
    4. The library executes the operation internally
    5. CLI displays updated state and feedback
    6. User can return to main menu anytime

---

🧪 Example Interaction
========================= Singly Linear Linked List Menu =========================

1. Insert at first position
2. Insert at last position
3. Insert at given position
4. Delete node at first position
5. Delete node at last position
6. Delete node at given position
7. Display elements
8. Count number of elements
0. Return to Main Menu

Enter choice: 1
Enter value: 10

Element inserted successfully
Current Node Count: 1

---

🧠 Design Highlights
    - STL-Inspired Library Design
        Implemented reusable, generic data structures similar to how STL provides containers and operations.
    - Separation of Concerns
        -- Library → Data structure logic
        -- CLI → User interaction
    - Modular Architecture
    - Each data structure has its own menu handler and implementation.
    - Reusable Interaction Pattern
        Display Menu → Input → Execute → Feedback → Repeat

---

🔮 Future Enhancements
- Add non-linear data structures:
    -- Graph
    -- Heap
- Iterator-like functionality (STL-style traversal)
- Persistent storage (save/load structures)
- Command-based CLI (advanced mode)
- Robust input validation system
- Performance benchmarking of operations

--- 

👨‍💻 Author

Umesh Shivaji Bhabad
📫 umeshbhabad9@gmail.com

---

⭐ Support

If you find this project useful, consider giving it a ⭐ on GitHub!