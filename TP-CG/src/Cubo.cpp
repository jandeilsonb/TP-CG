/*
 * Cubo.cpp
 *
 *  Created on: 07/05/2015
 *      Author: root
 */

#include "Cubo.h"

Cubo::Cubo() {
	// TODO Auto-generated constructor stub
}

Cubo::~Cubo() {
	// TODO Auto-generated destructor stub
}
void Cubo::polygon(int a, int b, int c, int d) {
	glNormal3f(1.0, 0.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glBegin(GL_POLYGON);
		glVertex3fv(vertices[a]);
		glVertex3fv(vertices[b]);
		glVertex3fv(vertices[c]);
		glVertex3fv(vertices[d]);
	glEnd();
}
void Cubo::Desenha() {
	glScalef(0.5, 0.5, 0.5);
	glNormal3f(0.0, 0.0, -1.0);
	glEnable(GL_COLOR_MATERIAL);
	polygon(0, 3, 2, 1);

	glNormal3f(0.0, 1.0, 0.0);
	polygon(2, 3, 7, 6);

	glNormal3f(-1.0, 0.0, 0.0);
	polygon(0, 4, 7, 3);

	glNormal3f(1.0, 0.0, 0.0);
	polygon(1, 2, 6, 5);

	glNormal3f(0.0, 0.0, 1.0);
	polygon(4, 5, 6, 7);

	glNormal3f(0.0, -1.0, 0.0);
	polygon(0, 1, 5, 4);
}

