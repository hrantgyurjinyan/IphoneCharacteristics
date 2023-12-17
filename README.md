# iPhone Profitability Calculator

This project provides a program for analyzing iPhone sales data and calculating profitability based on various criteria. The program reads phone information from a CSV file, performs calculations using different algorithms, and presents the results in sorted order.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Algorithms](#algorithms)
- [File Formats](#file-formats)
- [Contributing](#contributing)

## Features

- Calculates the most profitable iPhones based on different criteria.
- Reads phone information from a CSV file.
- Implements merge sort for sorting the results.

## Getting Started

### Prerequisites

- [POSIX-compliant system](https://en.wikipedia.org/wiki/POSIX) (for file operations)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/iphone-profitability-calculator.git
   cd iphone-profitability-calculator
2. Compile the program:
```bash
   cmake ..
   cmake --build .

3. Usage
Run the program with a CSV file containing iPhone data as a command-line argument:
```bash
    ./iphone_calculator your_file.csv

Follow the on-screen prompts to choose a calculation option.

