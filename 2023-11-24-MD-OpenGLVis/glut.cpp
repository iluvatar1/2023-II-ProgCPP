//g++ -std=c++14 -I /opt/homebrew/include -L /opt/homebrew/lib glut.cpp -lglut -lGL -lGLU
#include <GL/glut.h>
#include <cmath>

class BouncingSphere {
    public:
        BouncingSphere(float radius, float speedX, float speedY, float speedZ)
            : radius(radius), speeds{speedX, speedY, speedZ} {
            position[0] = 0.0f;
            position[1] = 0.0f;
            position[2] = 0.0f;
        }

        void update() {
            for (int i = 0; i < 3; ++i) {
                position[i] += speeds[i];
            }

            // Bounce off the walls
            for (int i = 0; i < 2; ++i) {
                if (position[i] + radius > 1.0f || position[i] - radius < -1.0f) {
                    speeds[i] *= -1;
                }
            }
        }

        void draw() const {
            glPushMatrix();
            glTranslatef(position[0], position[1], position[2]);
            glColor3f(1.0f, 0.0f, 0.0f);
            glutSolidSphere(radius, 30, 30);
            glPopMatrix();
        }

    private:
        float radius;
        float position[3];
        float speeds[3] = {0.05f, 0.03f, 0.0f};
};

BouncingSphere sphere(0.2f, 0.05f, 0.03f, 0.0f);

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    sphere.draw();

    glutSwapBuffers();
}

void update(int value) {
    sphere.update();

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, static_cast<float>(width) / height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Bouncing Sphere");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
