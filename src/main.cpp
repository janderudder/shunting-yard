#include "parse_infix_expression.hpp"
#include "parse_token.hpp"
#include "Program_options.hpp"
#include "to_postfix_expression.hpp"
#include "to_string.hpp"
#include "Token.hpp"
#include <iostream>


int main(int const argc, char** argv)
{
    // parse command line arguments
    ////////////////////////////////////////////////////////////////////////
    Program_options program_options {argc, argv};

    if (program_options.should_abort())
    {
        std::cout << program_options.message() << "\n";
        return program_options.exit_code();
    }


    auto const input = program_options.positional(0);
    std::cout << "input: " <<  input << "\n\n";



    // parse input
    ////////////////////////////////////////////////////////////////////////
    auto const [tokens, opt_error_remainder] = parse_infix_expression(input);



    // handle syntax error
    ////////////////////////////////////////////////////////////////////////
    if (opt_error_remainder) {
        std::cout << to_string(*opt_error_remainder) << "\n";
        return 0;
    }



    // token list
    ////////////////////////////////////////////////////////////////////////
    if (program_options.option(Program_options::Show_token_list))
    {
        std::cout << "tokens (" << tokens.size() << "):\n";
        for (unsigned i=0; i < tokens.size(); ++i)
        {
            std::cout << "'" << to_string(tokens[i]) << "'";
            if (i != tokens.size()-1) {
                std::cout << ", ";
            }
        }
        std::cout << "\n\n";
    }



    // postfix expression
    ////////////////////////////////////////////////////////////////////////
    auto const postfix_expression = to_postfix_expression(tokens);

    std::cout << "output:\n";
    for (auto const& token : postfix_expression) {
        std::cout << to_string(token) << " ";
    }
    std::cout << "\n";

}
