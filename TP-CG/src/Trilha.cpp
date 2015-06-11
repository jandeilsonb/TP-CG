/*
 * Trilha.cpp
 *
 *  Created on: 14/05/2015
 *      Author: jandeilson
 */

#include "Trilha.h"

Trilha::Trilha() {
	// TODO Auto-generated constructor stub

}

Trilha::~Trilha() {
	// TODO Auto-generated destructor stub
}
void Trilha::cone(GLfloat raio, GLfloat base, GLfloat alt) {
	static GLUquadric* quad;
	quad = gluNewQuadric();
	gluCylinder(quad, base, raio, alt, 10, 10);
}
void Trilha::circulo(GLdouble raioDoMeio, GLdouble raio) {
	static GLUquadric* quad;
	quad = gluNewQuadric();
	gluQuadricDrawStyle(quad, GLU_FILL);
	gluDisk(quad, raioDoMeio, raio, 10, 10);
}

void Trilha::curvaCentral() {
	//borda externa
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	GLdouble equation[4] = { 0, 1, 0, 0 };
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE0, equation);
	cone(1, 1, 1);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	//borda interna
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE0, equation);
	cone(0.95, 0.95, 1);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	//borda superior
	glPushMatrix();
	glTranslatef(0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glEnable(GL_CLIP_PLANE0);
	glClipPlane(GL_CLIP_PLANE0, equation);
	circulo(0.95, 1.0);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

}
void Trilha::curvaFabio1() {
	glPushMatrix();
	GLdouble equation[4] = { 1, 0, 0, 0 };
	glEnable(GL_CLIP_PLANE1);
	glClipPlane(GL_CLIP_PLANE1, equation);
	//glTranslatef(1.0, 0.0, 0.0);
	glRotatef(125.0, 0.0, 1.0, 0.0);
	curvaCentral();
	//arco();
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

void Trilha::grade() {
	glPushMatrix();
	glScaled(1.5, 1.0, 0.7);
	curvaCentral();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5, 0, 0);
	glRotated(270, 0, 1, 0);
	curvaFabio1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.38, 0, 0.35);
	glRotated(65, 0, 1, 0);
	glScaled(1.5, 1.0, 1.0);
	curvaFabio1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, 1);
	glRotated(55, 0, 1, 0);
	glScaled(2.0, 1.0, 1.0);
	curvaFabio1();
	glPopMatrix();
}
void Trilha::Desenha() {
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
	grade();
	glPopMatrix();

	glPushMatrix();
	glScaled(1.1, 1.0, 1.1);
	grade();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.9, 1.0, 0.9);
	grade();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.8, 1.0, 0.8);
	grade();
	glPopMatrix();

}

