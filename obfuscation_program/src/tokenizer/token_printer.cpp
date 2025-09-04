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


void token_printer::print_tokens_in_file(
const std::string& filename,
const std::list<token>& tokens_to_print)
{
    std::ofstream file;
    file.open(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::string content = "";
    uint32_t tab = 0;
    for(auto token : tokens_to_print)
    {
        content = token.get_content();

        if(content != "\n") file << content << " ";
        else file << content << std::string(tab * 4, ' ');

        if(content == "{") tab++;
        else if(content == "}") tab--;
    }
}
