#ifndef ARG_CHECKER_HPP
#define ARG_CHECKER_HPP


#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>


class arg_checker
{
    public: bool check(
        std::list<std::string> argv,
        const std::string& value_to_find
    ) const;
};


#endif // ARG_CHECKER_HPP
