#include "parse_token.hpp"
#include <sstream>



// private
////////////////////////////////////////////////////////////////////////////////
namespace
{
    auto trim_left(std::string_view sv) noexcept -> std::string_view
    {
        static auto const is_valid = [](size_t idx) {
            return idx != std::string_view::npos;
        };
        auto const trim_idx = sv.find_first_not_of(" \r\n\t\v\b");
        return sv.substr(is_valid(trim_idx) ? trim_idx : sv.size());
    }
}




// module's API
////////////////////////////////////////////////////////////////////////////////
auto parse_token(std::string_view input) -> parsing_result_t<Token>
{
    auto const trimmed_input = trim_left(input);

    auto const [operator_token, remainder] = parse_operator(trimmed_input);

    if (operator_token) {
        return {operator_token, remainder};
    }
    else {
        return parse_operand(trimmed_input);
    }
}




auto parse_operator(std::string_view input) -> parsing_result_t<Operator_token>
{
    auto const trimmed_input = trim_left(input);

    auto const opt_operator = ([](char c) -> std::optional<Operator_token> {
        switch (c) {
            case '+': return Operator_token{Operator_token::Id::Add};
            case '-': return Operator_token{Operator_token::Id::Sub};
            case '*': return Operator_token{Operator_token::Id::Mul};
            case '/': return Operator_token{Operator_token::Id::Div};
            case '%': return Operator_token{Operator_token::Id::Mod};
            default: return std::nullopt;
        }})(trimmed_input[0]);

    std::string_view remainder = (opt_operator)
        ? trimmed_input.substr(1)
        : trimmed_input;

    return {opt_operator, remainder};
}



auto parse_operand(std::string_view input) -> parsing_result_t<Operand_token>
{
    auto const trimmed_input = trim_left(input);

    double n = 0.0;
    std::istringstream iss {trimmed_input.data()};
    iss >> n;

    if (iss.fail()) {
        return {std::nullopt, trimmed_input};
    }

    auto const rem_start = std::min(size_t(iss.tellg()), trimmed_input.size());

    return {{Operand_token{n}}, trimmed_input.substr(rem_start)};
}
