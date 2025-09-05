#ifndef ARG_CHECKER_HPP
#define ARG_CHECKER_HPP


#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>


class arg_checker
{
    private: std::string arg_to_check_;

    public: std::string get_arg_to_check_() const noexcept;
    public: void set_arg_to_check_(const std::string& new_arg_to_check) noexcept;

    public: explicit arg_checker(std::string arg_to_check);
    public: bool check(std::list<std::string> argv) const;
};


#endif // ARG_CHECKER_HPP
