/*
 * Poligono.h
 *
 *  Created on: 11/05/2015
 *      Author: jandeilson
 */

#ifndef POLIGONO_H_
#define POLIGONO_H_
#include "Objeto.h"
#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

class Poligono: public Objeto {
private:
	float a, b, c, d;
public:
	Poligono();
	Poligono(float a, float b, float c, float d);
	virtual ~Poligono();
	void Desenha();
};



#endif /* POLIGONO_H_ */
