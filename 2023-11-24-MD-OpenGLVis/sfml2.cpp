//g++ -std=c++11 -I /opt/homebrew/include -L /opt/homebrew/lib  sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <random>

const double BOX_SIZE = 1.0f;
const double RADIUS = 0.13f;
const int RENDER_INTERVAL = 100; // Render every 5 steps

const int SCALE = 800;
const int WINDOW_LX = 1.1*SCALE;
const int WINDOW_LY = 1.1*SCALE;

class Sphere {
    public:
        double x, y; // Position
        double vx, vy; // Velocity
        double mass;
        double radius;
        int color[3];

        //Sphere() {x = 0.0; y = 0.0;vx = 0.0; vy = 0.0; mass = 1.0; radius = 0.0;};
        //Sphere(double startX, double startY, double startVX, double startVY)
        //    : x(startX), y(startY), vx(startVX), vy(startVY) {}

        void update(double dt, double box_size) {
            // Update position based on velocity
            x += vx * dt;
            y += vy * dt;

            // Bounce off the walls of the box
            if ((x + radius > box_size/2 and vx > 0) || (x - radius < -box_size/2 and vx < 0)) {
                vx = -vx;
            }
            if ((y + radius > box_size/2 and vy > 0) || (y - radius < -box_size/2 and vy < 0)) {
                vy = -vy;
            }
        }
};

void initial_setup(std::vector<Sphere> &spheres, double ref_radius, int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> color_dist(0, 255);
    std::uniform_real_distribution<double> radii_dist(0.2*ref_radius, 1.0*ref_radius);
    spheres[0].x = 0.2;
    spheres[0].y = 0.1;
    spheres[0].vx = 0.01;
    spheres[0].vy = 0.01;
    spheres[0].radius = radii_dist(gen);
    spheres[0].mass = 0.987;
    for (int ii = 0; ii < 3; ii++){
        spheres[0].color[ii] = color_dist(gen);
    }

    spheres[1].x = -0.2;
    spheres[1].y = -0.1;
    spheres[1].vx = -0.01;
    spheres[1].vy = -0.01;
    spheres[1].radius = radii_dist(gen);
    spheres[1].mass = 0.987;
    for (int ii = 0; ii < 3; ii++){
        spheres[1].color[ii] = color_dist(gen);
    }
}


int main() {
    // Visualization stuff
    sf::String title = "Bouncing Sphere";
    sf::RenderWindow window(sf::VideoMode(WINDOW_LX, WINDOW_LY), title);
    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);
    // box boundary
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(BOX_SIZE*SCALE, BOX_SIZE*SCALE));
    box.setPosition(sf::Vector2f(WINDOW_LX/2 - BOX_SIZE*SCALE/2, WINDOW_LY/2 - BOX_SIZE*SCALE/2));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(5);
    box.setFillColor(sf::Color::Transparent); // Set fill color to transparent
    int renderCounter = 0;

    // bodies
    std::vector<Sphere> spheres(2);
    initial_setup(spheres, RADIUS, 0);

    // constants
    double deltaTime = 0.01;

    // main graphics loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // dynamics: forces, integration, constrains
        for (auto &sphere : spheres) {
            sphere.update(deltaTime, BOX_SIZE);
        }

        // Render
        // Only render every RENDER_INTERVAL steps
        if (renderCounter == 0) {
            window.clear(sf::Color::Black);
            window.draw(box);

            for (const auto & sphere : spheres) {
                sf::CircleShape circle(sphere.radius*SCALE); // Scale radius for rendering
                //circle.setFillColor(sf::Color::Red);
                sf::Color color(sphere.color[0], sphere.color[1], sphere.color[2]);
                circle.setFillColor(color);
                circle.setPosition(WINDOW_LX/2 + sphere.x*SCALE - sphere.radius*SCALE, WINDOW_LY/2 + sphere.y*SCALE - sphere.radius*SCALE);
                window.draw(circle);
            }

            window.display();
        }

        // Increment render counter and reset after RENDER_INTERVAL steps
        renderCounter = (renderCounter + 1) % RENDER_INTERVAL;
    }

    return 0;
}
