#ifndef RK4_H_
#define RK4_H_

// Declarations and includes: 
#include "integrator.h"
class Model; 


class Rk4: public Integrator
{
public:
    Rk4(double dt, const Model &model); // constructor
    ~Rk4();                             // destructor

    int Step(double t, double *x);      // function for 1 integration step 

private: 
    const double dt_; 		// timestep
    const Model &model_;    // functor to evaluate f(x,t)
    const int dimen_;		// dimension of state x
    double *fx_;	        // rates of change for x
    double *K_; 	        // K_i for RK calculations (see eqns in README.md)
    double *x_sum_;         // x summed through iteration loop 
    double t_temp_;         // holds temporary time value for calculating fx 
    int RK_ORDER_ = 4; 	    // 4th order RK equation system 


    double coeff_;                                      // variable for holding generic coefficient 
    double temp_coeffs_[4] = {0, 0.5, 0.5, 1};          // Coefficients for calculating x_temp, t_temp
    double K_coeffs_[4] = {1/6.0, 1/3.0, 1/3.0, 1/6.0}; // Coefficients of K for calc. x 
    
    // Generic function to sum 2 arrays: 
    double *sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim); 
};


#endif // RK4_H_
