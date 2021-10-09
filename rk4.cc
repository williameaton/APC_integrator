#include "rk4.h"
#include "model.h"
#include <iostream>


// Class of type Integrator which provides numerical integration capability using 4th-order Runge-Kutta method:


Rk4::Rk4(double dt, const Model &model) : dt_(dt), model_(model), dimen_(model.dimen()){
  // Constructor pre-allocates heap space for rhs() results
  fx_ = new double[dimen_];
  x_sum_ = new double[dimen_];
  K_  = new double[dimen_](); 
}

Rk4::~Rk4(){
    delete fx_; 
    delete K_; 
}

double *Rk4::sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim){
    // Function to sum two arrays: 
    for (int i=0; i<dim; i++){
        out_array[i] = arr1[i]*mult1 + arr2[i]*mult2;
    }
    return out_array;
}




int Rk4::Step(double t, double *x){
    double x_temp_[dimen_];

    for (int i=0; i<RK_ORDER_; i++){
        
        // Calculate (t + c*dt) and (x + c*K[i-1]/2)) 
        coeff_ = temp_coeffs_[i];                         // Get c (coeff)
        t_temp_ = t + coeff_*dt_;                         // Calc. t_temp_
        sumArrays(x_temp_, x, K_, 1, coeff_, dimen_);     // x_temp = 1*x + coeff*K[i-1]
        
        model_.rhs(t_temp_, x_temp_, fx_);                // Calc fx at t_temp, x_temp

        sumArrays(K_, fx_, K_, dt_, 0, dimen_);           // Calc. K[i] = fx*dt + (0 * K )
        coeff_ = K_coeffs_[i];                            // Get K_coeff 
        sumArrays(x_sum_, x_sum_, K_, 1, coeff_, dimen_); // X_sum += coeff*K
    }

    // Finally set x equal to x_sum: 
    sumArrays(x, x_sum_, x, 1, 0, dimen_);

    return 0;
}