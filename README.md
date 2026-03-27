<h1 align="center">📚 Data Structures Library — CUI Based Interactive Application</h1>

<p align="center">
A modular, menu-driven C++ application designed to demonstrate and test a custom-built, STL-inspired data structures library.
</p>

<hr>

<h2>📌 Project Overview</h2>

<p>
This project focuses on building a <b>custom data structures library from scratch</b>, inspired by the design principles of the <b>Standard Template Library (STL)</b>.
It provides reusable, generic implementations of commonly used data structures along with a Command Line Interface (CUI) to interact with them.
</p>

<p>
The CLI acts as a testing layer, allowing users to dynamically perform operations like insertion, deletion, traversal, and analysis in real-time.
</p>

<ul>
<li>Understanding internal working of data structures</li>
<li>Designing reusable and generic libraries</li>
<li>Maintaining separation between implementation and interface</li>
</ul>

<hr>

<h2>⚙️ Features</h2>

<ul>
<li>Custom-built data structures library inspired by STL</li>
<li>Generic implementations using C++ templates</li>
<li>Menu-driven Command Line Interface (CUI)</li>
<li>Modular architecture for each data structure</li>
<li>Dynamic memory management</li>
<li>Real-time feedback after each operation</li>
<li>Scalable design for future extensions</li>
</ul>

<h3>Supported Data Structures</h3>

<ul>
<li>Singly Linear Linked List</li>
<li>Singly Circular Linked List</li>
<li>Doubly Linear Linked List</li>
<li>Doubly Circular Linked List</li>
<li>Stack</li>
<li>Queue</li>
<li>Binary Search Tree</li>
<li>Graph (in progress)</li>
<li>Sorting Algorithms</li>
<li>Searching Algorithms</li>
</ul>

<h3>Core Operations</h3>

<ul>
<li>Insert</li>
<li>Delete</li>
<li>Display</li>
<li>Count</li>
</ul>

<hr>

<h2>🛠️ Tech Stack</h2>

<ul>
<li><b>Language:</b> C++</li>
</ul>

<h3>Concepts Used</h3>

<ul>
<li>Object-Oriented Programming (OOP)</li>
<li>Templates (Generic Programming)</li>
<li>Dynamic Memory Allocation</li>
<li>Modular Design</li>
<li>CLI Interaction Handling</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>

<pre>
ds-library-cli/
│
├── menu.cpp              # CLI application (menu-driven interface)
├── library_ds.h          # Custom STL-like data structures library
├── README.md             # Project documentation
</pre>

<hr>

<h2>🚀 Installation</h2>

<h3>1️⃣ Clone the Repository</h3>
<pre>
git clone https://github.com/your-username/ds-library-cli.git
cd ds-library-cli
</pre>

<h3>2️⃣ Compile the Program</h3>
<pre>
g++ menu.cpp -o ds_app
</pre>

<hr>

<h2>▶️ Usage</h2>

<pre>
./ds_app
</pre>

<hr>

<h2>🖥️ How It Works</h2>

<ol>
<li>User selects a data structure from the main menu</li>
<li>A dedicated submenu is displayed</li>
<li>User performs operations (Insert, Delete, Display, Count)</li>
<li>The library executes operations internally</li>
<li>CLI displays updated state and feedback</li>
<li>User can return to main menu anytime</li>
</ol>

<hr>

<h2>🧪 Example Interaction</h2>

<pre>
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
</pre>

<hr>

<h2>🧠 Design Highlights</h2>

<ul>
<li><b>STL-Inspired Library Design</b> – Generic reusable data structures</li>
<li><b>Separation of Concerns</b> – Library logic vs CLI interaction</li>
<li><b>Modular Architecture</b> – Each DS has independent menu handler</li>
<li><b>Reusable Interaction Pattern</b> – Menu → Input → Execute → Feedback</li>
</ul>

<hr>

<h2>🔮 Future Enhancements</h2>

<ul>
<li>Graph implementation</li>
<li>Heap data structure</li>
<li>Iterator-style traversal (STL-like)</li>
<li>Persistent storage (save/load)</li>
<li>Command-based CLI</li>
<li>Robust input validation system</li>
<li>Performance benchmarking</li>
</ul>

<hr>

<h2>👨‍💻 Author</h2>

<p>
<b>Umesh Shivaji Bhabad</b><br>
📫 umeshbhabad9@gmail.com
</p>

<hr>

<h2>⭐ Support</h2>

<p>If you find this project useful, consider giving it a ⭐ on GitHub!</p>

<hr>

<!-- ================= PROFILE MARKDOWN SECTION ================= -->

<h1 align="center">Hi 👋, I'm Umesh Bhabad</h1>
<h3 align="center">A passionate Software developer from India</h3>

<p>
🌱 I’m currently learning <b>Data Structures and algorithms</b><br>
👨‍💻 All of my projects are available at 
<a href="https://github.com/UmeshBhabad">GitHub Profile</a><br>
📫 How to reach me <b>umeshbhabad9@gmail.com</b>
</p>

<h3 align="left">Languages and Tools:</h3>

<p align="left"> 
<a href="https://www.w3schools.com/cpp/" target="_blank"> 
<img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" width="40" height="40"/> 
</a> 
<a href="https://git-scm.com/" target="_blank"> 
<img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" width="40" height="40"/> 
</a> 
</p>