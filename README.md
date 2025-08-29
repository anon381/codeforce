# Codeforces Solutions (C++)

Collection of C++ solutions to Codeforces problems. Used for daily practice and tracking algorithmic progress.

## 🔍 About
* Language: **C++20** (single-file solutions, typically using `<bits/stdc++.h>` for convenience)
* Focus: Implementation speed + clarity (not always the absolute optimal micro-optimization)
* Topics covered: graphs, number theory, brute force, greedy, DP, strings, data structures

## 🏅 Codeforces Profile
<p align="center">
<img src="https://codeforces-readme-stats.vercel.app/api/card?username=anonized&theme=github_dark&title_color=FFFFF0&icon_color=1E90FF&text_color=FFFFF0&bg_color=0D1117" height="400" alt="Codeforces Stats"/>
</p>
## 📁 Repository Layout
Each source file is named with the pattern:

```
<ProblemID><OptionalLetterDash><ReadableTitle>.cpp
```

Examples:
* `20C-Dijkstra.cpp` – shortest path with Dijkstra
* `26A-AlmostPrime.cpp` – counting numbers with exactly two distinct prime divisors
* `34A-Reconnaissance2.cpp` – minimal adjacent circular difference

Older or alternative attempts may have `-old` or spacing quirks preserved from contest copy/paste.

## ▶️ How to Compile & Run (Windows / PowerShell)
Compile a single solution (replace filename as needed):

```
g++ -std=c++17 -O2 -pipe -static -s 20C-Dijkstra.cpp -o dijkstra.exe
./dijkstra.exe < input.txt
```

If `g++` is not available, install MinGW-w64 or use WSL (Ubuntu) and run the same command.

## 🧪 Testing Quickly
Create a small inline test:

```
echo "5 6\n1 2 3\n1 3 1\n2 4 5\n3 4 2\n3 5 4\n4 5 1" > graph.txt
g++ -std=c++17 -O2 20C-Dijkstra.cpp -o d.exe && ./d.exe < graph.txt
```

---

## ✨ Style Notes
* Uses fast I/O (`scanf/printf` or `ios::sync_with_stdio(false)`).
* Minimal abstractions—contest speed preferred over heavy structure.
* Occasional exploratory / legacy versions retained for comparison.

## 🚀 Possible Future Improvements
* Add a simple build script to compile all files.
* Introduce a markdown index mapping files to original Codeforces problem links.
* Add unit-style harness for reusable algorithms (DSU, Dijkstra, etc.).

## 📜 Disclaimer
These are personal practice solutions. They are not guaranteed to be the most elegant or fastest; they aim for correctness first, then clarity.

---
Feel free to fork / study. Happy coding!
