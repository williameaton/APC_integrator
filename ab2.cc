#include "model.h"
#include "ab2.h"
#include "rk4.h" // Inherits the step method from RK4 
#include <iostream>

class Rk4;


Ab2::Ab2(double dt, const Model &model)
: dt_(dt), model_(model), dimen_(model.dimen())
{
    fx_ = new double[dimen_];
    fx_old_ = new double[dimen_];
}


Ab2::~Ab2()
{
  delete [] fx_;
  delete [] fx_old_;
}


double *Ab2::sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim){
    // Function to sum two arrays: 
    for (int i=0; i<dim; i++){
        out_array[i] = arr1[i]*mult1 + arr2[i]*mult2;
    }
    return out_array;
}


int Ab2::Step(double t, double *x){ 
    // Calculate fx
    model_.rhs(t, x, fx_); 

    if (counter_==0){
        
        Rk4 rk4(dt_, model_); // instantiate some example object of RK4 
        rk4.Step(t, x);

        counter_ = 1;
    }
    else{     
    // else run AB2 mthod
        // x = x + coeff1*dt*fx - coeff2*dt*fx_prev
        sumArrays(x, x, fx_, 1, dt_*ab2_coef_[0], dimen_);
        sumArrays(x, x, fx_old_, 1, dt_*ab2_coef_[1], dimen_);
    }

    // Set fx_old = fx_current
    sumArrays(fx_old_, fx_, fx_old_, 1, 0, dimen_);
    
    return 0;
}