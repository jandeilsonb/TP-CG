/*
 * Bolinha.cpp
 *
 *  Created on: 10/05/2015
 *      Author: root
 */

#include "Bolinha.h"

Bolinha::Bolinha(bool wire) {
	// TODO Auto-generated constructor stub
	this->wire= wire;

}

Bolinha::~Bolinha() {
	// TODO Auto-generated destructor stub
}

void Bolinha::Desenha(){
	glColor3f(1.0,1.0,1.0);

    if(wire)
    	glutWireSphere(0.1, 10, 10);
    else
    	glutSolidSphere(0.1,10,10);
}
