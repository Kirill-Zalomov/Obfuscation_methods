#include "args/args_parser.hpp"


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
    args_parser args_parser_;

    std::cout << std::setw(30)
              << "--add-garbage-lines: "
              << (args_parser_.check_opt_add_garbage_lines(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--add-ramdom-whitespaces: "
              << (args_parser_.check_opt_add_random_whitespaces(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--delete-newlines: "
              << (args_parser_.check_opt_delete_newlines(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--mess-up-comments: "
              << (args_parser_.check_opt_mess_up_comments(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--rename-variables: "
              << (args_parser_.check_opt_rename_variables(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--rename-variables: "
              << (args_parser_.check_opt_rename_variables(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--in: "
              << (args_parser_.check_opt_in(args) ? "true" : "false")
              << "\n";

    std::cout << std::setw(30)
              << "--out: "
              << (args_parser_.check_opt_out(args) ? "true" : "false")
              << "\n";

    try
    {
        std::cout << "\n\n input: "
                  << args_parser_.get_path_to_input_file ( args )
                  << "\n"
                  << "output: "
                  << args_parser_.get_path_to_output_file ( args )
                  << "\n\n";
    }
    catch(const std::exception& exception)
    {
        std::cout << exception.what() << std::endl;
    }


    return 0;
}
