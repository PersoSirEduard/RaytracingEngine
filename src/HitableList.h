#ifndef HITABLELISTH
#define HITABLELISTH

#include "Hitable.h"

class HitableList: public Hitable {
    public:
        // Variables
        Hitable** list;
        int listSize;

        // Constructors
        HitableList() {}
        HitableList(Hitable** hitable, int n) { list = hitable; listSize = n; }

        // Functions
        virtual bool hit(const Ray& ray, float tMin, float tMax, HitRecord& rec) const;
};

bool HitableList::hit(const Ray& ray, float tMin, float tMax, HitRecord& rec) const {
    HitRecord record;
    bool hitAnything = false;

    double closestSoFar = tMax;
    for (int i = 0; i < listSize; i++) {
        if (list[i]->hit (ray, tMin, closestSoFar, record)) {
            hitAnything = true;
            closestSoFar = record.distance;
            rec = record;
        }
    }

    return hitAnything;
}

#endif