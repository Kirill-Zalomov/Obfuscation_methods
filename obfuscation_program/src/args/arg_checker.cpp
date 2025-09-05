#include "args/arg_checker.hpp"


arg_checker::arg_checker(std::string arg_to_check)
: arg_to_check_(arg_to_check) {}


std::string arg_checker::get_arg_to_check_() const noexcept
{
    return arg_to_check_;
}


void arg_checker::set_arg_to_check_(
    const std::string& new_arg_to_check
) noexcept
{
    arg_to_check_ = new_arg_to_check;
}


bool arg_checker::check(std::list<std::string> argv) const
{
    return std::find(argv.begin(), argv.end(), arg_to_check_) != argv.end();
}
