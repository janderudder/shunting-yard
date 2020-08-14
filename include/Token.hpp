#pragma once
#include <string>
#include <type_traits>
#include <variant>


////////////////////////////////////////////////////////////////////////////////
struct Operator_token
{
    enum class Id { Add, Sub, Mul, Div } const id;
};




////////////////////////////////////////////////////////////////////////////////
struct Operand_token
{
    std::string value;
};




////////////////////////////////////////////////////////////////////////////////
using Token = std::variant<Operator_token, Operand_token>;




////////////////////////////////////////////////////////////////////////////////
constexpr auto to_string(Operator_token::Id id) -> std::string_view
{
    using Id = Operator_token::Id;
    switch (id) {
        case Id::Add: return "+"; case Id::Sub: return "-";
        case Id::Mul: return "*"; case Id::Div: return "/";
        default: return "§";
    };
}




////////////////////////////////////////////////////////////////////////////////
constexpr auto to_string(Token const& token) -> std::string_view
{
    using op_token_to_string_t = std::string_view(*)(Operator_token::Id);
    op_token_to_string_t op_to_str = to_string;

    constexpr auto token_to_string_visitor = [](auto&& tok) -> std::string_view
    {
        using tok_type = std::decay_t<decltype(tok)>;

        if constexpr(std::is_same_v<tok_type, Operator_token>) {
            return to_string(tok.id);
        }
        else {
            return tok.value;
        }
    };

    return std::visit(token_to_string_visitor, token);
}
