/*Arquivo com as funçes que desenham na tela*/

#include "global.h"
#include<stdio.h>
GLint opcao;//opcao de figura para ser desenhada
float mx,my;//coordenadas do mouse
void opcaoDesenho();
float coordenadasLinha[4]={0.0};//array que quarda as coordenadas dos vertices da linha
int click = 0;//conta os clicks para desenho da linha


void mouse(int button,int state,int x,int y){//funco que captura as coordenadas do mouse e chama o desenho selecionado no menu
    my = (float)y;
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        my = (float)altura - my;
        mx = (float)x;
        opcaoDesenho();
    }
};

//##################################################triangulo######################################################

void triangulo(){
    glPushMatrix();
    glTranslatef(mx,my,0.0);
    glBegin(GL_TRIANGLES);
        glVertex3f(0.0,0.0, 0.0);
        glVertex3f(40.0, 0.0, 0.0);
        glVertex3f(20.0, 30.0, 0.0);
    glEnd();
    glPopMatrix();
    glFlush();
}
//###########################################circulo#######################################################
void circulo(){
    int i;
    float angle;
    GLfloat circle_points = 100;
    glPushMatrix();
    glTranslatef(mx,my,0.0);
    glBegin(GL_TRIANGLE_FAN);
        for (i = 0; i < circle_points; i++) {
            angle =2*M_PI*i/circle_points;
            glVertex2f(cos(angle)*20, sin(angle)*20);
        }
    glEnd();
    glPopMatrix();
    glFlush();
}
//################################ponto##############################################
void ponto(){
    glPointSize(10);
    glBegin(GL_POINTS);
      glVertex2f(mx,my);
    glEnd();
    glFlush();
}
//####################################retangulo#################################################333

void retangulo(){
    glPushMatrix();
    glTranslatef(mx,my,0.0);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-40,0.0);
        glVertex2f(40.0,0.0);
        glVertex2f(-40.0,60.0);
        glVertex2f(40,60.0);
    glEnd();
    glPopMatrix();
    glFlush();

}
//######################arco########################################
void arco(){
    int i;
    float angle;
    glPushMatrix();
    glTranslatef(mx,my,0.0);
    GLfloat circle_points = 100;
    glBegin(GL_LINE_STRIP);
        for (i = 0; i < circle_points/2; i++) {
            angle =2*M_PI*i/circle_points;
            glVertex2f(cos(angle)*20, sin(angle)*20);
        }
    glEnd();
    glPopMatrix();
    glFlush();
}
//############################linha##########################################################3
void linha(){
    float x,y;
    x = mx;
    y = my;
    click++;
    if(click==1){
    coordenadasLinha[0] = x;
    coordenadasLinha[1] = y;
    }
    if(click==2){
    coordenadasLinha[2] = mx;
    coordenadasLinha[3] = my;
    }
    if(click==2){
        glPushMatrix();
        glBegin(GL_LINE_STRIP);
        glVertex2f(coordenadasLinha[0],coordenadasLinha[1]);
        glVertex2f(coordenadasLinha[2],coordenadasLinha[3]);
        glEnd();
        glPopMatrix();
        glFlush();
        coordenadasLinha[0,1,2,3] = {0.0};
        click = 0;
    }
}

void opcaoDesenho(){

    switch(opcao){
        case 1://circulo
            circulo();
        break;
        case 2://triangulo
            triangulo();
        break;
        case 3://linha
            linha();
        break;
        case 4://retangulo
            retangulo();
        break;
        case 5://arco
            arco();
        break;
        case 6://ponto
            ponto();
        break;
    }
    glFlush();
}






