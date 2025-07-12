#ifndef BASIC_FONT_H_
#define BASIC_FONT_H_

#include <vector>
#include <map>

namespace font {
namespace basic {

const int kFontWidth = 5;
const int kFontHeight = 8;

// Each character is represented by a vector of 40 booleans (5x8 grid).
// The vector starts from the bottom-left pixel, moving right, then up row by row.
// true = black pixel, false = gray/white pixel.
const std::map<char, std::vector<bool>> kFontMap = {
    {'A', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'B', {
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false
    }},
    {'C', {
        false,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        false,true,true,true,true
    }},
    {'D', {
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false
    }},
    {'E', {
        true,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,true
    }},
    {'F', {
        true,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false
    }},
    {'G', {
        false,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'H', {
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'I', {
        false,true,true,true,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,true,true,true,false
    }},
    {'J', {
        false,false,false,true,true,
        false,false,false,false,true,
        false,false,false,false,true,
        false,false,false,false,true,
        false,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'K', {
        true,false,false,false,true,
        true,false,false,true,false,
        true,false,true,false,false,
        true,true,false,false,false,
        true,false,true,false,false,
        true,false,false,true,false,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'L', {
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,true
    }},
    {'M', {
        true,false,false,false,true,
        true,true,false,true,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'N', {
        true,false,false,false,true,
        true,true,false,false,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,false,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'O', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'P', {
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false
    }},
    {'Q', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,true,false,true,
        true,false,false,true,false,
        true,false,false,false,true,
        false,true,true,true,true
    }},
    {'R', {
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false,
        true,false,true,false,false,
        true,false,false,true,false,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'S', {
        false,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        false,true,true,true,false,
        false,false,false,false,true,
        false,false,false,false,true,
        false,false,false,false,true,
        true,true,true,true,false
    }},
    {'T', {
        true,true,true,true,true,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'U', {
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'V', {
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,false,true,false,
        false,true,false,true,false,
        false,false,true,false,false
    }},
    {'W', {
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,true,false,true,true,
        true,false,false,false,true
    }},
    {'X', {
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,false,true,false,
        false,false,true,false,false,
        false,true,false,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'Y', {
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,false,true,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'Z', {
        true,true,true,true,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,true
    }},
    {'a', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,true,false,
        false,false,false,false,true,
        false,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true
    }},
    {'b', {
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false
    }},
    {'c', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,false,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'d', {
        false,false,false,false,true,
        false,false,false,false,true,
        false,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true
    }},
    {'e', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,true,false,
        true,false,false,false,true,
        true,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        false,true,true,true,true
    }},
    {'f', {
        false,false,true,true,false,
        false,true,false,false,true,
        false,true,false,false,false,
        true,true,true,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false
    }},
    {'g', {
        false,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true,
        false,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'h', {
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'i', {
        false,false,true,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'j', {
        false,false,false,true,false,
        false,false,false,false,false,
        false,false,true,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        true,false,false,true,false,
        false,true,true,false,false
    }},
    {'k', {
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,true,false,
        true,false,true,false,false,
        true,true,false,false,false,
        true,false,true,false,false,
        true,false,false,true,false,
        true,false,false,false,true
    }},
    {'l', {
        false,true,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'m', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,false,true,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,true,false,true
    }},
    {'n', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'o', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'p', {
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,true,true,true,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false
    }},
    {'q', {
        false,true,true,true,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false
    }},
    {'r', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false
    }},
    {'s', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,true,true,
        true,false,false,false,false,
        false,true,true,true,false,
        false,false,false,false,true,
        false,false,false,false,true,
        true,true,true,true,false
    }},
    {'t', {
        false,true,false,false,false,
        false,true,false,false,false,
        true,true,true,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,true,
        false,true,false,false,true,
        false,false,true,true,false
    }},
    {'u', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,true,true,
        false,true,true,false,true
    }},
    {'v', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,false,true,false,
        false,true,false,true,false,
        false,false,true,false,false
    }},
    {'w', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,true,false,true,true,
        true,false,false,false,true
    }},
    {'x', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,false,false,false,true,
        false,true,false,true,false,
        false,false,true,false,false,
        false,true,false,true,false,
        true,false,false,false,true,
        true,false,false,false,true
    }},
    {'y', {
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true,
        false,false,false,false,true,
        false,false,false,true,false,
        true,false,true,false,false,
        false,true,false,false,false
    }},
    {'z', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        true,true,true,true,true
    }},
    {'0', {
        false,true,true,true,false,
        true,false,false,true,true,
        true,false,true,false,true,
        true,true,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'1', {
        false,false,true,false,false,
        false,true,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,true,true,true,false
    }},
    {'2', {
        false,true,true,true,false,
        true,false,false,false,true,
        false,false,false,false,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        true,true,true,true,true
    }},
    {'3', {
        true,true,true,true,false,
        false,false,false,false,true,
        false,false,false,false,true,
        false,true,true,true,false,
        false,false,false,false,true,
        false,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'4', {
        true,false,false,true,false,
        true,false,false,true,false,
        true,false,false,true,false,
        true,false,false,true,false,
        true,true,true,true,true,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false
    }},
    {'5', {
        true,true,true,true,true,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        false,false,false,false,true,
        false,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'6', {
        false,true,true,true,false,
        true,false,false,false,false,
        true,false,false,false,false,
        true,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'7', {
        true,true,true,true,true,
        false,false,false,false,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false
    }},
    {'8', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,false
    }},
    {'9', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,false,false,true,
        true,false,false,false,true,
        false,true,true,true,true,
        false,false,false,false,true,
        false,false,false,false,true,
        false,true,true,true,false
    }},
    {'&', {
        false,true,true,false,false,
        true,false,false,true,false,
        true,false,false,true,false,
        false,true,true,false,false,
        true,false,false,true,false,
        true,false,false,true,false,
        true,false,true,false,true,
        false,true,false,true,false
    }},
    {'\'', {
        false,false,true,false,false,
        false,false,true,false,false,
        false,true,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'(', {
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,false,true,false,false,
        false,false,false,true,false
    }},
    {')', {
        false,true,false,false,false,
        false,false,true,false,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false
    }},
    {'*', {
        false,false,false,false,false,
        true,false,true,false,true,
        false,true,true,true,false,
        true,true,true,true,true,
        false,true,true,true,false,
        true,false,true,false,true,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'+', {
        false,false,false,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        true,true,true,true,true,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'-', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,true,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'=', {
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,true,
        false,false,false,false,false,
        true,true,true,true,true,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'.', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,true,true,false,false
    }},
    {'!', {
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,false,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'"', {
        false,true,false,true,false,
        false,true,false,true,false,
        false,true,false,true,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'#', {
        false,true,false,true,false,
        false,true,false,true,false,
        true,true,true,true,true,
        false,true,false,true,false,
        true,true,true,true,true,
        false,true,false,true,false,
        false,true,false,true,false,
        false,false,false,false,false
    }},
    {'$', {
        false,false,true,false,false,
        false,true,true,true,true,
        true,false,true,false,false,
        false,true,true,true,false,
        false,false,true,false,true,
        true,true,true,true,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'%', {
        true,true,false,false,true,
        true,true,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        false,true,false,true,true,
        false,false,false,true,true,
        false,false,false,false,false
    }},
    {'^', {
        false,false,true,false,false,
        false,true,false,true,false,
        true,false,false,false,true,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {',', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,true,true,false,false,
        false,false,true,false,false,
        false,true,false,false,false
    }},
    {':', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,true,true,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,true,true,false,false
    }},
    {';', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,true,true,false,false,
        false,false,false,false,false,
        false,true,true,false,false,
        false,false,true,false,false,
        false,true,false,false,false
    }},
    {'?', {
        false,true,true,true,false,
        true,false,false,false,true,
        false,false,false,false,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,false,false,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'@', {
        false,true,true,true,false,
        true,false,false,false,true,
        true,false,true,true,true,
        true,false,true,false,true,
        true,false,true,false,true,
        true,false,false,false,false,
        true,false,false,false,false,
        false,true,true,true,true
    }},
    {'/', {
        false,false,false,false,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        true,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'<', {
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        true,false,false,false,false,
        false,true,false,false,false,
        false,false,true,false,false,
        false,false,false,true,false,
        false,false,false,false,false
    }},
    {'>', {
        false,true,false,false,false,
        false,false,true,false,false,
        false,false,false,true,false,
        false,false,false,false,true,
        false,false,false,true,false,
        false,false,true,false,false,
        false,true,false,false,false,
        false,false,false,false,false
    }},
    {'\\', {
        true,false,false,false,false,
        false,true,false,false,false,
        false,false,true,false,false,
        false,false,false,true,false,
        false,false,false,false,true,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'|', {
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false,
        false,false,true,false,false
    }},
    {'[', {
        false,true,true,true,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,true,true,false
    }},
    {']', {
        false,true,true,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,true,true,true,false
    }},
    {'{', {
        false,false,true,true,false,
        false,true,false,false,false,
        false,true,false,false,false,
        true,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,true,false,false,false,
        false,false,true,true,false
    }},
    {'}', {
        false,true,true,false,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,true,
        false,false,false,true,false,
        false,false,false,true,false,
        false,false,false,true,false,
        false,true,true,false,false
    }},
    {'_', {
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        true,true,true,true,true
    }},
    {' ', { // Space
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false
    }},
    {'~', { // Using the 'v' like symbol for tilde
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        false,false,false,false,false,
        true,false,false,false,true,
        false,true,false,true,false,
        false,false,true,false,false
    }},
};

} // namespace basic
} // namespace font

#endif