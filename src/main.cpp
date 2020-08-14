#include "Token.hpp"
#include <iostream>
#include <stack>



int main()
{
    Token tok_op_add {Operator_token{Operator_token::Id::Add}};
    Token tok_op_div {Operator_token{Operator_token::Id::Div}};
    Token tok_val_01 {Operand_token{"12.8"}};
    Token tok_val_02 {Operand_token{"0x2bc"}};

    std::cout << to_string(tok_op_add) << "\n";
    std::cout << to_string(tok_op_div) << "\n";
    std::cout << to_string(tok_val_01) << "\n";
    std::cout << to_string(tok_val_02) << "\n";
}
