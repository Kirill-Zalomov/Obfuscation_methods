#include "obfuscation/newline_obfuscator.hpp"


void newlines_obfuscator::obfuscate(std::list<token>& tokens) const
{
    for (auto iterator = tokens.begin(); iterator != tokens.end();)
    {
        if (iterator->get_type() == token_type::new_line_symbol_)
        {
            iterator = tokens.erase(iterator);
        }
        else
        {
            ++iterator;
        }
    }
}
