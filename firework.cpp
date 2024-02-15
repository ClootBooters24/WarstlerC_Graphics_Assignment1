//---------------------------------------
// Program: line_split.cpp
// Purpose: Generate random line sequences
//          using recursive splitting.
// Author:  John Gauch
// Date:    Februrary 2024
//---------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <cmath>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//---------------------------------------
// Init function for OpenGL
//---------------------------------------
void init()
{
   // Initialize OpenGL
   glClearColor(0.0, 0.0, 0.0, 1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   int numFireworks = rand() % 10 + 5;
   float pointsX[numFireworks] = {};
   float pointsY[numFireworks] = {};

   for(int i = 0; i < numFireworks; i++) {
      // colors[i][0] = rand() % 256;
      pointsX[i] = (-1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2)))); 
      pointsY[i] = (-1 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2))));
      glBegin(GL_POINTS);
      glColor3f((float) rand() / (RAND_MAX), (float) rand() / (RAND_MAX), (float) rand() / (RAND_MAX));
      glVertex2f(pointsX[i], pointsY[i]);
      glEnd();

      glBegin(GL_LINES);
      glColor3f((float) rand() / (RAND_MAX), (float) rand() / (RAND_MAX), (float) rand() / (RAND_MAX));
      // glVertex2f(pointsX[i], pointsY[i]);
      float size = (float) rand() / (RAND_MAX);

      for (int j = 0; j < 20; j++) {
         glVertex2f(pointsX[i], pointsY[i]);
         float angle = 2 * M_PI * j / 20;
         float dx = cos(angle) * size; // Adjust the length by multiplying with a factor (e.g., 0.5)
         float dy = sin(angle) * size; // Adjust the length by multiplying with a factor (e.g., 0.5)
         glVertex2f(pointsX[i] + dx, pointsY[i] + dy);
      }
      
      glEnd();

   }

   glFlush();
   return;
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(250, 250);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Firework");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}