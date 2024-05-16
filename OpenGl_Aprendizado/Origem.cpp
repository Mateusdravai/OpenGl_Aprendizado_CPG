#include <GL/freeglut.h>

void Desenhar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar linha azul
    glColor3f(1.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(-0.5, 0.5, 0.0); // Transladar para a posição desejada
    glScalef(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, -1.0);
    glEnd();
    glPopMatrix();

    // Desenhar quadrado azul
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0); // Transladar para a posição desejada
    glScalef(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    glPopMatrix();

    // Desenhar triângulo
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0.0); // Transladar para a posição desejada
    glScalef(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();
    glPopMatrix();

    //Desenhar Poligono qualquer
    
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-0.5, -0.5, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0); 
    glVertex2f(0.0, -0.5); 
    glVertex2f(1.0, -0.5); 
    glVertex2f(1.0, 0.0); 
    glFlush();
}

void Inicializar()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Desenho");

    Inicializar();
    glutDisplayFunc(Desenhar);
    glutMainLoop();

    return 0;
}
