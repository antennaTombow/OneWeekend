// OneWeekend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"


int main() {
    hittable_list world;

    auto R = cos(pi / 4);
    
    auto material_ground = make_shared<lambertian>(color(.8, .8, 0));
    auto material_center = make_shared<lambertian>(color(.1, .2, .5));
    auto material_left = make_shared<dielectric>(1.5);
    auto material_right = make_shared<metal>(color(.8,.6,.2), 0);

    world.add(make_shared<sphere>(point3(0, -100.5, 1), 100, material_ground));
    world.add(make_shared<sphere>(point3(0, 0, -1), .5, material_center));
    world.add(make_shared<sphere>(point3(-1, 0.0, -1.0), .5, material_left));
    world.add(make_shared<sphere>(point3(-1, 0.0, -1.0), -.4, material_left));
    world.add(make_shared<sphere>(point3(1, 0.0, -1.0), .5, material_right));

    camera cam;

    cam.aspect_ratio        = 16.0 / 9.0;
    cam.image_width         = 400;
    cam.samples_per_pixel   = 100;
    cam.max_depth           = 50;

    cam.vfov        = 20;
    cam.lookfrom    = point3(-2, 2, 1);
    cam.lookat      = point3(0, 0, -1);
    cam.vup         = vec3(0, 1, 0);

    cam.defocus_angle = 10.0;
    cam.focus_dist = 3.4;

    cam.render(world);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
