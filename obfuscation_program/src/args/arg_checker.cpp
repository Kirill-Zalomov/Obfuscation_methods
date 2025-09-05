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


bool arg_checker::check(const std::list<std::string>& argv) const
{
    std::string prefix = arg_to_check_ + "=";
    for (const auto& arg : argv) {
        if (arg == arg_to_check_ || (arg.compare(0, prefix.size(), prefix) == 0)) {
            return true;
        }
    }
    return false;
}
