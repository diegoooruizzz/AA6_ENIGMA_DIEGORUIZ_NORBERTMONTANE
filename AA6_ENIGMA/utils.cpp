#include "Utils.h"
#include <cctype>

std::string cleanText(const std::string& text) {
    std::string result;

    for (char c : text) {
        if (isalpha(c))
            result += toupper(c);
    }
    return result;
}

void grupo5(std::string& text) {
    std::string grouped;

    for (int i = 0; i < text.size(); i++) {
        grouped += text[i];
        if ((i + 1) % 5 == 0)
            grouped += ' ';
    }
    text = grouped;
}
