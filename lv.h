#ifndef LV_H_
#define LV_H_

#include "model.h"

class Lv: public Model
{   
public:
    Lv(double *params); // constructor
    ~Lv();              // destructor 

    int rhs(double t, const double *x, double *fx) const; // calculates rates of change
    
    int dimen() const{  
        // RETURNS DIMENSION OF MODEL                                    
        return dimen_;
    }; 

private: 
    double alpha_, beta_, gamma_, delta_; // parameters (see README.md)
    static const int dimen_ = 2; 
};


#endif // LV_H_