#include "basic/basic_font.h"
#include "text_renderer.h"

int main() {
  bitmap bm{"test", 60, 150};
  line_t ln{10, 10};
  std::string temp = "test";
  ln.setline(temp);

  ln.print(&bm, font::basic::kFontMap);
  bm.writeToDisk();
}