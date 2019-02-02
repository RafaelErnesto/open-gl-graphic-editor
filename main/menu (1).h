/*Arquivo com  as funções do Menu*/

#include "global.h"
GLfloat r,g,b;
int limpar;

void menuCor(int selected){
    switch(selected){
        case 1://marrom
            r = 0.5f;
            g = 0.35f;
            b = 0.05f;
        break;
        case 2://azul
            r = 0.0f;
            g = 0.0f;
            b = 1.0f;
        break;
        case 3://amarelo
            r = 1.0f;
            g = 1.0f;
            b = 0.0f;
        break;
        case 4://verde claro
            r = 0.5f;
            g = 1.0f;
            b = 0.5f;
        break;
        case 5://verde escuro
            r = 0.0f;
            g = 0.5f;
            b = 0.0f;
        break;
        case 6://preto
            r = 0.0f;
            g = 0.0f;
            b = 0.0f;
        break;
        case 7://roxo
            r = 0.7f;
            g = 0.39f;
            b = 0.89f;
        break;
        case 8://laranja
            r = 1.0f;
            g = 0.5f;
            b = 0.0f;
        break;
        case 9://lilás
            r = 2.0f;
            g = 0.5f;
            b = 1.0f;
        break;
        case 10://cinza
            r = 0.1f;
            g = 0.1f;
            b = 0.1f;
        break;
    }

    glutPostRedisplay();

}

void menuDesenho(int selected){
    switch(selected){
        case 1://circulo
            opcao = 1;
        break;
        case 2://triangulo
            opcao = 2;
        break;
        case 3://linha
            opcao = 3;
        break;
        case 4://retangulo
            opcao = 4;
        break;
        case 5://arco
            opcao = 5;
        break;
        case 6://ponto
            opcao = 6;
        break;

    }
    glutPostRedisplay();
}

void menuPrincipal(int x){
}
void  menuApagar(int x){
    if(x == 1){
        limpar = 1;
        glutPostRedisplay();
    }
};
int createNewMenu(){
    int submenu1, submenu2,submenu3;

    submenu1 = glutCreateMenu(menuDesenho);
    glutAddMenuEntry("Circulo", 1);
    glutAddMenuEntry("Triangulo", 2);
    glutAddMenuEntry("Linha", 3);
    glutAddMenuEntry("Retangulo", 4);
    glutAddMenuEntry("Arco", 5);
    glutAddMenuEntry("Ponto", 6);
    submenu2 = glutCreateMenu(menuCor);
    glutAddMenuEntry("Marrom", 1);
    glutAddMenuEntry("Azul", 2);
    glutAddMenuEntry("Amarelo", 3);
    glutAddMenuEntry("Verde Claro", 4);
    glutAddMenuEntry("Verde Escuro", 5);
    glutAddMenuEntry("Preto", 6);
    glutAddMenuEntry("Roxo", 7);
    glutAddMenuEntry("Laranja", 8);
    glutAddMenuEntry("Lilas", 9);
    glutAddMenuEntry("Cinza", 10);
    submenu3 = glutCreateMenu(menuApagar);
    glutAddMenuEntry("!!Apagar!!",1);
    glutCreateMenu(menuPrincipal);
    glutAddSubMenu("Cores", submenu2);
    glutAddSubMenu("Formas", submenu1);
    glutAddSubMenu("LIMPAR TELA",submenu3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
