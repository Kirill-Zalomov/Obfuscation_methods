#ifndef ARG_CHECKER_MESS_UP_COMMENTS_HPP
#define ARG_CHECKER_MESS_UP_COMMENTS_HPP


#include "arg_checker.hpp"


#include <list>
#include <string>


class arg_checker_mess_up_comments : public arg_checker
{
    public: bool check(std::list<std::string> argv) const override;
};


#endif // ARG_CHECKER_MESS_UP_COMMENTS_HPP
