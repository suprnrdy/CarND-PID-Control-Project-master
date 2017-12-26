#ifndef PID_H
#define PID_H

class PID {
public:
  double prev_cte;
  double int_cte;
  /*diff_cte = cte - prev_cte
   prev_cte = cte
   int_cte += cte
   steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte*/
  
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp_, double Ki_, double Kd_);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */