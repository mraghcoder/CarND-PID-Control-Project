#include "PID.h"

//using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  prev_error = 0.0;
  prev_filt = 0.0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error; // Diff Errors
  i_error += cte; // Integral Error
  p_error = cte; // Proportional Error

}

double PID::TotalError() {

  double tot_err = -Kp*p_error - Kd*d_error - Ki*i_error;

  // Exponential Moving average filter to filter the error/steer value
  static const double alpha = 0.05;
  double filt_err = (1.0-alpha)*tot_err + alpha*prev_error;
  prev_error = filt_err;
  return filt_err;
}

double PID::filter(double input){
  static const double alpha = 0.05;
  double filt_out = (1.0-alpha)*input + alpha*prev_filt;
  prev_filt = filt_out;
  return filt_out;
}
