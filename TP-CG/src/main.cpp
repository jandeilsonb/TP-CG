//#include <GL/glut.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
#include <windows.h>
#include "Cubo.h"
#include "Cilindro.h"
#include "Palheta.h"
#include "Mesa.h"
#include "Bolinha.h"

/*COMANDOS DO JOGO
 * o - move a palheta da esquerda
 * p - move a palheta da direita
 * l - lança a bolinha
 * w - move o observador para cima, sobre o eixo y, sempre olhando para o centro
 * s - move o observador para baixo no eixo y, sempre olhando para o centro
 * v - seleciona a bola completa
 * b - seleciona a bola wireframe
 *
 * Existe uma força gravitacional que sempre puxa a bola para baixo, ao lançar uma força maior a puxa para cima,
 * exite uma força que a desloca para direita e esquerda nos limites da mesa, essa força deve ser substituída
 * posteriormente por colisões com as laterais da mesa.
 *
 */

// Angulos das palhetas, coordenadas x e y da esfera, coordenada y do observador, altura do lançador.
GLfloat pal1 = 0,
        pal2 = 0,
		yesfera = 2,
		xesfera = 2.1,
		dx = 0.05,
		lc = 1.9,
		yObs = 4.0;

//booleanos para controle das palhetas, do lançador e do tipo da esfera
bool l = false, movePal1 = false, movePal2 = false, lcb = false, lancou = false, wiresphere = false;

GLint view_w, view_h, primitiva;
GLfloat win, r, g, b;

//exibe os eixos coordenados
void eixosCoordenados()
{
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 10);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 10, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glEnd();
}
// Função é chamada caso a tela tenha tido alterada, sendo distorcer a imagem
void AlteraTamanhoTela(int w, int h) {

    if (h == 0)
        h = 1;

    float proporcao =  w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0, 0, w, h);

    gluPerspective(60.0f, proporcao, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
}

//barra do lançador com altura variável
void barra(float alt){
	glBegin(GL_POLYGON);
	    glVertex3f(1, 0, 0);
	    glVertex3f(-1, 0, 0);
	    glVertex3f(-1, alt, 0);
	    glVertex3f(1, alt, 0);
    glEnd();
}

void exibe()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();
   // posicionamento inicial do observador, com possibilidade de se mover no eixo y, sempre olhando para o centro da mesa
   gluLookAt(0.0,yObs,8.0, 0.0,4.0,0.0, 0.0,1.0,0.0);

   //desenha os eixos x,y,z, para debug
   //eixosCoordenados();

   glPushMatrix();
   glScalef(1.1,1.1,1.0);

   //desenha a mesa, parte estática
   glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    Mesa mesa;
    mesa.Desenha();
   glPopMatrix();

   //desenha a bolinha, podendo ser completa ou só a armação
   glPushMatrix();
    glTranslatef(xesfera,yesfera,0.0);
    Bolinha bolinha(wiresphere);
    bolinha.Desenha();
   glPopMatrix();

   //desenha o cubo do lançador
   glPushMatrix();
       glTranslatef(2.1,lc,0.0);
       glScalef(0.2,0.1,0.5);
       Cubo cubo;
       cubo.Desenha();
   glPopMatrix();

   //desenha a barra do lançador
   glPushMatrix();
   	  glTranslatef(2.15,0.0,0.0);
      glScalef(0.04,1.0,1.0);
      barra(lc);
   glPopMatrix();

   //Palheta esquerda
   glPushMatrix();
    glScalef(0.7,0.7,1.0);
   	glRotatef(-20.0,0.0,0.0,1.0);
    glTranslatef(-1.6, 0.8, 0.0);
    glRotatef(pal1,0.0,0.0,1.0);
    Palheta paletaE;
    paletaE.Desenha();
   glPopMatrix();

   //Palheta direita
   glPushMatrix();
    glScalef(0.7,0.7,1.0);
  	glRotatef(20.0,0.0,0.0,1.0);
    glTranslatef(1.6, 0.8, 0.0);
    glRotatef(-pal2,0.0,0.0,1.0);
    glRotatef(180.0,0.0,1.0,0.0);
    Palheta paletaD;
    paletaD.Desenha();
   glPopMatrix();

    glPopMatrix();

   glFlush();
   glutSwapBuffers();

}

//controla o lançamento da esfera
void lanca(){
	yesfera = lc;
	xesfera = 2.1;
	l = true;
}

//Controla os movimentos dos objetos na mesa, a gravidade puxando a esfera sempre para baixo,
//quando for lançada, exerce uma força na esfera para cima, e existe uma força atuando sobre ela
//para a direita ou para a esquerda durante a queda. Controla também os movimentos das Palhetas.
void gravidade(){

	if(yesfera > 0.3 && lancou)
		yesfera -= 0.02;

	if (l == true)
		yesfera += 0.1;
	if(yesfera >= 7){
		l = false;
	}
	if(yesfera >= 7.0)
		xesfera = 1.8;


	if(yesfera > 0.3 && (xesfera <= 2 && xesfera >= -2) ){
	xesfera += dx;
	if (xesfera>=1.8 || xesfera<=-1.8)
		dx*=-1;
	}

	if(movePal1){
		pal1 += 5.0;
	    if(pal1 >= 50.0)
		    pal1 = 51.0;
	}

	if(lc <= 1.9)
			lc += 0.1;

	if(lcb){
		if(lc >=0.2)
		  lc -= 0.2;
	}

	if(movePal2){
		pal2 += 5.0;
		if(pal2 >= 50.0)
		    pal2 = 51;
	}
	glutPostRedisplay();
}

//controla quando solta a tecla que estava pressionada
void controlePalheta(unsigned char tecla, int x, int y){
	switch (tecla) {
		case 'o': movePal1 = false;pal1 = 0.0; break;
	    case 'p': movePal2 = false;pal2 = 0.0; break;
	    case 'l': lcb = false, lanca(); break;
	}
}

//controla o pressionar de cada tecla
void controle (unsigned char tecla, int x, int y) {
   switch (tecla) {
      case 27: exit(EXIT_SUCCESS);  // tecla ESC para sair
      case 'o': movePal1 = true; break;
      case 'p': movePal2 = true; break;
      case 'v': wiresphere = false; break;
      case 'b': wiresphere = true; break;
      case 'w': yObs += 0.1; break;
      case 's': yObs -= 0.1; break;
      case 'l': lcb = true;lancou = true; break;

   }
   glutPostRedisplay();
}

void janela(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void inicia()
{
    // estabelece parametros de iluminacao
    GLfloat mat_ambient[]={1.0, 1.0, 0.0, 1.0};
    GLfloat mat_diffuse[]={0.6, 0.6, 0.0, 1.0};
    GLfloat mat_specular[]={0.4, 0.4, 0.0, 1.0};
    GLfloat mat_shininess={50.0};
    GLfloat light_ambient[]={0.3, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]={0.6, 0.6, 0.6, 1.0};
    GLfloat light_specular[]={0.6, 0.6, 0.6, 1.0};

    GLfloat light_position[]={3.0,3.0,3.0,1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

    glEnable(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glClearColor (0.7, 0.7, 1.0, 1.0);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("PinBall");
    glutReshapeFunc(AlteraTamanhoTela);
    glutDisplayFunc(exibe);
    glutIdleFunc(gravidade);
    glutKeyboardFunc(controle);
    glutKeyboardUpFunc(controlePalheta);
    inicia();
    glutMainLoop();
}

