/*
 * Triangulo.cpp
 *
 *  Created on: 11/05/2015
 *      Author: jandeilson
 */

#include "Triangulo.h"

Triangulo::Triangulo() {
	// TODO Auto-generated constructor stub

}

Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}

void Triangulo::Desenha(){

	glBegin(GL_POLYGON);
	 glVertex3f(-1.0, 1.0, 0.5);
	 glVertex3f(1.0, -2.3, 0.5);
	 glVertex3f(-1.0, -1.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
     glVertex3f(-1.0, 1.0, -0.5);
     glVertex3f(1.0, -2.3, -0.5);
     glVertex3f(-1.0, -1.0, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
     glVertex3f(-1.0, 1.0, 0.5);
     glVertex3f(-1.0, 1.0, -0.5);
     glVertex3f(1.0, -2.3, -0.5);
     glVertex3f(1.0, -2.3, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
     glVertex3f(-1.0, 1.0, 0.5);
     glVertex3f(-1.0, 1.0, -0.5);
     glVertex3f(-1.0, -1.0, -0.5);
     glVertex3f(-1.0, -1.0, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
     glVertex3f(-1.0, -1.0, -0.5);
     glVertex3f(-1.0, -1.0, 0.5);
     glVertex3f(1.0, -2.3, 0.5);
     glVertex3f(1.0, -2.3, -0.5);
    glEnd();

}
