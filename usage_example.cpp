#include <iostream>
#include <thread>
#include "Bocchiemark.h"

#define sleep std::this_thread::sleep_for(std::chrono::milliseconds(1234));

int silly_sum(int a, int b) { sleep return a + b; }

std::string silly_hello_world() { sleep return "hello world!";}

void silly_procedure() { sleep }

auto silly_lambda = []() { sleep return 0; };

auto silly_void_lambda = []() { sleep return 0; }; // FIXME: this is not working

int main() {

    bocchie::mark sum_runner("sum");
    std::cout << "[" << sum_runner.get_runnable_name() << "]"
    << "sum result: " << sum_runner.run(silly_sum, 1, 2)
    << "; avg time for " << sum_runner.get_total_runs() << " runs: "
    << sum_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    bocchie::mark hello_world_runner("hello_world");
    std::cout << "[" << sum_runner.get_runnable_name() << "]"
    << "hello world result: " << hello_world_runner.run(silly_hello_world)
    << "; avg time for " << hello_world_runner.get_total_runs() << " runs: "
    << hello_world_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    bocchie::mark procedure_runner("procedure");
    procedure_runner.run(silly_procedure);
    std::cout << "[" << sum_runner.get_runnable_name() << "]"
    << "avg time for " << procedure_runner.get_total_runs() << " runs: "
    << procedure_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    bocchie::mark lambda_runner("lambda");
    lambda_runner.run(silly_lambda);
    std::cout << "avg time for " << lambda_runner.get_total_runs() << " runs: "
    << lambda_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    return 0;
}
