#include "obfuscation/whitespaces_obfuscator.hpp"


void whitespaces_obfuscator::obfuscate(std::list<token>& tokens) const
{
    std::srand(std::time(nullptr));
    for (auto iterator = tokens.begin(); iterator != tokens.end(); ++iterator)
    {
        if(std::rand() % 8 > 5)
        {
            token garbage_token_to_insert
            {
                std::string(std::rand() % 8, ' '),
                token_type::space_
            };

            iterator = tokens.insert(
                std::next(iterator),
                garbage_token_to_insert
            );
        }
    }
}
