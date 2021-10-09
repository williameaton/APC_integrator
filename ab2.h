#ifndef AB2_H_
#define AB2_H_

#include "integrator.h"

class Model; 


class Ab2: Integrator
{
    
public:
    Ab2(double dt, const Model &model);
    ~Ab2();

    int Step(double t, double *x);

private:
    const double dt_; 
    const Model &model_;	
    const int dimen_;		
    double *fx_;
    double *fx_old_; 	
    int counter_ = 0;   
    double *sumArrays(double *out_array, double *arr1, double *arr2, double mult1, double mult2, int dim); 
    double ab2_coef_[2] = {1.5, -0.5} ;
};





#endif // AB2_H_
