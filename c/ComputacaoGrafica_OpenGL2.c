/*
CÉLIO YUTAKA

*/

#include <Windows.h>
#include <GL/glut.h>]
#include <stdio.h>


GLint tx, ty, angulo;
GLfloat ex, ey;



void nome();
void inicializa();
void TeclasEspeciais(int key, int x, int y);
void reshape (int w, int h);
void bff();
void transladar();
void escalar();

// Função callback chamada para fazer o desenho
void Desenha(){

    glTranslatef(tx, ty, 0);
    //Define a cor branca para o fundo
  glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
  //Pinta a tela com a cor de fundo
  glClear(GL_COLOR_BUFFER_BIT);

    nome();

  //Define a cor telhado
  glColor3f(0.73f, 0.15f, 0.11f);
 //Desenha um triangulo
  glBegin(GL_TRIANGLES);
     glVertex2f(125.0f, 5.0f);
     glVertex2f(150.0f, 10.0f);
     glVertex2f(100.0f,  10.0f);
  glEnd();

  //Define a cor casa
  glColor3f(0.0f, 0.27f, 0.72f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(100.0f, 10.0f);
      glVertex2f(100.0f, 20.0f);
      glVertex2f(150.0f, 20.0f);
      glVertex2f(150.0f, 10.0f);
  glEnd();

  //Define a cor chamine
  glColor3f(0.73f, 0.15f, 0.11f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(105.0f, 5.0f);
      glVertex2f(105.0f, 10.0f);
      glVertex2f(115.0f, 10.0f);
      glVertex2f(115.0f, 5.0f);
  glEnd();


  //Define a cor porta
  glColor3f(1.0f, 1.0f, 1.00f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(110.0f, 12.0f);
      glVertex2f(110.0f, 20.0f);
      glVertex2f(125.0f, 20.0f);
      glVertex2f(125.0f, 12.0f);
  glEnd();

  //Define a cor porta
  glColor3f(0.0f, 0.0f, 0.00f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(110.5f, 15.5f);
      glVertex2f(110.5f, 16.0f);
      glVertex2f(115.0f, 16.0f);
      glVertex2f(115.0f, 15.5f);
  glEnd();


  //Define a cor janela
  glColor3f(1.0f, 1.0f, 1.00f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(130.0f, 13.0f);
      glVertex2f(130.0f, 16.0f);
      glVertex2f(145.0f, 16.0f);
      glVertex2f(145.0f, 13.0f);
  glEnd();


  //Define a cor linha janela
  glColor3f(0.0f, 0.27f, 0.72f);
  //Desenha uma linha
  glBegin(GL_LINES);
     glVertex2f(137.5f, 16.0f);
     glVertex2f(137.5f, 13.0f);
  glEnd();


  //Define a cor linha janela
  glColor3f(0.0f, 0.27f, 0.72f);
  //Desenha uma linha
  glBegin(GL_LINES);
     glVertex2f(130.0f, 14.5f);
     glVertex2f(145.5f, 14.5f);
  glEnd();

  glFlush();
}

void inicializa(){
    tx = 0;
    ty = 0;
    ex = 0;
    ey = 0;
    angulo = 0;
}

void bff(){
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0, 1000, 100, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void transladar(){
    glTranslatef(1+tx, 1+ty, 1);
}

void escalar(){
    glScalef(1+ex, 1+ey, 1);
}

void rotacionar(){

    glRotatef(angulo, 0, 0, 1);

}

void TeclasEspeciais(int key, int x, int y){
    bff();
    int tipo = 0;
    //glClear(GL_COLOR_BUFFER_BIT);
    switch (key) {
        case GLUT_KEY_PAGE_UP:
            tipo = 2;
            angulo -= 5;

        break;
        case GLUT_KEY_PAGE_DOWN:
            tipo = 2;
            angulo += 5;


        break;
        case GLUT_KEY_HOME:
            tipo = 1;
            ex += 0.1f;
            ey += 0.1f;
        break;
        case GLUT_KEY_END:
            tipo = 1;
            ex -= 0.1f;
            ey -= 0.1f;
        break;

        case GLUT_KEY_UP:
            ty -= 1;
        break;
        case GLUT_KEY_DOWN:
            ty += 1;
        break;
        case GLUT_KEY_RIGHT:
            tx += 1;
        break;
        case GLUT_KEY_LEFT:
            tx -= 1;
        break;
        }

        transladar();
        escalar();
        rotacionar();

        fflush(stdin);


      glutPostRedisplay();
}

// Programa Principal
int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 500);
	glutCreateWindow("Célio - Bruno - CG");
    //Define a janela de selecao: esquerda, direita, baixo, cima
	gluOrtho2D (0, 1000, 100, 0);
    inicializa();

    //glScalef(0.5, 0.5, 1);

	glutDisplayFunc(Desenha);
	glutSpecialFunc(TeclasEspeciais);
	glutMainLoop();
}



void nome(){
    glColor3f(0.0f, 0.0f, 0.0f);

  //Desenha uma linha
  glBegin(GL_LINES);
     glVertex2f(10.0f, 3.0f);
     glVertex2f(10.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(10.0f, -3.0f);
     glVertex2f(20.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(10.0f, 0.0f);
     glVertex2f(20.0f, 0.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(10.0f, 3.0f);
     glVertex2f(20.0f, 3.0f);
  glEnd();
//
  glBegin(GL_LINES);
     glVertex2f(30.0f, -3.0f);
     glVertex2f(50.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(40.0f, 3.0f);
     glVertex2f(40.0f, -3.0f);
  glEnd();
//
  glBegin(GL_LINES);
     glVertex2f(90.0f, 3.0f);
     glVertex2f(90.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(90.0f, -3.0f);
     glVertex2f(100.0f, -2.5f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(100.0f, -2.5f);
     glVertex2f(100.0f, -0.5f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(90.0f, 0.0f);
     glVertex2f(100.0f, 0.5f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(100.0f, 0.5f);
     glVertex2f(100.0f, 2.5f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(90.0f, 0.0f);
     glVertex2f(100.0f, -0.5f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(90.0f, 3.0f);
     glVertex2f(100.0f, 2.5f);
  glEnd();
  //
  glBegin(GL_LINES);
     glVertex2f(120.0f, 3.0f);
     glVertex2f(120.0f, -3.0f);
  glEnd();
  //

  glBegin(GL_LINES);
     glVertex2f(140.0f, 3.0f);
     glVertex2f(140.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(140.0f, 3.0f);
     glVertex2f(150.0f, 3.0f);
  glEnd();

  //

  glBegin(GL_LINES);
     glVertex2f(170.0f, 3.0f);
     glVertex2f(170.0f, -3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(170.0f, 3.0f);
     glVertex2f(180.0f, 3.0f);
  glEnd();
  glBegin(GL_LINES);
     glVertex2f(180.0f, 3.0f);
     glVertex2f(180.0f, -3.0f);
  glEnd();



}
