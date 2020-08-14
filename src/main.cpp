#include "Token.hpp"
#include "parse_token.hpp"
#include "to_string.hpp"
#include "parse_expression.hpp"
#include <iostream>



int main()
{
    auto const input = "12+8*2/4-5";

    std::cout << "\ninput: " <<  input << "\n\n";

    auto const [tokens, erroneous_parsing_result] = parse_expression(input);

    std::cout << "\ntokens (" << tokens.size() << "):\n";

    if (erroneous_parsing_result) {
        std::cout << to_string(*erroneous_parsing_result) << "\n";
    }

    for (auto const& token : std::as_const(tokens)) {
        std::cout << "'" << to_string(token) << "'\n";
    }
}
