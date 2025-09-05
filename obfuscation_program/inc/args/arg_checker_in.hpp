#ifndef ARG_CHECKER_IN_HPP
#define ARG_CHECKER_IN_HPP


#include "arg_checker.hpp"


#include <list>
#include <string>


class arg_checker_in : public arg_checker
{
    public: bool check(std::list<std::string> argv) const override;
};


#endif // ARG_CHECKER_IN_HPP
