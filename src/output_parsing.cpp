#include "output_parsing.hpp"
#include <iostream>
#include <string>



////////////////////////////////////////////////////////////////////////////////
auto to_string(Operator_token::Id id) -> std::string_view
{
    using Id = Operator_token::Id;
    switch (id) {
        case Id::Add: return "+"; case Id::Sub: return "-";
        case Id::Mul: return "*"; case Id::Div: return "/";
        default: return "§";
    };
}




////////////////////////////////////////////////////////////////////////////////
auto to_string(Token const& token) -> std::string
{
    return std::visit([](auto&& tok) -> std::string
    {
        using tok_type = std::decay_t<decltype(tok)>;

        if constexpr(std::is_same_v<tok_type, Operator_token>) {
            return to_string(tok.id).data();
        }
        else {
            return std::to_string(tok.value);
        }
    }, token);
}




////////////////////////////////////////////////////////////////////////////////
void output_parsing_result(
    parsing_result_t<Token> const&  result,
    std::ostream&                   os
){
    auto const& [token, remainder] = result;

    auto const type_str = (token && token_type(*token) == Token_type::Operator)
        ? "operator" : "operand";

    if (token) {
        os  << type_str << " : " << to_string(*token) << "\n"
            << "remainder : " << remainder << "\n";
    }
    else {
        os << "Syntax error. Input: \"" << remainder << "\"\n";
    }
}
