#ifndef TOKEN_CLASSIFIER_HPP
#define TOKEN_CLASSIFIER_HPP


#include <string>
#include <regex>
#include <unordered_set>


class token_classifier
{
    private: static const std::unordered_set<std::string> key_words;
    private: static const std::unordered_set<std::string> data_types;
    private: static const std::unordered_set<std::string> operators;


    private: static const std::regex identifier_pattern;
    private: static const std::regex literal_pattern;
    private: static const std::regex comment_pattern;
    private: static const std::regex multi_line_comment_pattern;
    private: static const std::regex preprocessor_pattern;


    public: bool is_key_word(const std::string& token) const;
    public: bool is_whitespace(const std::string& token) const;
    public: bool is_literal(const std::string& token) const;
    public: bool is_new_line_symbol(const std::string& token) const;
    public: bool is_data_type(const std::string& token) const;
    public: bool is_identifier(const std::string& token) const;
    public: bool is_operator(const std::string& token) const;
    public: bool is_semicolon(const std::string& token) const;
    public: bool is_comment(const std::string& token) const;
    public: bool is_multi_line_comment(const std::string& token) const;
    public: bool is_preprocessor_directive(const std::string& token) const;
    public: bool is_openning_square_bracket(const std::string& token) const;
    public: bool is_closing_square_bracket(const std::string& token) const;
    public: bool is_openning_round_bracket(const std::string& token) const;
    public: bool is_closing_round_bracket(const std::string& token) const;
    public: bool is_openning_curly_bracket(const std::string& token) const;
    public: bool is_closing_curly_bracket(const std::string& token) const;
    public: bool is_openning_triangle_bracket(const std::string& token) const;
    public: bool is_closing_triangle_bracket(const std::string& token) const;
};


#endif // TOKEN_CLASSIFIER_HPP
