#ifndef ARG_CHECKER_RENAME_VARIABLES_HPP
#define ARG_CHECKER_RENAME_VARIABLES_HPP


#include "arg_checker.hpp"


#include <list>
#include <string>


class arg_checker_rename_variables : public arg_checker
{
    public: bool check(std::list<std::string> argv) const override;
};


#endif // ARG_CHECKER_RENAME_VARIABLES_HPP

