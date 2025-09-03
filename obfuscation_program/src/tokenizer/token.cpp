#include "tokenizer/token.hpp"


token::token () noexcept
: content_(""),
  type_(token_type::unknown_) {}


token::token ( const std::string& content ) noexcept
: content_(content),
  type_(token_type::unknown_) {}


token::token ( const std::string& content, token_type type ) noexcept
: content_(content),
  type_(type) {}


std::string token::get_content() const noexcept
{
    return content_;
}


void token::set_content ( const std::string& new_content ) noexcept
{
    content_ = new_content;
}


token_type token::get_type() const noexcept
{
    return type_;
}


void token::set_type ( token_type new_type ) noexcept
{
    type_ = new_type;
}


bool token::operator== ( const token& other_token )
{
    return content_ == other_token.content_ && type_ == other_token.type_;
}


bool token::operator!= ( const token& other_token )
{
    return content_ != other_token.content_ || type_ != other_token.type_;
}
