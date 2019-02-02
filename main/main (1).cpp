

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include "desenho.h"
#include "menu.h"
#include "global.h"
#include <stdio.h>
/*Display*/
const int largura = 500;
const int altura = 500;

void Display(void)
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,largura,0.0,altura);
     if(limpar==1){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glutSwapBuffers();

        limpar = 0;
     }

     glClear(GL_COLOR);
     glColor3f(r,g,b);
     glFlush();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(largura,altura);
    glutInitWindowPosition(largura/4,altura/4);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
     glutCreateWindow("Editor");

    createNewMenu();
    glutMouseFunc(mouse);
    glClearColor(255, 255, 255, 0.0);
     glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(Display);
    glutMainLoop();
    return EXIT_SUCCESS;

}
