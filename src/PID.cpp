#include "PID.h"
using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
  total_error = 0.0;
  step = 0;
	;
}

void PID::UpdateError(double cte) {
	if (step != 0)
    d_error = cte - p_error;
	else if(step == 0)
		d_error = 0;
	p_error = cte;
	i_error = i_error + cte;

	total_error = total_error + cte * cte;
	step++;
}

double PID::TotalError() {
	return total_error;

}

double PID::UpdateValues() {
    return (-(Kp*p_error + Kd*d_error + Ki*i_error));
}
