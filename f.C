#include <algorithm>
#include <array>
#include <cmath>

extern int f(float x)
{
  constexpr std::array a = {1.0, 2.0, 3.0, 4.0, 5.0};
  auto i = std::lower_bound(a.begin(), a.end(), x);
  if (std::fabs(*i - x) < std::fabs(*std::next(i) - x))
    return i - a.begin();
  else
    return std::next(i) - a.begin();
}

extern int g(float x) {
  constexpr std::array a = {1.0, 2.0, 3.0, 5.0, 4.0};
  return std::min_element(a.begin(), a.end(), [x](float a, float b) {
    return std::fabs(a - x) < std::fabs(b - x);
  }) - a.begin();
}
