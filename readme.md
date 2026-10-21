# Data Communication Project

A C++ implementation of fundamental data communication techniques, including binary data generation, line coding, digital scrambling, palindrome detection, and Pulse Code Modulation (PCM).

## Features

### 1. Binary Data Generation
- Generate random binary data.
- Generate binary sequences containing four consecutive zeros.
- Generate binary sequences containing eight consecutive zeros.

### 2. Longest Palindrome Detection
- Identify the longest palindromic substring in a binary sequence.
- Display the palindrome and its length.

### 3. Line Coding
The project implements digital line coding schemes, including:
- NRZ-L (Non-Return-to-Zero Level)
- NRZ-I (Non-Return-to-Zero Invert)
- Manchester
- Differential Manchester
- AMI (Alternate Mark Inversion)

### 4. Digital Scrambling
- B8ZS (Bipolar with Eight-Zero Substitution)
- HDB3 (High-Density Bipolar 3-Zero)

These techniques help maintain synchronization by handling long sequences of consecutive zeros.

### 5. PCM Encoder and Decoder
- Accept sample values within the supported range of -10 to 10.
- Quantize samples into eight levels.
- Encode each sample using a 3-bit PCM code.
- Decode PCM codes into reconstructed sample values.
- Display the reconstructed signal as a staircase-style text visualization.
- Export reconstructed sample values to `pcm_output.csv`.

## Technologies Used

- **Language:** C++
- **Compiler:** GCC / G++
- **Version Control:** Git and GitHub
- **Build Environment:** Windows, Linux, or another environment supporting a compatible C++ compiler

## Project Structure

```text
Data-Communication-project/
├── src/
│   ├── main.cpp
│   ├── data/
│   │   ├── data_generator.cpp
│   │   └── data_generator.h
│   ├── line_coding/
│   │   └── line_coding.cpp
│   ├── line_coding.h
│   ├── pallindrome/
│   │   ├── pallindrome.cpp
│   │   └── pallindrome.h
│   └── pcm/
│       ├── pcm.cpp
│       └── pcm.h
├── .gitignore
└── README.md
```

*Note: Additional test files and optional visualization sources may also be present in the repository.*

## Prerequisites

Install a C++ compiler that supports C++11 or later. GCC/G++ is recommended.

Verify the compiler installation:

```bash
g++ --version
```

## Build and Run

Run the following commands from the repository root.

### Compile

```bash
g++ -std=c++11 src/main.cpp src/data/data_generator.cpp src/pallindrome/pallindrome.cpp src/line_coding/line_coding.cpp src/pcm/pcm.cpp -o project.exe
```

### Run on Windows PowerShell

```powershell
.\project.exe
```

On Linux, use `-o project` when compiling, then run:

```bash
./project
```

If the project uses a different entry point or a module is not linked from `main.cpp`, adjust the compile command accordingly.

## PCM Output

The PCM module writes reconstructed sample values to `pcm_output.csv` in the current working directory. This file is generated when the PCM functionality runs successfully.

## Testing

The repository includes test sources for functionality such as palindrome detection, performance testing, and scrambling. Compile each test with its required implementation files before running it.

For example, if `src/line_coding/scrambling_test.cpp` is present:

```bash
g++ -std=c++11 src/line_coding/line_coding.cpp src/line_coding/scrambling_test.cpp -o scrambling_test.exe
.\scrambling_test.exe
```

## Learning Objectives

This project demonstrates:
- Binary sequence generation and processing.
- Digital line coding and signal representation.
- Zero-substitution scrambling techniques.
- PCM quantization, encoding, and decoding.
- Modular C++ development and testing.

## Contributors

Developed as an academic Data Communication project.

See the repository's Git history for individual contributions.
