#include "tokenizer/token_printer.hpp"


void token_printer::print_token(const token& token_to_print) const noexcept
{
    std::cout << "token: { c:\"" << token_to_print.get_content()
              << "\" t:" << token_to_print.get_type_str() << " }\n";

}


void token_printer::print_tokens(const std::list<token>& tokens_to_print) const noexcept
{
    for(auto token_ : tokens_to_print)
    {
        print_token(token_);
    }
}
