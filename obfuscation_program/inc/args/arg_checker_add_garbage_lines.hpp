#ifndef ARG_CHECKER_ADD_GARBAGE_LINES_HPP
#define ARG_CHECKER_ADD_GARBAGE_LINES_HPP


#include "arg_checker.hpp"


#include <list>
#include <string>


class arg_checker_add_garbage_lines : public arg_checker
{
    public: bool check(std::list<std::string> argv) const override;
};


#endif // ARG_CHECKER_ADD_GARBAGE_LINES_HPP
