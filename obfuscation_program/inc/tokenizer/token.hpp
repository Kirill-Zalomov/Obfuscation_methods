#ifndef TOKEN_HPP
#define TOKEN_HPP


#include <string>
#include "token_type.hpp"


class token
{
    // Поля
    private: std::string  content_;
    private: token_type   type_;

    // Конструкторы и деструкторы
    public: explicit token () noexcept;
    public: explicit token (const std::string& content) noexcept;
    public: token (const std::string& content, token_type type) noexcept;

    // Геттеры и сеттеры
    public: std::string get_content() const noexcept;
    public: void set_content(const std::string& new_content) noexcept;
    public: token_type get_type() const noexcept;
    public: void set_type(token_type new_type) noexcept;

    // Операторы
    public: bool operator==(const token& other_token);
    public: bool operator!=(const token& other_token);
};


#endif // TOKEN_HPP
