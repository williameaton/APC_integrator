#ifndef RK4_H_
#define RK4_H_

// Declarations and includes: 
#include "integrator.h"
class Model; 

class Rk4: Integrator
{

public:
    Rk4(double dt, const Model &model);
    ~Rk4();

    int Step(double t, double *x);

private: 
    // All the useful private variables
    double *sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim); 

    const double dt_; 		// timestep
    const Model &model_;    // functor to evaluate f(x,t)
    const int dimen_;		// dimension of state x
    double *fx_;	
    double *K_; 	
    double *x_sum_;


    double coeff_; 
    int RK_ORDER_ = 4; 	
    double temp_coeffs_[4] = {0, 0.5, 0.5, 1};
    double K_coeffs_[4] = {1/6.0, 1/3.0, 1/3.0, 1/6.0};
    double t_temp_; 
    
};


#endif // RK4_H_
