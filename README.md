# stevensVectorLib
A C++ std::vector utility library that is simple, powerful, and efficient

A header-only library providing enhanced utilities for working with `std::vector`, featuring comprehensive tests and benchmarks.

## Features

- **Header-only**: Simply include `stevensVectorLib.hpp` in your project
- **Fully tested**: 88 comprehensive unit tests with Google Test
- **Benchmarked**: Performance benchmarks with Google Benchmark
- **Modern C++17**: Clean, efficient, and well-documented code
- **Zero dependencies**: Only requires C++ standard library

## Available Functions

- `contains()` - Check if vector contains an element
- `eraseAllOf()` - Remove all instances of an element
- `sumAll()` / `multiplyAll()` - Aggregate operations
- `findElementIndex()` - Find index of element
- `findMin()` - Find minimum element
- `getRandomElement()` - Get random element from vector
- `concat()` - Concatenate two vectors
- `getUncommonElements()` - Get symmetric difference of vectors
- `getLargestVectorElement()` - Find largest vector in 2D vector
- `getLongestStringElement()` - Find longest string in vector
- `reorient2DVector()` - Transpose a 2D vector
- `eraseDuplicateElements()` - Remove duplicates while preserving order
- `difference()` - Remove elements from first vector that appear in second
- `popFront()` - Remove and return first element
- `vecOfStrings_to_vecOfInts()` / `vecOfStrings_to_vecOfLongLongInts()` - String to numeric conversions

## Installation

### Option 1: Direct Include
Simply copy `stevensVectorLib.hpp` into your project and include it:
```cpp
#include "stevensVectorLib.hpp"
```

### Option 2: CMake Integration
Clone the repository and use CMake:
```bash
git clone https://github.com/Bucephalus-Studios/stevensVectorLib.git
cd stevensVectorLib
mkdir build && cd build
cmake ..
make
ctest  # Run tests
```

### Option 3: Beldum Package Manager
https://github.com/Nord-Tech-Systems-LLC/beldum_package_manager
```bash
mkdir new_project
cd new_project
beldum init
beldum install stevensVectorLib
```

## Usage Example
```cpp
#include <vector>
#include <string>
#include "stevensVectorLib.hpp"

int main()
{
    // Check if vector contains an element
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    bool has_three = stevensVectorLib::contains(numbers, 3);  // true

    // Remove duplicates
    std::vector<int> with_dupes = {1, 2, 2, 3, 3, 3};
    auto unique = stevensVectorLib::eraseDuplicateElements(with_dupes);  // {1, 2, 3}

    // Sum all elements
    int sum = stevensVectorLib::sumAll(numbers, 0);  // 15

    // Concatenate vectors
    std::vector<int> more_numbers = {6, 7, 8};
    auto combined = stevensVectorLib::concat(numbers, more_numbers);  // {1, 2, 3, 4, 5, 6, 7, 8}

    return 0;
}
```

## Building and Testing

### Build with CMake
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Run Tests
```bash
ctest --output-on-failure
```

### Run Benchmarks
```bash
./benchmarks/vector_lib_benchmarks
```

### CMake Options
- `BUILD_TESTS` (default: ON) - Build unit tests
- `BUILD_BENCHMARKS` (default: ON) - Build performance benchmarks

To disable tests or benchmarks:
```bash
cmake -DBUILD_TESTS=OFF -DBUILD_BENCHMARKS=OFF ..
```

## Requirements

- C++17 compatible compiler
- CMake 3.14 or higher (for building tests/benchmarks)

## Code Quality

This library has been optimized for:
1. **Simplicity** - Clear, straightforward implementations
2. **Readability** - Well-documented with descriptive names
3. **Functional abstraction** - Reusable, composable functions
4. **Encapsulation** - All functions in `stevensVectorLib` namespace
5. **DRY principle** - No code duplication
6. **Efficiency** - Pass by reference, reserve space, O(n) or better complexity
7. **Speed** - Optimized algorithms and minimal allocations
8. **Good variable names** - Self-documenting code
9. **Low nesting** - Maximum 2 levels of nesting per function

## License

See LICENSE file for details.

## Contributing

Contributions are welcome! Please feel free to submit pull requests.
