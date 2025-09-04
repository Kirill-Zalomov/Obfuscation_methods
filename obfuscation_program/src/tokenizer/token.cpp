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


std::string token::get_type_str() const noexcept
{
    std::string type = "";
    if(type_ == token_type::unknown_) type = "unknown";
    else if(type_ == token_type::literal_) type = "literal";
    else if(type_ == token_type::space_) type = "space";
    else if(type_ == token_type::key_word_) type = "key_word";
    else if(type_ == token_type::data_type_) type = "data_type";
    else if(type_ == token_type::identifier_) type = "identifier";
    else if(type_ == token_type::operator_) type = "operator";
    else if(type_ == token_type::semicolon_) type = "semicolon";
    else if(type_ == token_type::comment_) type = "comment";
    else if(type_ == token_type::multi_line_comment_) type = "multi_line_comment";
    else if(type_ == token_type::preprocessor_directive_) type = "preprocessor_directive";
    else if(type_ == token_type::openning_square_bracket_) type = "openning_square_bracket";
    else if(type_ == token_type::closing_square_bracket_) type = "closing_square_bracket";
    else if(type_ == token_type::openning_curly_bracket_) type = "openning_curly_bracket";
    else if(type_ == token_type::closing_curly_bracket_) type = "closing_curly_bracket";
    else if(type_ == token_type::openning_round_bracket_) type = "openning_round_bracket";
    else if(type_ == token_type::closing_round_bracket_) type = "closing_round_bracket";
    else if(type_ == token_type::openning_triangle_bracket_) type = "openning_triangle_bracket";
    else if(type_ == token_type::closing_triangle_bracket_) type = "closing_triangle_bracket";
    else if(type_ == token_type::new_line_symbol_) type = "new_line_symbol";

    return type;
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
