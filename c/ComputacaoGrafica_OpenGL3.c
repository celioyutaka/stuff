/*
CÉLIO YUTAKA
*/

#include <windows.h>
#include <gl/glut.h>
#include <stdio.h>

GLint tx, ty, angulo;
GLfloat ex, ey;



void inicializaLetras();
void TeclasEspeciais(int key, int x, int y);
void reshape (int w, int h);
void bff();
void transladar();
void escalar();
// Tamanho e posição inicial do quadrado
GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

// Tamanho do incremento nas direções x e y
// (número de pixels para se mover a cada
// intervalo de tempo)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;


// Função callback chamada para fazer o desenho
void Desenha(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_QUADS);
               glVertex2i(x1,y1+rsize);
               glVertex2i(x1,y1);
               // Especifica que a cor corrente é azul
               //glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(x1+rsize,y1);
               glVertex2i(x1+rsize,y1+rsize);
     glEnd();

     // Executa os comandos OpenGL
     glutSwapBuffers();
}

// Função callback chamada para fazer o desenho
void DesenhaTriangulo(void)
{
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     // Limpa a janela de visualização com a cor de fundo especificada
     glClear(GL_COLOR_BUFFER_BIT);

     // Especifica que a cor corrente é vermelha
     //         R     G     B

     // Desenha um quadrado preenchido com a cor corrente
     glBegin(GL_TRIANGLES);
               glVertex2i(x1,y1+rsize);
               glVertex2i(x1,y1);
               // Especifica que a cor corrente é azul
               //glColor3f(0.0f, 0.0f, 1.0f);
               glVertex2i(x1+rsize,y1);
               //glVertex2i(x1+rsize,y1+rsize);
     glEnd();

     // Executa os comandos OpenGL
     glutSwapBuffers();
}

// Função callback chamada pela GLUT a cada intervalo de tempo
// (a window não está sendo redimensionada ou movida)
void Timer(int value)
{
    // Muda a direção quando chega na borda esquerda ou direita
    if(x1 > windowWidth-rsize || x1 < 0){
            xstep = -xstep;
            glColor3f(0.0f, 1.0f, 0.0f);
            glutDisplayFunc(DesenhaTriangulo);
    }

    // Muda a direção quando chega na borda superior ou inferior
    if(y1 > windowHeight-rsize || y1 < 0){
          ystep = -ystep;
          glColor3f(0.0f, 0.0f, 1.0f);
          glutDisplayFunc(Desenha);
    }

    // Verifica as bordas.  Se a window for menor e o
    // quadrado sair do volume de visualização
   if(x1 > windowWidth-rsize)
         x1 = windowWidth-rsize-1;

   if(y1 > windowHeight-rsize)
         y1 = windowHeight-rsize-1;

    // Move o quadrado
    x1 += xstep;
    y1 += ystep;

    // Redesenha o quadrado com as novas coordenadas
    glutPostRedisplay();
    glutTimerFunc(33,Timer, 1);
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
     // Evita a divisao por zero
     if(h == 0) h = 1;

     // Especifica as dimensões da Viewport
     glViewport(0, 0, w, h);

     // Inicializa o sistema de coordenadas
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();

     // Estabelece a janela de seleção (left, right, bottom, top)
     if (w <= h)  {
		windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
     }
     else  {
		windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
     }

     gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

void DesenhaCursor(){

    glTranslatef(tx, ty, 0);


  glColor3f(0.0f, 0.27f, 0.72f);
  //Desenha um retangulo
  glBegin(GL_QUADS);
      glVertex2f(100.0f, 10.0f);
      glVertex2f(100.0f, 20.0f);
      glVertex2f(150.0f, 20.0f);
      glVertex2f(150.0f, 10.0f);
  glEnd();

  glFlush();
}

void inicializaTeclas(){
    tx = 0;
    ty = 0;
    ex = 0;
    ey = 0;
    angulo = 0;
}

void bff(){
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
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
        case  GLUT_KEY_F1:
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
int main(void)
{
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(800,800);
     glutInitWindowPosition(0,0);
     glutCreateWindow("Trabalho Prático 3 – CélioYutaka - BrunoSouza - CarlosHenrique");
     glColor3f(1.0f, 0.0f, 0.0f);
     glutDisplayFunc(Desenha);

     glutReshapeFunc(AlteraTamanhoJanela);
     glutTimerFunc(33, Timer, 1);
     Inicializa();
     inicializaTeclas();
     glutMainLoop();
}
