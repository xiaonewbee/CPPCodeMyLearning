#include <iostream>

template<typename T>
void printR (T const& arg) {
// …
}
template<typename T>
void printR (T arg) {
// …
}
int main() {
  int arr[4];
  printR(arr);
  return 0;
}