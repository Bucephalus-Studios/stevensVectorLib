# stevensVectorLib
A C++ std::vector library that is simple and powerful

Currently posted a working, non-full release version here. Eventually, full version with tests, benchmarks, documentation, and more will be posted.

# Simple installation and usage:
You can use this map library with the Beldum Package Manager:

## Install
Import "stevensVectorLib.cpp" into your own project

or

### Beldum Package Manager: https://github.com/Nord-Tech-Systems-LLC/beldum_package_manager
```
mkdir new_project
cd new_project
beldum init
beldum install stevensVectorLib
```

## Usage
`src/main.cpp`
```cpp
#include <vector>
#include <string>
#include "stevensVectorLib.hpp"

int main()
{

    std::vector<std::string> test_vector;
    test_vector.push_back("Testing");
    stevensVectorLib::contains(test_vector, std::string("Testing"));
    return 0;
}

```