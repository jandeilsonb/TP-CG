/*
 * Mesa.cpp
 *
 *  Created on: 07/05/2015
 *      Author: root
 */

#include "Mesa.h"

Mesa::Mesa() {
	// TODO Auto-generated constructor stub
}

void Mesa::Desenha() {
	//trilha 1
	glPushMatrix();
	glNormal3f(1.0, 0.0, 0.0);
	glColor3f(0.8, 0.8, 0.8);
	glTranslatef(0.0, 6.0, 0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glRotatef(35.0,1.0,0.0,0.0);
	glScalef(1.25, 0.1, 1.7);
	Trilha trilha;
	trilha.Desenha();
	glPopMatrix();

	//mesa em si
	glPushMatrix();
	glNormal3f(1.0, 0.0, 0.0);
	//glEnable(GL_COLOR_MATERIAL);
	glScalef(4.3, 7.5, 0.2);
	glTranslatef(0.02, 0.5, -0.8);
	Cubo cubo;
	glColor3f(0.0, 1.0, 0.0);
	cubo.Desenha();
	glPopMatrix();

	//barra lateral direita
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.1, 6.5, 0.3);
	glTranslatef(20.0, 0.5, 0.0);
	Cubo cubo1;
	cubo1.Desenha();
	glPopMatrix();

	//barra lateral direita que separa a bola
	glPushMatrix();
	glScalef(0.1, 7.5, 0.3);
	glTranslatef(23.0, 0.5, 0.0);
	Cubo cubo2;
	cubo2.Desenha();
	glPopMatrix();

	//barra lateral esquerda
	glPushMatrix();
	glScalef(0.1, 7.5, 0.3);
	glTranslatef(-20.0, 0.5, 0.0);
	Cubo cubo3;
	cubo3.Desenha();
	glPopMatrix();

	//barra superior
	glPushMatrix();
	glScalef(4.4, 0.1, 0.3);
	glTranslatef(0.037, 75.0, 0.0);
	Cubo cubo4;
	cubo4.Desenha();
	glPopMatrix();

	//barra inferior esquerda
	glPushMatrix();
	glScalef(1.5, 0.5, 0.3);
	glTranslatef(0.8, 0.5, 0.0);
	Cubo cubo5;
	cubo5.Desenha();
	glPopMatrix();

	//barra inferior direita
	glPushMatrix();
	glScalef(1.5, 0.5, 0.3);
	glTranslatef(-0.8, 0.5, 0.0);
	Cubo cubo6;
	cubo6.Desenha();
	glPopMatrix();

	//quina direita
	glPushMatrix();
	glScalef(0.5, 2.0, 1.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glTranslatef(-4.5, -3.74, 0.0);
	Palheta paleta;
	paleta.Desenha();
	glPopMatrix();

	//quina esquerda
	glPushMatrix();
	glScalef(1.3, 4.2, 1.0);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(-1.5, -1.78, 0.0);
	Palheta paleta1;
	paleta1.Desenha();
	glPopMatrix();

	//cilindro da direita
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(2.5, 30.0, 0.0);
	Cilindro cilindroD;
	cilindroD.Desenha();
	glPopMatrix();

	//cilindro da esquerda
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(-2.5, 30.0, 0.0);
	Cilindro cilindroE;
	cilindroE.Desenha();
	glPopMatrix();

	//cilindro do centro
	glPushMatrix();
	glScalef(0.2, 0.2, 0.2);
	glTranslatef(0.0, 26.0, 0.0);
	Cilindro cilindroC;
	cilindroC.Desenha();
	glPopMatrix();

	glColor3f(1.0, 1.0, 0.0);
	//cilindro da direita
	glPushMatrix();
	glScalef(0.1, 0.1, 0.25);
	glTranslatef(5.0, 60.0, 0.0);
	Cilindro cilindroDmenor;
	cilindroDmenor.Desenha();
	glPopMatrix();

	//cilindro da esquerda
	glPushMatrix();
	glScalef(0.1, 0.1, 0.3);
	glTranslatef(-5, 60.0, 0.0);
	Cilindro cilindroEmenor;
	cilindroEmenor.Desenha();
	glPopMatrix();

	//cilindro do centro
	glPushMatrix();
	glScalef(0.1, 0.1, 0.3);
	glTranslatef(0.0, 52.0, 0.0);
	Cilindro cilindroCmenor;
	cilindroCmenor.Desenha();
	glPopMatrix();

	glColor3f(1.0, 0.0, 0.0);
	//obstáculo direita
	glPushMatrix();
	glScalef(0.2, 0.3, 0.5);
	glRotatef(-3, 0.0, 0.0, 1.0);
	glTranslatef(-10.0, 14.0, 0.0);
	Poligono poligono(2.0, 0.0, 1.0, -0.3);
	poligono.Desenha();
	glPopMatrix();

	//obstáculo esquerda
	glPushMatrix();
	glScalef(0.2, 0.3, 0.5);
	glRotatef(3, 0.0, 0.0, 1.0);
	glTranslatef(10.0, 14.0, 0.0);
	Poligono poligono2(1.0, 0.0, 2.0, -0.3);
	poligono2.Desenha();
	glPopMatrix();

	//fundo da mesa esquerda
	glPushMatrix();
	glScalef(0.5, 0.24, 0.5);
	glTranslatef(-3.0, 3.6, 0.0);
	Poligono poligono3(2.5, 0.0, 0.3, 0.0);
	poligono3.Desenha();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.1, 0.5);
	glTranslatef(-2.5, 4.0, 0.0);
	Poligono poligono4(2.5, 0.0, 0.3, 0.0);
	poligono4.Desenha();
	glPopMatrix();

	//fundo da mesa direita
	glPushMatrix();
	glScalef(0.5, 0.24, 0.5);
	glTranslatef(3.0, 3.6, 0.0);
	Poligono poligono5(0.3, 0.0, 2.5, 0.0);
	poligono5.Desenha();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.3, 0.1, 0.5);
	glTranslatef(2.5, 4.0, 0.0);
	Poligono poligono6(0.3, 0.0, 2.5, 0.0);
	poligono6.Desenha();
	glPopMatrix();

	//Triangulo obstáculo direita
	glPushMatrix();
	glScalef(0.4, 0.4, 0.5);
	glTranslatef(-3.0, 7.0, 0.0);
	Triangulo triangulo;
	triangulo.Desenha();
	glPopMatrix();

	//Triangulo obstáculo esquerda
	glPushMatrix();
	glScalef(0.4, 0.4, 0.5);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(-3.0, 7.0, 0.0);
	Triangulo triangulo1;
	triangulo1.Desenha();
	glPopMatrix();
}

Mesa::~Mesa() {
	// TODO Auto-generated destructor stub
}