#include "lv.h"


Lv::Lv(double *params):
    alpha_(params[0]), 
    beta_(params[1]), 
    gamma_(params[2]), 
    delta_(params[3])
{}

Lv::~Lv(){}



int Lv::rhs(double t, const double *x, double *fx) const{
    // dR/dt = fx[0] = alpha*R - beta*R*F 
    // dF/dt = fx[1] = gamma*R*F - delta*F

    fx[0] = alpha_*x[0] - beta_*x[0]*x[1]; 
    fx[1] = gamma_*x[0]*x[1] - delta_*x[1]; 


    return 0;
}



