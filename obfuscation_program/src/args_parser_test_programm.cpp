#include "args/args_parser.hpp"
#include "args/arg_checker.hpp"


#include <list>
#include <string>
#include <iostream>
#include <iomanip>


std::list<std::string> argv_to_list(int argc, char** argv)
{
    std::list<std::string> args;
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }

    return args;
}


int main(int argc, char** argv)
{
    std::list<std::string> args = argv_to_list(argc, argv);
    std::list<arg_checker> checkers_;
    args_parser args_parser_;

    checkers_.push_back(arg_checker("--in"));
    checkers_.push_back(arg_checker("--out"));
    checkers_.push_back(arg_checker("--add-garbage-lines"));
    checkers_.push_back(arg_checker("--add-ramdom-whitespaces"));
    checkers_.push_back(arg_checker("--delete-newlines"));
    checkers_.push_back(arg_checker("--mess-up-comments"));
    checkers_.push_back(arg_checker("--rename-variables"));

    for (auto checker : checkers_)
    {
        std::cout << std::setw(30) << checker.get_arg_to_check_() << ": "
                  << (checker.check(args) ? "true" : "false") << "\n";
    }

    try
    {
        std::cout << "\n\n input: "
                  << args_parser_.get_value_of_arg(args, "--in=")
                  << "\n"
                  << "output: "
                  << args_parser_.get_value_of_arg (args, "--out=")
                  << "\n\n";
    }
    catch(const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}
