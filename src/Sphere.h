#ifndef SPHEREH
#define SPHEREH

#include "Vector3.h"
#include "Ray.h"
#include "Hitable.h"

class Sphere: public Hitable {
    public:

        // Variables
        Vector3 center;
        float radius;
        Vector3 color;

        // Constructors
        Sphere() { center = Vector3(0, 0, 0); radius = 1.0; color = Vector3(1.0, 0.0, 0.0); }
        Sphere(const Vector3& ce, float r, const Vector3& co) { center = ce; radius = r; color = co; }

        // Functions
        virtual bool hit(const Ray& ray, float distMin, float distMax, HitRecord& rec) const;
        // Vector3 computeColor(const Ray& ray) const;
};

bool Sphere::hit(const Ray& ray, float distMin, float distMax, HitRecord& rec) const {
    Vector3 oc = ray.origin() - center;
    float a = dot(ray.direction(), ray.direction());
    float b = 2.0 * dot(oc, ray.direction());
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        
        float dist = (-b - sqrt(b*b-a*c)) / a;

        if (dist < distMax && dist > distMin) {
            rec.distance = dist;
            rec.point = ray.pointAtParameter(rec.distance);
            rec.normal = (rec.point - center) / radius;
            return true;
        }

        dist = (-b + sqrt(b*b-a*c)) / a;

        if (dist < distMax && dist > distMin) {
            rec.distance = dist;
            rec.point = ray.pointAtParameter(rec.distance);
            rec.normal = (rec.point - center) / radius;
            return true;
        }

    }

    return false;
}

// Vector3 Sphere::computeColor(const Ray& ray) const {
    
//     if (hit(ray)) {
//         return color;
//     }

//     Vector3 unitDirection = normalize(ray.direction());
//     float t = 0.5 * (unitDirection.y() + 1.0); // 0 < t < 1
//     return (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.0, 0.0, 1.0); // White --> Blue
// }

#endif