#include "data.hpp"
#include <fstream>
#include <iostream>

// User-Defined Constructor
Data::Data(const std::string &file_name) {
  std::ifstream input_file{file_name};
  if (!input_file.is_open()) {
    std::cout << "Error during opening " << file_name << std::endl;
    return;
  }
  int counter{0};
  double temp{};
  while (input_file >> temp) {
    if (counter++ % 2 == 0) {
      x_values.push_back(temp);
    } else {
      y_values.push_back(temp);
    }
  }
  input_file.close();
}

// Copy Constructor
Data::Data(const Data &rhs) : x_values{rhs.x_values}, y_values{rhs.y_values} {}

// Copy Assignment
Data &Data::operator=(const Data &rhs) {
  if (this == &rhs) {
    return *this;
  }
  x_values = rhs.x_values;
  y_values = rhs.y_values;
  return *this;
}

// Move Constructor
Data::Data(Data &&rhs) : x_values{std::move(rhs.x_values)}, y_values{std::move(rhs.y_values)} {}

// Move Assignment
Data &Data::operator=(Data &&rhs) {
  x_values = std::move(rhs.x_values);
  y_values = std::move(rhs.y_values);
  return *this;
}

const std::vector<double>& Data::get_x() const { return x_values; }

const std::vector<double>& Data::get_y() const { return y_values; }

// Print the dataset into the console
void Data::info() {
  const size_t SIZE{x_values.size()};
  std::cout << "DATA SIZE : " << SIZE << std::endl;
  std::cout << "DATA:\n";
  for (size_t i{0}; i < SIZE; ++i) {
    std::cout << "[ " << x_values[i] << ", " << y_values[i] << " ]\n";
  }
}