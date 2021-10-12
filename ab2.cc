#include "model.h"
#include "ab2.h"
#include "rk4.h" // Inherits the step method from RK4 
#include <iostream>


Ab2::Ab2(double dt, const Model &model)
: dt_(dt), model_(model), dimen_(model.dimen())
// CONSTRUCTOR
{
    fx_ = new double[dimen_];
    fx_old_ = new double[dimen_];
} 


Ab2::~Ab2()
// DESTRUCTOR
{
  delete [] fx_;
  delete [] fx_old_;
}


double *Ab2::sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim){
    // FUNCTION TO SUM TWO ARRAYS: 
    for (int i=0; i<dim; i++){
        out_array[i] = arr1[i]*mult1 + arr2[i]*mult2;
    }
    return out_array;
}


int Ab2::Step(double t, double *x){ 
    // CONDUCTS 1 TIMESTEP OF NUMERICAL INTEGRATION USING AB2 METHOD 

    model_.rhs(t, x, fx_);    // Calculate fx

    if (counter_==0){
        // First timestep cant be done with AB2 - use RK4

        Rk4 rk4(dt_, model_); // instantiate some example object of RK4 
        rk4.Step(t, x);

        counter_ = 1;         // Update so uses AB2 for future timesteps
    }
    else{     
        // Run AB2 method for timesteps after first: 
        // x = x + coeff1*dt*fx - coeff2*dt*fx_old_
        sumArrays(x, x, fx_, 1, dt_*ab2_coef_[0], dimen_);
        sumArrays(x, x, fx_old_, 1, dt_*ab2_coef_[1], dimen_);
    }

    // Set fx_old = fx_current for use in next timestep 
    sumArrays(fx_old_, fx_, fx_old_, 1, 0, dimen_);
    
    return 0;
}