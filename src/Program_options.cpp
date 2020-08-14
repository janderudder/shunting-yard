#include "Program_options.hpp"



Program_options::Program_options(int argc, char** argv) noexcept
    : m_switches    {0}
    , m_should_quit {false}
    , m_exit_code   {0}
{
    if (argc < 2) {
        m_string = "Please enter an input string.\n";
        m_should_quit = true;
        m_exit_code = 1;
    }

    for (int i=1; i < argc; ++i)
    {
        auto const arg = std::string{argv[i]};

        if (arg == "--help" or arg == "-h" or arg == "-?" or arg == "-help")
        {
            m_should_quit = true;
            m_string = R"(
Infix to postfix expression converter.
Using basic implementation of shunting yarg algorithm.

Options:

  -?, --help        this screen
  -l, --token-list  output the parsed list of tokens from infix expression.
)";
            break;
        }

        else if (arg == "--token-list" or arg == "-l") {
            m_switches[Switch::Show_token_list].flip();
        }

        else if (arg[0] == '-') {
            m_string = "unrecognized option: " + arg;
            m_should_quit = true;
            m_exit_code = 1;
            break;
        }

        else {
            m_string = arg;
        }
    }
}




////////////////////////////////////////////////////////////////////////////////
auto Program_options::string() const -> std::string_view
{
    return m_string;
}




bool Program_options::should_quit() const
{
    return m_should_quit;
}




int Program_options::exit_code() const
{
    return m_exit_code;
}




bool Program_options::get_switch(Switch sw) const
{
    return m_switches[sw];
}
