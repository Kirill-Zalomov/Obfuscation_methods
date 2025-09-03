#ifndef TOKEN_CLASSIFIER_HPP
#define TOKEN_CLASSIFIER_HPP


#include <string>


class toke_classifiers
{
    public: bool is_key_word(const std::string& token) const;
    public: bool is_literal(const std::string& token) const;
    public: bool is_data_type(const std::string& token) const;
    public: bool is_identifier(const std::string& token) const;
    public: bool is_operator(const std::string& token) const;
    public: bool is_semicolon(const std::string& token) const;
    public: bool is_comment(const std::string& token) const;
    public: bool is_multi_line_comment(const std::string& token) const;
    public: bool is_preprocessor_directive(const std::string& token) const;
    public: bool is_openning_parenthesis(const std::string& token) const;
    public: bool is_closing_parenthesis(const std::string& token) const;
    public: bool is_openning_curly_brace(const std::string& token) const;
    public: bool is_closing_curly_brace(const std::string& token) const;
};


#endif // TOKEN_CLASSIFIER_HPP
