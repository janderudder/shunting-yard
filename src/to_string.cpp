#include "to_string.hpp"



////////////////////////////////////////////////////////////////////////////////
auto to_string(parsing_result_t<Token> const& parsing_result) -> std::string
{
    auto const& [token, remainder] = parsing_result;

    using namespace std::string_literals;

    if (!token) {
        return "Syntax error in \""s + remainder.data() + "\"";
    }

    return {
        ((token_type(*token) == Token_type::Operator)
            ? "operator "s
            : "operand "s
        ) + to_string(*token).data()
    };
}




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
