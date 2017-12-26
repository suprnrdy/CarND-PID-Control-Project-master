#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
  prev_cte = -1;
  int_cte = 0;
}

void PID::UpdateError(double cte) {
  double diff_cte;
  if(prev_cte == -1) {
    diff_cte = 0;
  } else {
    diff_cte = cte - prev_cte;
  }
  int_cte += cte;
  prev_cte = cte;
  
  p_error = Kp * cte;
  i_error = Ki * int_cte;
  d_error = Kd * diff_cte;
}

double PID::TotalError() {
  return -p_error - d_error - i_error;
}

