/*
 * Cilindro.cpp
 *
 *  Created on: 08/05/2015
 *      Author: root
 */

#include "Cilindro.h"

Cilindro::Cilindro() {
	// TODO Auto-generated constructor stub
	raio = 1.0;
	alt = 1.0;


}
Cilindro::Cilindro(float raio,float alt){
	this->raio = raio;
	this->alt = alt;
}

Cilindro::~Cilindro() {
	// TODO Auto-generated destructor stub
}
void Cilindro::Desenha(){
	static GLUquadric* quad = gluNewQuadric();
	  gluCylinder(quad, raio, raio, alt, 20, 10);
	  // tampas para o cilindro
	  glNormal3f(1.0,0.0,0.0);
		glEnable(GL_COLOR_MATERIAL);
	  glPushMatrix();
	    glRotatef(180,0.0,1.0,0.0);
	    Tampa(raio);
	  glPopMatrix();
	  glPushMatrix();
	    glTranslatef(0.0,0.0,1.0);
	    Tampa(raio);
	  glPopMatrix();
}
void Cilindro::Tampa(float raio){
	glNormal3f(1.0,0.0,0.0);
	glEnable(GL_COLOR_MATERIAL);
  glBegin(GL_POLYGON);
      for(int i = 0; i < 100; i++) {
         float ang = i*2*PI/100;
         glVertex2f(cos(ang) * raio, sin(ang) * raio);
      }
  glEnd();
}
