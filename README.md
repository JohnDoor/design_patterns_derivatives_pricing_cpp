# Quant Finance C++ Library

This repository is a personal library for learning and experimenting with quantitative finance models using C++.  
It combines structured design patterns with financial modeling techniques, drawing inspiration from professional practices in the industry.

## 🎯 Purpose

- Apply and solidify knowledge from mathematical finance using C++
- Design clean, reusable components following object-oriented and modular principles
- Build a practical foundation for pricing derivatives and modeling financial instruments

## 📂 Project Structure

Each folder contains a self-contained C++ mini-project with its own `main.cpp`, demonstrating a specific concept or model:

```plaintext quant-finance-cpp/ │ ├── 01-option-pricing-simpleMC/ # Monte Carlo pricing for European options │ ├── main.cpp │ ├── Random1.cpp / Random1.h │ └── CMakeLists.txt │ ├── 02-.../ # (Future modules) │ └── README.md ```

## 📌 Dependencies

- C++17 compiler (tested with g++)

## 🧮 Models Implemented & Planned

- Simple Monte Carlo simulation for European options
- Gaussian random number generation (Summation & Box-Muller)
Planned models and components include:

- Procedural Monte Carlo pricing for vanilla options
- Object-oriented payoff abstraction (encapsulation, polymorphism)
- Improved design via inheritance and virtual interfaces
- Virtual constructors, the bridge pattern, and reusable parameter classes
- Strategy and decorator patterns for analytics and convergence tools
- Modular random number generators with adapters and clean interfaces
- Pricing of path-dependent exotic options (e.g., Asian options)
- Binomial and trinomial tree-based pricing frameworks
- Templates and reusable solver classes (e.g., implied volatility)
- Factory and singleton patterns for dynamic model construction
- Design principles for clean, testable, and extensible quant code

## 🛠️ How to Build

- Visual Studio Code (or any editor)
- Git Bash or terminal

### 🧱 Using Visual Studio Code (with Git Bash or terminal)

```bash
cd 01-option-pricing-simpleMC
g++ main.cpp Random1.cpp -o simpleMC.exe
./simpleMC.exe
```

### ✍️ Author

Giovanni Porta
Mathematical Engineer & Quantitative Finance Enthusiast
Currently working as a Quantitative Risk Analyst at Morgan Stanley.
📍 Budapest
🔗 LinkedIn (www.linkedin.com/in/giovanni-porta)
📝 Disclaimer

This project is for educational and personal development purposes only.
Not intended for production use or financial advice.
