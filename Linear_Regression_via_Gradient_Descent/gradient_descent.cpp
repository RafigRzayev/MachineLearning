#include "gradient_descent.hpp"
#include <cmath>

// Calculate partial derivatives of cost function which are required to update linear regression coefficients A and B.
std::pair<double, double> get_derivatives(const std::vector<double>& X_VALUES, const std::vector<double>& Y_VALUES,
                                          const double A, const double B, const double DATA_SIZE) {
  double dA{0}, dB{0}, temp{0};
  for (size_t i{0}; i < DATA_SIZE; ++i) {
    temp = A * X_VALUES[i] + B - Y_VALUES[i];
    dA += temp * X_VALUES[i];
    dB += temp;
  }
  dA /= DATA_SIZE;
  dB /= DATA_SIZE;
  return std::make_pair(dA, dB);
}

// Calculate linear regression coefficients for a given data. Modifiy learning rate parameter (ALPHA) in case of divergence. 
std::pair<double, double> generate_coefficients(const Data &data, const double ALPHA, double A, double B) {
  // Get X and Y values of dataset
  const auto &X_VALUES{data.get_x()};
  const auto &Y_VALUES{data.get_y()};
  const size_t DATA_SIZE{X_VALUES.size()};
  // Keep updating A and B coefficients until minimum error is achieved.
  const double ZERO_FOR_COMPARISON{0.00000000000001};
  std::pair<double, double> derivatives(1, 1);
  while (fabs(derivatives.first) > ZERO_FOR_COMPARISON && fabs(derivatives.second) > ZERO_FOR_COMPARISON) {
    derivatives = get_derivatives(X_VALUES, Y_VALUES, A, B, DATA_SIZE);
    A -= ALPHA * derivatives.first;
    B -= ALPHA * derivatives.second;
  }
  // Round very small coefficients to zero
  const double ZERO_FOR_ROUNDING{0.00000000001};
  if (abs(A) < ZERO_FOR_ROUNDING)
    A = 0;
  if (abs(B) < ZERO_FOR_ROUNDING)
    B = 0;

  return std::make_pair(A, B);
}