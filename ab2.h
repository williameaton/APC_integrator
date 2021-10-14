#ifndef AB2_H_
#define AB2_H_

#include "integrator.h"

class Model; 


class Ab2: public Integrator
{
    
public:
    Ab2(double dt, const Model &model);  // constructor
    ~Ab2();                              // destructor 

    int Step(double t, double *x);       // numerical integration of one timestep

private:
    const double dt_;                    // Timestep value [s]
    const Model &model_;	             // Model being used
    const int dimen_;		             // Dimension of state variable
    double *fx_;                         // Rate of change values (dx/dt)
    double *fx_old_; 	                 // Rate of change for prev. timestep 
    int counter_ = 0;                    // Looping counter
    double ab2_coef_[2] = {1.5, -0.5} ;  // Coefficients for AB2 equation: x += 1.5*dt*fx - 0.5*dt*fx_old

    // Function that sums two generic arrays and stores sum in out_array 
    double *sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim); 

};





#endif // AB2_H_
