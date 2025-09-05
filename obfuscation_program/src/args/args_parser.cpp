#include "args/args_parser.hpp"


bool args_parser::check_opt_delete_newlines(const std::list<std::string>& args) const
{
    return std::find(args.begin(), args.end(), "--delete-newlines") != args.end();
}


bool args_parser::check_opt_add_garbage_lines(const std::list<std::string>& args) const
{
    return std::find(args.begin(), args.end(), "--add-garbage-lines") != args.end();
}


bool args_parser::check_opt_add_random_whitespaces(const std::list<std::string>& args) const
{
    return std::find(args.begin(), args.end(), "--add-random-whitespaces") != args.end();
}


bool args_parser::check_opt_mess_up_comments(const std::list<std::string>& args) const
{
    return std::find(args.begin(), args.end(), "--mess-up-comments") != args.end();
}


bool args_parser::check_opt_rename_variables(const std::list<std::string>& args) const
{
    return std::find(args.begin(), args.end(), "--rename-variables") != args.end();
}


bool args_parser::check_opt_in(const std::list<std::string>& args) const
{
    for (const auto& arg : args)
    {
        if (arg.find("--in=") == 0)
        {
            return true;
        }
    }
    return false;
}


bool args_parser::check_opt_out(const std::list<std::string>& args) const
{
    for (const auto& arg : args)
    {
        if (arg.find("--out=") == 0)
        {
            return true;
        }
    }
    return false;
}


std::string args_parser::get_path_to_input_file(const std::list<std::string>& args) const
{
    for (const auto& arg : args)
    {
        if (arg.find("--in=") == 0)
        {
            return arg.substr(5);
        }
    }
    throw std::runtime_error("Input file option (--in) not found");
}


std::string args_parser::get_path_to_output_file(const std::list<std::string>& args) const
{
    for (const auto& arg : args)
    {
        if (arg.find("--out=") == 0)
        {
            return arg.substr(6); // Получаем путь после "--out="
        }
    }
    throw std::runtime_error("Output file option (--out) not found");
}
