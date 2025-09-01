# Advanced CLI Calculator (C Project)

**A modular C command-line calculator supporting arithmetic, scientific functions, and robust error handling — perfect for learning C and CLI programming.**

---

### 🖥️ Screenshot

<img width="708" height="272" alt="image" src="https://github.com/user-attachments/assets/067d9afe-e54b-4ecd-a53d-0153ce4dc77d" />

---

### ✨ Features

- Binary operations: `+`, `-`, `*`, `/`, `%` (remainder), `**` (power)  
- Unary operations: `sqrt`, `log`, `ln`, `abs`, `cos`, `sin`, `tan`, `exp`  
- Trigonometric inputs in degrees (converted internally to radians)  
- Error handling with exit codes for invalid input, divide by zero, domain errors  
- Smart output formatting (integers vs floats)  
- Modular design for easy extension  

---

### 🖥️ Usage

```bash
# Binary (two operands)
./cli-calculator 10 + 5        # 15
./cli-calculator 2 ** 3        # 8
./cli-calculator 7 / 2         # 3.5

# Unary (single operand)
./cli-calculator sqrt 25       # 5
./cli-calculator log 1000      # 3
./cli-calculator cos 60        # 0.5
```
---

### 🛠️ Build
You can compile the project using either method:
```
# Using gcc directly
gcc -std=c11 -O2 -Wall -Wextra -lm -o cli-calculator calculator.c

# Or, if using the CS50 environment
make cli-calculator
```
---

### 🚀 Exit Codes
```
0 – Success

1 – Invalid number of arguments

2 – Invalid operator or operation

3 – Division or modulo by zero

4 – Invalid number format

5 – Square root of negative number

6 – Log10 of non-positive number

7 – Natural log of non-positive number

8 – Tangent undefined (e.g., 90°, 270°, …)
```
---

### 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
