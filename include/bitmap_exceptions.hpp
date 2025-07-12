#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <string>
#include <exception>

class unvalid_character : public std::exception
{
private:
    char m_character;
    std::string m_line;
    std::string m_message;

public:
    unvalid_character(const char &character, const std::string &line)
        : m_character(character), m_line(line)
    {
        m_message = "Unvalide character: the character '" + std::string(1, m_character) +
                    "' from \"" + m_line + "\" does not exist in provided font.";
    }

    // Override the what() method from std::exception
    const char *what() const noexcept override
    {
        return m_message.c_str();
    }
};

#endif