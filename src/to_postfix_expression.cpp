#include "to_postfix_expression.hpp"
#include "Token.hpp"
#include <stack>


namespace
{
    bool has_priority_over(Operator_token const& lhs, Operator_token const& rhs)
    {
        using Id = Operator_token::Id;

        auto const is_assoc = [](Id id) { return id==Id::Add or id==Id::Sub; };

        return !is_assoc(lhs.id) && is_assoc(rhs.id);
    }
}




////////////////////////////////////////////////////////////////////////////////
auto to_postfix_expression(Infix_expression const& infix_expression)
 -> Postfix_expression
{
    std::vector<Token> output;
    std::stack<Operator_token> operators;

    auto const flush_stack = [&output, &operators]
    {
        while (!operators.empty()) {
            output.push_back(operators.top());
            operators.pop();
        }
    };

    for (auto const& token : infix_expression)
    {
        if (token_type(token) == Token_type::Operand)
        {
            output.push_back(token);
        }
        else
        {
            auto const& current_op = std::get<Operator_token>(token);

            if (!operators.empty()
                && has_priority_over(operators.top(), current_op))
            {
                flush_stack();
            }

            operators.push(current_op);
        }
    }

    flush_stack();
    return output;
}
