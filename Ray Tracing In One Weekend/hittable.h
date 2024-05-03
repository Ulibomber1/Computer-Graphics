#ifndef HITTABLE_H
#define HITTABLE_H

#include "rtweekend.h"

class hit_record 
{
public:
    point3 p; // Position of hit in world coordinates
    vec3 normal;
    double t; // Where hit occurs along ray
    bool front_face; 

    void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        // Sets the hit record normal vector. outward_normal is assumed to be unit length
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal; // Determine whether hit occurs on the indie or outside of hit geometry
    }
};

class hittable 
{
public:
    virtual ~hittable() = default;

    virtual bool hit(const ray &r, interval ray_t, hit_record &rec) const = 0;
};

#endif