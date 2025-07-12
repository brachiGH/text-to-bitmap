#include "basic/basic_font.h"
#include "text_renderer.h"

int main() {
  bitmap bm{"test", 150, 150};
  text_area txt{10, 10};
  std::string temp = "test\nABC";
  txt.text(temp, font::basic::kFontMap);

  txt.print(&bm);
  bm.writeToDisk();
}