#pragma once
#include "data.hpp"

std::pair<double, double> generate_coefficients(const Data &data, const double ALPHA = 0.0001, double A = 0, double B = 0);
                                              