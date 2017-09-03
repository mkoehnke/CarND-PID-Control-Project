#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    
    // Proportional Parameters
    PID::Kp = Kp;
    p_error = 0;
    
    // Integral Parameters
    PID::Ki = Ki;
    i_error = 0;
    
    // Differential Parameters
    PID::Kd = Kd;
    d_error = 0;
    
    // Previous CTE
    prev_cte = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - prev_cte;
    p_error =  cte;
    i_error += cte;
    prev_cte = cte;
}

double PID::TotalError() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}

