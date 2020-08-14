#include "Token.hpp"
#include "parse_token.hpp"
#include "output_parsing.hpp"
#include <iostream>
#include <stack>

#include <vector>


struct Parser
{
    enum Expecting {Operator, Operand} expecting {Operand};
    std::vector<Token> tokens;

    auto operator()(std::string_view sv) noexcept
    {
        auto input = sv;
        while (!input.empty())
        {
            if (expecting == Operator)
            {
                auto const [op, rem] = parse_operator(input);
                output_parsing_result({op, rem}, std::cout);
                if (op) {
                    tokens.push_back(*op);
                } else {
                    break;
                }
                input = rem;
                expecting = Operand;
            }
            else
            {
                auto const [op, rem] = parse_operand(input);
                output_parsing_result({op, rem}, std::cout);
                if (op) {
                    tokens.push_back(*op);
                } else {
                    break;
                }
                input = rem;
                expecting = Operator;
            }
        }
    }
};



int main()
{
    auto const input = "12+8*2/4-5";

    std::cout << "\ninput: " <<  input << "\n\n";
    Parser p;
    p(input);

    std::cout << "\ntokens (" << p.tokens.size() << "):\n";

    for (auto const& token : std::as_const(p.tokens)) {
        std::cout << "'" << to_string(token) << "'\n";
    }
}
