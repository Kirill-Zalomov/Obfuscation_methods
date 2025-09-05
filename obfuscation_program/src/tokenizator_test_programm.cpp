#include "io/file_reader.hpp"
#include "tokenizer/tokenizer.hpp"
#include "tokenizer/token.hpp"
#include "tokenizer/token_printer.hpp"


#include <iostream>
#include <string>
#include <list>


int main()
{
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
}
