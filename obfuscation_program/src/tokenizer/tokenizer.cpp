#include <list>
#include <string>
#include <sstream>
#include <cctype>
#include "tokenizer/tokenizer.hpp"
#include "tokenizer/token_classifier.hpp"


std::list<token> tokenizer::tokenize(const std::list<std::string>& lines_of_code) const
{
    std::list<token> tokens;
    token_classifier classifier;

    auto split_line_into_tokens = [&](const std::string& line) -> std::list<std::string>
    {
        std::list<std::string> parts;
        std::string current;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            std::string two_chars = (i + 1 < line.size()) ? line.substr(i, 2) : "";
            if (!two_chars.empty() && classifier.is_operator(two_chars)) {
                if (!current.empty()) {
                    parts.push_back(current);
                    current.clear();
                }
                parts.push_back(two_chars);
                i++;
            }
            else if (classifier.is_operator(std::string(1, c)) || std::isspace(c) ||
                     c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' ||
                     c == ';' || c == ',' || c == '.') {
                if (!current.empty()) {
                    parts.push_back(current);
                    current.clear();
                }
                if (!std::isspace(c)) {
                    parts.push_back(std::string(1, c));
                }
            }
            else {
                current.push_back(c);
            }
        }
        if (!current.empty()) {
            parts.push_back(current);
        }
        return parts;
    };

    for (const auto& line : lines_of_code) {
        if (!line.empty() && line[0] == '#') {
            // Добавляем всю строку как препроцессорный токен и переходим к следующей строке
            token tk(line, token_type::preprocessor_directive_);
            tokens.push_back(tk);
            continue; // переходим к следующей строке
        }

        auto line_tokens = split_line_into_tokens(line);

        for (const auto& t : line_tokens) {
            token tk(t);
            if (classifier.is_key_word(t)) {
                tk.set_type(token_type::key_word_);
            }
            else if (classifier.is_data_type(t)) {
                tk.set_type(token_type::data_type_);
            }
            else if (classifier.is_literal(t)) {
                tk.set_type(token_type::literal_);
            }
            else if (classifier.is_operator(t)) {
                tk.set_type(token_type::operator_);
            }
            else if (classifier.is_semicolon(t)) {
                tk.set_type(token_type::semicolon_);
            }
            else if (classifier.is_comment(t)) {
                tk.set_type(token_type::comment_);
            }
            else if (classifier.is_multi_line_comment(t)) {
                tk.set_type(token_type::multi_line_comment_);
            }
            else if (classifier.is_preprocessor_directive(t)) {
                tk.set_type(token_type::preprocessor_directive_);
            }
            else if (classifier.is_openning_round_bracket(t)) {
                tk.set_type(token_type::openning_round_bracket_);
            }
            else if (classifier.is_closing_round_bracket(t)) {
                tk.set_type(token_type::closing_round_bracket_);
            }
            else if (classifier.is_openning_square_bracket(t)) {
                tk.set_type(token_type::openning_square_bracket_);
            }
            else if (classifier.is_closing_square_bracket(t)) {
                tk.set_type(token_type::closing_square_bracket_);
            }
            else if (classifier.is_openning_curly_bracket(t)) {
                tk.set_type(token_type::openning_curly_bracket_);
            }
            else if (classifier.is_closing_curly_bracket(t)) {
                tk.set_type(token_type::closing_curly_bracket_);
            }
            else if (classifier.is_openning_triangle_bracket(t)) {
                tk.set_type(token_type::openning_triangle_bracket_);
            }
            else if (classifier.is_closing_triangle_bracket(t)) {
                tk.set_type(token_type::closing_triangle_bracket_);
            }
            else if (classifier.is_identifier(t)) {
                tk.set_type(token_type::identifier_);
            }
            else {
                tk.set_type(token_type::unknown_);
            }
            tokens.push_back(tk);
        }
    }
    return tokens;
}

