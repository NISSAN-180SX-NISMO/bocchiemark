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


    std::cout << "[sum]"
    << "sum result: " << bocchie::manager::get("sum").run(silly_sum, 1, 2)
    << "; avg time for " << bocchie::manager::get("sum").get_total_runs() << " runs: "
    << bocchie::manager::get("sum").get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    std::cout << "[hello_world]"
    << "hello world result: " << bocchie::manager::get("hello_world").run(silly_hello_world)
    << "; avg time for " << bocchie::manager::get("hello_world").get_total_runs() << " runs: "
    << bocchie::manager::get("hello_world").get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    bocchie::manager::get("procedure").run(silly_procedure);
    std::cout << "[procedure]"
    << "avg time for " << bocchie::manager::get("procedure").get_total_runs() << " runs: "
    << bocchie::manager::get("procedure").get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    bocchie::mark lambda_runner("lambda");
    lambda_runner.run(silly_lambda);
    std::cout << "avg time for " << lambda_runner.get_total_runs() << " runs: "
    << lambda_runner.get_avg_time<bocchie::accuracy::milliseconds>() << "ms" << std::endl;

    return 0;
}
