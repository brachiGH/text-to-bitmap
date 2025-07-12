#pragma once

// Checks if a character is a valid ASCII character
inline bool is_valid_char(char c) {
    unsigned char uc = static_cast<unsigned char>(c);

    // Printable ASCII range
    if (uc >= 32 && uc <= 126)
        return true;

    return false;
}