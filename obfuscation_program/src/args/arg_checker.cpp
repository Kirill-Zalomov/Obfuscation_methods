#include "args/arg_checker.hpp"


bool arg_checker::check(
    std::list<std::string> argv,
    const std::string& value_to_find
) const
{
    return std::find(argv.begin(), argv.end(), value_to_find) != argv.end();
}
