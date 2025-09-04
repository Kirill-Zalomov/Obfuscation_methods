#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP


#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>


class args_parser
{
    public: bool check_opt_delete_newlines(const std::list<std::string> args) const;
    public: bool check_opt_add_garbage_lines(const std::list<std::string> args) const;
    public: bool check_opt_add_random_spaces(const std::list<std::string> args) const;
    public: bool check_opt_mess_up_comments(const std::list<std::string> args) const;
    public: bool check_opt_rename_variables(const std::list<std::string> args) const;
    public: bool check_opt_in(const std::list<std::string> args) const;
    public: bool check_opt_out(const std::list<std::string> args) const;

    public: std::string get_path_to_input_file(const std::list<std::string> args);
    public: std::string get_path_to_output_file(const std::list<std::string> args);
};


#endif // ARGS_PARSER_HPP
