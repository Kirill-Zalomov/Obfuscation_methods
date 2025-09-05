#include "args/args_parser.hpp"
#include "args/arg_checker.hpp"
#include "io/file_reader.hpp"
#include "tokenizer/tokenizer.hpp"
#include "tokenizer/token.hpp"
#include "tokenizer/token_printer.hpp"


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
    checkers_.push_back(arg_checker("--add-random-whitespaces"));
    checkers_.push_back(arg_checker("--delete-newlines"));
    checkers_.push_back(arg_checker("--mess-up-comments"));
    checkers_.push_back(arg_checker("--rename-variables"));


    tokenizer tokenizer_;
    file_reader file_reader_;
    token_printer token_printer_;

    std::list<std::string> lines_of_code_;
    std::list<token> tokens_;

    const std::string filename_ =
    "/home/kirillzalomov/Projects/Obfuscation_methods/lab1/max_finder.cpp";
    const std::string output_file_ =
    "/home/kirillzalomov/Projects/Obfuscation_methods/lab1/max_finder_new.cpp";

    lines_of_code_ = file_reader_.read_lines(filename_);
    tokens_ = tokenizer_.tokenize(lines_of_code_);

    token_printer_.print_tokens(tokens_);
    std::cout << "\n\n\n\n" << std::string(40, '-');

    token_printer_.print_tokens_in_file(output_file_, tokens_);




    return 0;
}
