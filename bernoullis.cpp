#include "bernoullis.h"

double calculateVelocity(double height) {
    return sqrt(2 * gravity * height + 2 * pressure / density);
}

void drawBernoullisGraph() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= numPoints; ++i) {
        double height = static_cast<double>(i) / numPoints * pipeHeight;
        double velocity = calculateVelocity(height);
        glVertex2f(height, velocity);
    }
    glEnd();
    glFlush();
}

void bernoullisReshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, pipeHeight, 0.0, calculateVelocity(pipeHeight) * 1.2);
    glMatrixMode(GL_MODELVIEW);
}