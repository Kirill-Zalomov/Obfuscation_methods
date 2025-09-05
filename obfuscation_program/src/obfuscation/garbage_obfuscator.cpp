#include "obfuscation/garbage_obfuscator.hpp"


const std::vector<std::string> garbage_obfuscator::garbage_strings =
{
    // Числовые литералы
    "1;", "512453;", "-421512;", "041551;", "0x10abc9;", "591905925U;"

    // Строковые литералы
    "\"g,2-g1f\";", "\"41ncx\";", "\"10m93s_\";", "\"vk1jc-\";", "\"-13-\";",

    // Символьные литералы
    "\'a\';", "\'~\';", "\'R\';", "\'X\';", "\'!\';", "\'&\';"

    // Пустые циклы
    "while (false) {}", "for (;false;) {}",

    // Строки с избыточным количеством скобок
    "((((\"b90129c1\"))));", "((((\"e,lve14\"))));", "((((\"=1b_1b1!\"))));"
};


void garbage_obfuscator::obfuscate(std::list<token>& tokens) const
{
    size_t garbage_list_size = garbage_strings.size();

    std::srand(std::time(nullptr));
    for (auto iterator = tokens.begin(); iterator != tokens.end(); ++iterator)
    {
        if(iterator->get_type() == token_type::new_line_symbol_)
        {
            size_t index_of_garbage_str = std::rand() % garbage_list_size;
            token garbage_token_to_insert
            {
                garbage_strings[index_of_garbage_str],
                token_type::unknown_
            };

            iterator = tokens.insert(
                std::next(iterator),
                garbage_token_to_insert
            );
        }
    }
}

