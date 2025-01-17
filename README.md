# Bocchiemark

Bocchiemark is a simple C++ benchmarking library. It allows you to measure the execution time of your functions and methods in a convenient and straightforward way.

## Features

- Measure execution time in different units (seconds, milliseconds, microseconds, nanoseconds).
- Run any function or method and get its execution time.
- Get minimum, maximum, total, and average execution time for multiple runs.
- Convert benchmark results to JSON format.

## Usage

Here is a simple usage example:

```cpp
#include "Bocchiemark.h"

int main() {
    bocchie::mark sum_runner("sum");
    std::cout << "[" << sum_runner.get_runnable_name() << "]"
    << "sum result: " << sum_runner.run(silly_sum, 1, 2)
    << "; avg time for " << sum_runner.get_total_runs() << " runs: "
    << sum_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    // ... other benchmarks ...

    return 0;
}
```

In this example, `silly_sum` is a function that you want to benchmark. You can replace it with any function or method you want to measure.

## Installation

To use Bocchiemark in your project, include the `Bocchiemark.h` header file in your source code.

```cpp
#include "Bocchiemark.h"
```

## License

Bocchiemark is open-source software released under [INSERT LICENSE HERE].

## Contributing

Contributions to Bocchiemark are welcome. Please submit a pull request or open an issue on GitHub.

## Contact

If you have any questions or suggestions, please open an issue on GitHub.

## WTF is this?