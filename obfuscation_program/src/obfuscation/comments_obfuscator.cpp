#include "obfuscation/comments_obfuscator.hpp"


static const std::vector<std::string> random_words =
{
    "apple", "river", "table", "mountain", "keyboard",
    "window", "computer", "flower", "guitar", "castle",
    "bridge", "ocean", "forest", "dream", "light",
    "clock", "bird", "stone", "house", "sky",
    "v010ca", "4uv1821x!", "!*c0)3v031", "!V_!C", "_!vk1",
    "123423", "249104", "r4918oad", "mu5125sic", "t5125ree"
};


void comments_obfuscator::obfuscate(std::list<token>& tokens) const
{
    size_t garbage_list_size = random_words.size();
    bool comment_flag = false;

    std::srand(std::time(nullptr));
    for (auto iterator = tokens.begin(); iterator != tokens.end();)
    {
        if(iterator->get_content()  == "/" && (++iterator)->get_content() == "/")
        {
            comment_flag = true;
        }
        else if(iterator->get_type() == token_type::new_line_symbol_)
        {
            comment_flag = false;
        }
        else if(comment_flag)
        {
            size_t index_of_garbage_str = std::rand() % garbage_list_size;
            token garbage_token_to_replace
            {
                random_words[index_of_garbage_str],
                token_type::unknown_
            };
            *iterator = garbage_token_to_replace;
        }
    }
}
