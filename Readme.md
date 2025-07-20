# Text To Bitmap Library

A simple text to ascci and to bitmap image libarary:

## Demenstration

```cpp
#include "basic/basic_font.h"
#include "text_renderer.h"

int main() {
    // Initiating a bitmap with width=400px and height=900px
    bstd::shared_ptr<bitmap> bm = std::make_shared<bitmap>("test", 400, 900);

    // Creating an obj of type text are to write into starting at offset x=10px and y=10px
    text_area txt{10, 10};

    // writing into the text area
    std::string temp = "A B C D E F \nG H I J K L \nM N O P Q R \nS T U V W X \nY Z a b c d \ne f g h i j \nk l m n o p \nq r s t u v \nw x y z 0 1 \n2 3 4 5 6 7 \n8 9   ! @ # \n$ % ^ & * ( \n) - _ = + [ \n] { } \\";
    txt.text(temp, font::basic::kFontMap);

    // Printing the text on the bitmap
    txt.print(bm);

    bm->writeAsASCIIfileToDisk();
    bm->writeToDisk();
}
```
result:

<p align="center">
    <img src="all-characters.bmp" alt="Example output">
</p>


## usage

### **bitmap.h**: bitmap Class API

This class provides an interface for creating and saving bitmap images.

```cpp
// Constructor
bitmap(std::string filename, uint16_t width, uint16_t height);

// Getters
uint16_t getHeight() const;
uint16_t getWidth() const;
const std::string& getFilename() const;
const pixel& getPixel(uint16_t x, uint16_t y);

// Setters
void setHeight(const uint16_t height);
void setWidth(const uint16_t width);
void setFilename(const std::string& filename);
bool setPixel(const pixel p, const uint16_t x, const uint16_t y);

// Utility Functions
bool is_out_of_bound(const uint16_t x, const uint16_t y) const;
bool scaleUpPixel(const pixel p, uint16_t x, uint16_t y, int8_t scale);

// File Operations
bool writeAsASCIIfileToDisk(const char whitespace = ' ', const char ASCIIcharacter = '#');
bool writeToDisk();
```

### **text_renderer.h**: line_t Class API

This API provides classes for rendering single line onto a bitmap.

```cpp
// Constructors
line_t();
line_t(int x, int y);

// Getters
uint16_t offsetX() const;
uint16_t offsetY() const;
uint8_t fontSize() const;
const color_t& color() const;
const std::string& getline() const;
const font_t& font() const;
uint8_t characterSpacing() const;
virtual uint16_t getHeight() const;
virtual uint16_t getWidth() const;

// Setters
void offsetX(const uint16_t x);
void offsetY(const uint16_t y);
void fontSize(const uint8_t fs);
void color(const color_t& c);
void color(const uint8_t b, const uint8_t g, const uint8_t r);
void setline(const std::string& ln, const font_t& ft);
void setline(const std::string& ln);
void setfont(const font_t& ft);
void characterSpacing(const uint8_t cs);

// Rendering
virtual bool print(bitmap* bm) const;
```

### **text_renderer.h**: text_area Class API

The text_area class inherits from line_t and Renders multiple lines of text.

```cpp
// Constructor
text_area(const int x, const int y);

// Text Management
std::string text() const; // get text
void text(const std::string& t, const font_t& ft);
void text(const std::string& t);

// Spacing and Font
uint8_t linespacing() const;
void linespacing(const uint8_t ls);
void fontSize(const uint8_t fs); // Overrides base class behavior for all lines

// Deleted Functions (not available in text_area)
const std::string& getline() = delete;
void setline(const std::string& ln) = delete;
void setline(const std::string& ln, const font_t& ft) = delete;
```

## An example using the line_t class

```cpp
#include "basic/basic_font.h"
#include "text_renderer.h"

int main() {
    std::shared_ptr<bitmap> bm = std::make_shared<bitmap>("test", 400, 900);
    line_t txt{10, 10};
    std::string temp = "&test123456789";
    txt.setline(temp, font::basic::kFontMap);

    txt.print(bm);
    bm->writeAsASCIIfileToDisk();
    bm->writeToDisk();
}
```
result:

<p align="center">
    <img src="test.bmp" alt="Example output">
</p>

> note: no can't have a new line character '\n' with line_t type.


