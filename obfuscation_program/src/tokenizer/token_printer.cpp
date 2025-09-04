#include "tokenizer/token_printer.hpp"


void token_printer::print_token(const token& token_to_print) const noexcept
{
    std::string content = token_to_print.get_content();
    std::string type    = token_to_print.get_type_str();

    std::cout << "token: { c:\"" << (content == "\n" ? "\\n" : content)
              << "\" t:" << type << " }\n";

}


void token_printer::print_tokens(const std::list<token>& tokens_to_print) const noexcept
{
    for(auto token_ : tokens_to_print)
    {
        print_token(token_);
    }
}
