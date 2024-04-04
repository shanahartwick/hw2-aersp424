#pragma once

#include <GL/glut.h>
#include <cmath>

const double density = 1000; // Density of the fluid (kg/m^3), e.g., water
const double gravity = 9.81; // Acceleration due to gravity (m/s^2)
const double pressure = 101325; // Atmospheric pressure (Pa) at sea level
const double pipeHeight = 10.0; // Height of the pipe (m)
const int numPoints = 100; // Number of data points

// Function to calculate velocity using Bernoulli's equation
double calculateVelocity(double height);

// Function to draw the graph
void drawBernoullisGraph();

// Function to handle window resizing
void bernoullisReshape(int w, int h);

