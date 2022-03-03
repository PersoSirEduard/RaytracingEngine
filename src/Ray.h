#ifndef RAYH
#define RAYH

#include "Vector3.h"

class Ray {
    public:

        // Variables
        Vector3 A;
        Vector3 B;

        // Constructors
        Ray() {}
        Ray(const Vector3& a, const Vector3& b) { A = a; B = b; }
        
        // Functions
        Vector3 origin() const { return A; }
        Vector3 direction() const { return B; }
        Vector3 pointAtParameter(float t) const { return A + t*B; }

};

#endif
