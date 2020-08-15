#include "Program_options.hpp"
#include <initializer_list>
#include <string_view>



// private
////////////////////////////////////////////////////////////////////////////////
namespace
{
    bool is_one_of(
        std::string_view const                          sv,
        std::initializer_list<std::string_view> const   sv_list
    ){
        for (auto const& s : sv_list) {
            if (sv == s) {
                return true;
            }
        }
        return false;
    }
}




////////////////////////////////////////////////////////////////////////////////
Program_options::Program_options(int argc, char** argv) noexcept
    : m_options     {0}
    , m_exit_code   {0}
    , m_should_abort {false}
{
    for (int i=1; i < argc; ++i)
    {
        auto const arg = std::string{argv[i]};

        if (is_one_of(arg, {"--help", "-help", "-h", "-?"}))
        {
            m_message = R"(
Infix to postfix expression converter.
Using basic implementation of shunting yarg algorithm.

Options:

  -?, --help        this screen
  -l, --token-list  output the parsed list of tokens from infix expression.
)";
            m_should_abort = true;
            return;
        }

        else if (is_one_of(arg, {"-l", "--token-list"}))
        {
            m_options[Option::Show_token_list].flip();
        }

        else if (arg[0] == '-')
        {
            m_message = "unrecognized option: " + arg;
            m_should_abort = true;
            m_exit_code = 1;
            return;
        }

        else
        {
            m_positional_args.emplace_back(std::move(arg));
        }
    }

    if (!positional_count())
    {
        m_message = "Please provide an input string as program argument.\n";
        m_message += "Pass '--help' as argument for more information.\n";
        m_should_abort = true;
        m_exit_code = 1;
    }
}




////////////////////////////////////////////////////////////////////////////////
auto Program_options::message() const -> std::string const&
{
    return m_message;
}




bool Program_options::should_abort() const
{
    return m_should_abort;
}




int Program_options::exit_code() const
{
    return m_exit_code;
}




bool Program_options::option(Option sw) const
{
    return m_options[sw];
}




auto Program_options::positional(size_t index) const -> std::string const&
{
    return m_positional_args[index];
}




auto Program_options::positional_count() const -> size_t
{
    return m_positional_args.size();
}
