#include "lv.h"

Lv::Lv(double *params):
    alpha_(params[0]), // Prey birth rate
    beta_(params[1]),  // Prey death rate
    gamma_(params[2]), // Preditor reproduction rate
    delta_(params[3])  // Preditor death rate
{}

Lv::~Lv(){}



int Lv::rhs(double t, const double *x, double *fx) const{
    // CALCULATE FX FOR LOTKA-VOLTERRA SYSTEM
    fx[0] = alpha_*x[0] - beta_*x[0]*x[1];  // dR/dt = fx[0] = alpha*R - beta*R*F 
    fx[1] = gamma_*x[0]*x[1] - delta_*x[1]; // dF/dt = fx[1] = gamma*R*F - delta*F

    return 0;
}



