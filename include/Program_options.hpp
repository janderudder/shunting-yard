#pragma once
#include <bitset>
#include <string>
#include <vector>


class Program_options
{
public:
    enum Option {Show_token_list, COUNT};

private:
    std::bitset<Option::COUNT>  m_options;
    std::vector<std::string>    m_positional_args;
    std::string                 m_message;
    int                         m_exit_code;
    bool                        m_should_abort;

public:
    Program_options(int argc, char** argv) noexcept;

    bool should_abort() const;
    auto message() const -> std::string const&;
    int exit_code() const;

    bool option(Option) const;
    auto positional(size_t index) const -> std::string const&;
    auto positional_count() const -> size_t;

};
