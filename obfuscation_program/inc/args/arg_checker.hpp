#ifndef ARG_CHECKER_HPP
#define ARG_CHECKER_HPP


#include <list>
#include <string>


class arg_checker
{
    public: virtual ~arg_checker() = default;
    public: virtual bool check(std::list<std::string> argv) const;
};


#endif // ARG_CHECKER_HPP
