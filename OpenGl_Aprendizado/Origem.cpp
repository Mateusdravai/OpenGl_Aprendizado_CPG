#include <GL/freeglut.h>

void Desenhar(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(1.0, 1.0);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(-1.0, 1.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, 1.0);
    glVertex2f(1.0, -1.0);
    glEnd();
    glFlush();
}

void Inicializar()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Desenho");

    Inicializar();
    glutDisplayFunc(Desenhar);
    glutMainLoop();

    return 0;
}