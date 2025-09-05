#include "obfuscation/variables_obfuscator.hpp"


// Вспомогательная функция генерации случайного имени (например, длиной 8 символов)
std::string variables_obfuscator::generate_random_name()
{
    static const char alphanum[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    static std::mt19937 gen { std::random_device{}() };
    static std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    std::string result(8, ' ');
    for (auto &ch : result)
        ch = alphanum[dis(gen)];

    return result;
}


void variables_obfuscator::obfuscate(std::list<token>& tokens) const
{
    std::unordered_map<std::string, std::string> rename_map;

    for (auto it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (it->get_type() == data_type_)
        {
            auto next = std::next(it);
            if (next != tokens.end() && next->get_type() == identifier_)
            {
                auto third = std::next(next);
                if (third != tokens.end())
                {
                    auto third_type = third->get_type();
                    if (third_type == openning_curly_bracket_ ||
                        third_type == semicolon_ ||
                        (third_type == operator_ && third->get_content() == "="))
                    {
                        const std::string& old_name = next->get_content();
                        if (rename_map.find(old_name) == rename_map.end())
                        {
                            rename_map[old_name] = generate_random_name();
                        }
                    }
                }
            }
        }
    }

    // Второй проход: замена всех идентификаторов, которые есть в rename_map
    for (auto& tok : tokens)
    {
        if (tok.get_type() == identifier_)
        {
            const std::string& old_name = tok.get_content();
            auto found = rename_map.find(old_name);
            if (found != rename_map.end())
            {
                tok.set_content(found->second);
            }
        }
    }
}
