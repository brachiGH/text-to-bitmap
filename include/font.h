#ifndef FONT_H_
#define FONT_H_

#include <map>
#include <vector>

#define FONT_CHAR_HEIGHT_IN_PIXELS 8
#define FONT_CHAR_WIDTH_IN_PIXELS 5

using font_t = std::map<char, std::vector<bool>>;

#endif