#ifndef HITABLEH
#define HITABLEH

#include "Vector3.h"
#include "Ray.h"

struct HitRecord {
    float distance;
    Vector3 point;
    Vector3 normal;
};

class Hitable {
    public:
        virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& rec) const = 0;
};

#endif