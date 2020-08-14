#include "Token.hpp"
#include "parse_token.hpp"
#include "output_parsing.hpp"
#include <iostream>
#include <stack>



int main()
{
    auto const input = "12+8*2/4-5";

    auto const [op1, rem1] = parse_token(input);
    auto const [op2, rem2] = parse_token(rem1);
    auto const [op3, rem3] = parse_token(rem2);
    auto const [op4, rem4] = parse_token(rem3);
    auto const [op5, rem5] = parse_token(rem4);

    output_parsing_result({op1, rem1}, std::cout);
    output_parsing_result({op2, rem2}, std::cout);
    output_parsing_result({op3, rem3}, std::cout);
    output_parsing_result({op4, rem4}, std::cout);
}
