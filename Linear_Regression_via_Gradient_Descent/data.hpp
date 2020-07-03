#pragma once

#include <string>
#include <vector>

// Class to hold training data
class Data {
public:
  Data(const std::string &file_name);
  Data(const Data &);
  Data &operator=(const Data &);
  Data(Data &&);
  Data &operator=(Data &&);
  const std::vector<double> &get_x() const;
  const std::vector<double> &get_y() const;
  void info();

private:
  std::vector<double> x_values{};
  std::vector<double> y_values{};
};