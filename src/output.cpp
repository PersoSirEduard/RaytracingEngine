#include <iostream>
#include <cstdio>
#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include <float.h>

const int SCREEN_X = 200;
const int SCREEN_Y = 100;

Vector3 computeColor(const Ray& r, Hitable* world) {
    HitRecord rec;
    if (world->hit(r, 0.0, FLT_MAX, rec)) {

        // Draw the hit object
        return 0.5 * Vector3(rec.normal.x() + 1.0, rec.normal.y() + 1.0, rec.normal.z() + 1.0);
    } else {

        // Draw the sky
        Vector3 unitDirection = normalize(r.direction());
        float t = 0.5 * (unitDirection.y() + 1.0); // 0 < t < 1
        return (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0); // White --> Blue
    }
}

int main() {

    // Create a screen output stream
    freopen("output.ppm", "w", stdout);
    std::cout << "P3\n" << SCREEN_X << " " << SCREEN_Y << "\n255\n";

    Vector3 lowerLeftCorner(-2.0, -1.0, -1.0);
    Vector3 horizontal(4.0, 0.0, 0.0);
    Vector3 vertical(0.0, 2.0, 0.0);
    Vector3 origin(0.0, 0.0, 0.0);

    Hitable *list[2];
    list[0] = new Sphere(Vector3(0.0, 0.0, -1.0), 0.5, Vector3(0, 0, 1));
    list[1] = new Sphere(Vector3(0.0, -100.5, -1.0), 100.0, Vector3(1.0, 0.0, 0.0));
    Hitable *world = new HitableList(list, 2);

    for (int j = SCREEN_Y - 1; j >= 0; j--) {
        for (int i = 0; i < SCREEN_X; i++) {

            float u = float(i) / float(SCREEN_X);
            float v = float(j) / float(SCREEN_Y);

            Ray ray(origin, lowerLeftCorner + u*horizontal + v*vertical);
            
            Vector3 color = computeColor(ray, world);

            int ir = int(255.99 * color[0]);
            int ig = int(255.99 * color[1]);
            int ib = int(255.99 * color[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";

        }
    }

    return 0;
}