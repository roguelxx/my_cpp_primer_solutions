//
// Created by lxx on 2021/9/12.
//

#include <iostream>

template<std::size_t H, std::size_t W>
class Screen {
 public:
  Screen() = default;
  std::size_t get_height() { return height; }
  std::size_t get_width() { return width; }
 private:
  std::size_t height = H;
  std::size_t width = W;
};

int main() {
  Screen<1, 2> s1;
  std::cout << s1.get_height() << " , " << s1.get_width() << std::endl;
}
