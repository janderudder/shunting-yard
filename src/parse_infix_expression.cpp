#include "parse_infix_expression.hpp"


auto parse_infix_expression(std::string_view input)
 -> std::tuple<Infix_expression, std::optional<parsing_result_t<Token>>>
{
    std::vector<Token>                      tokens;
    std::optional<parsing_result_t<Token>>  opt_erroneous_result =std::nullopt;

    bool expect_operand = true;

    while (!input.empty())
    {
        auto const [op, rem] = (expect_operand)
            ? parsing_result_t<Token>(parse_operand(input))
            : parsing_result_t<Token>(parse_operator(input));

        if (op) {
            tokens.push_back(*op);
        }
        else {
            opt_erroneous_result.emplace(op, rem);
            break;
        }

        expect_operand = !expect_operand;
        input = rem;
    }

    return { std::move(tokens), opt_erroneous_result };
}
