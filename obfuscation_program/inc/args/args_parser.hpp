#ifndef ARGS_PARSER_HPP
#define ARGS_PARSER_HPP


#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>


class args_parser
{
    public: std::string get_value_of_arg(
        const std::list<std::string>& argv,
        const std::string& arg_name
    ) const;
};


#endif // ARGS_PARSER_HPP
