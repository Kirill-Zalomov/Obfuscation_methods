#ifndef TOKEN_PRINTER_HPP
#define TOKEN_PRINTER_HPP


#include "token.hpp"
#include "token_type.hpp"


#include <iostream>
#include <list>
#include <string>


class token_printer
{
    public: void print_token(const token& token_to_print) const noexcept;
    public: void print_tokens(const std::list<token>& tokens_to_print) const noexcept;
};


#endif // TOKEN_PRINTER_HPP
