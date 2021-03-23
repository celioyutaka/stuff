/*
CÉLIO YUTAKA 
*/

#include <Windows.h>
#include <GL/glut.h>


void nome();

// Função callback chamada para fazer o desenho
void Desenha(){
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
     glVertex2f(130.5f, 14.5f);
     glVertex2f(145.5f, 14.5f);
  glEnd();

  glFlush();
}

// Programa Principal
int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 400);
	glutCreateWindow("Primeiro Programa");
    //Define a janela de selecao: esquerda, direita, baixo, cima
	gluOrtho2D(0, 400, 20, -20);

	glutDisplayFunc(Desenha);
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
