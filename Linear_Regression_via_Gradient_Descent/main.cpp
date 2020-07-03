#include "data.hpp"
#include "gradient_descent.hpp"
#include <iostream>

int main() {
  std::string file_name;
  std::cout << "Enter file_name: ";
  std::cin >> file_name;
  Data data{file_name};
  auto [A, B] = generate_coefficients(data);
  std::cout << "y = " << A << " * x + " << B << std::endl;
  return 0;
}