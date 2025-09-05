#ifndef ARG_CHECKER_ADD_RANDOM_WHITESPACES_HPP
#define ARG_CHECKER_ADD_RANDOM_WHITESPACES_HPP


#include "arg_checker.hpp"


#include <list>
#include <string>


class arg_checker_add_random_whitespaces : public arg_checker
{
    public: bool check(std::list<std::string> argv) const override;
};


#endif // ARG_CHECKER_ADD_RANDOM_WHITESPACES_HPP
