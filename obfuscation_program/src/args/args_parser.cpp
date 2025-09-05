#include "args/args_parser.hpp"


std::string args_parser::get_value_of_arg(
    const std::list<std::string>& argv,
    const std::string& arg_name
) const
{
    for (const auto& current_arg : argv)
    {
        if (current_arg.find(arg_name) == 0)
        {
            return current_arg.substr(arg_name.size());
        }
    }
    throw std::runtime_error("Can't find value of argument \"" + arg_name + "\"");
}
