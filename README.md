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
- [License](#license)

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
   ```
2. Compile the program:
  ```bash
  cmake ..
  cmake --build .
```
3. Usage
   ```bash
  ./Iphone_Statistics ../data.csv
``
## Algorithms
- The project includes several algorithms for calculating profitability:

- most_profitable_of_whole: Calculates the most profitable phone over the entire period.
- most_profitable_of_first_year: Calculates the most profitable phone based on first-year sales.
- most_money_spent: Calculates the phone with the highest cost.
- most_sold_of_whole_time: Calculates the phone with the highest sales.

## File Formats
- CSV File
- The CSV file should follow the format:
- phone_model,starting_price,production_year,sale_first_year,sales_whole_time,bill_of_materials,price_inflation,bill_of_materials_inflation
iPhone X,999,2017,500000,1000000,400,5,2
...
## Contributing
- Feel free to contribute by opening issues or submitting pull requests. Please follow the code of conduct.

