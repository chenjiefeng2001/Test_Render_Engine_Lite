#ifndef NUMERICAL
#define NUMERICAL
#include "headers.hpp"
/// @brief: BUBBLE_SORT
/// @param container: a vector of type T
/// @return: void
/// @note: T cannot be std::string
template <typename T> void BUBBLE_SORT(std::vector<T> &container) {
  static_assert(!std::is_same<T, std::string>::value,
                "BUBBLE_SORT: T cannot be std::string");
  for (int i = 0; i < container.size(); i++) {
    for (int j = 0; j < container.size() - i - 1; j++) {
      if (container[j] > container[j + 1])
        std::swap(container[j], container[j + 1]);
    }
  }
};
template <typename T> int CTEST_FUNC(T left, T right) { return left + right; };
///@param container: a vector of type T
///@param begin: the beginning index of the vector
///@param end: the ending index of the vector
///@return: void
template <typename T>
void QUICKSORT(std::vector<T> &container, int begin, int end) {
  static_assert(!std::is_same<T, std::string>::value,
                "QUICKSORT: T cannot be std::string");
  // T begin = container.begin();
  // T end = container.end();
  if (begin >= end)
    return;
  T pivot = container[end];
  int left = begin;
  int right = end - 1;
  while (left < right) {
    while (container[left] < pivot && left < right)
      left++;
    while (container[right] >= pivot && left < right)
      right--;
    std::swap(container[left], container[right]);
  }
  if (container[left] >= container[end])
    std::swap(container[left], container[end]);
  else
    left++;
  QUICKSORT(container, begin, left - 1);
  QUICKSORT(container, left + 1, end);
};
template <typename T>
int SWAP_ITEM(std::vector<T> &container, int left, int right) {
  std::swap(container[left], container[right]);
  return 0;
}

#endif /* NUMERICAL */