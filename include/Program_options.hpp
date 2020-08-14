#pragma once
#include <bitset>
#include <string>


class Program_options
{
public:
    enum Switch {Show_token_list, COUNT};

private:
    std::bitset<Switch::COUNT>  m_switches;
    std::string                 m_string;
    bool                        m_should_quit;
    int                         m_exit_code;

public:
    Program_options(int argc, char** argv) noexcept;

    auto string() const -> std::string_view;
    bool should_quit() const;
    int exit_code() const;

    bool get_switch(Switch) const;

};
