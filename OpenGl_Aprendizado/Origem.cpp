#include <GL/freeglut.h>

// Variáveis globais para controle de zoom e deslocamento
float zoom = 1.0;
float zoomIncrement = 0.1;
float offsetX = 0.0;
float offsetY = 0.0;
float offsetIncrement = 0.1;

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

    // Desenhar Poligono qualquer
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-0.5, -0.5, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glVertex2f(1.0, -0.5);
    glVertex2f(1.0, 0.0);
    glEnd();
    glPopMatrix();

    glFlush();
}

void AtualizarProjecao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0 * zoom + offsetX, 1.0 * zoom + offsetX, -1.0 * zoom + offsetY, 1.0 * zoom + offsetY);
    glMatrixMode(GL_MODELVIEW);
}

void Inicializar()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    AtualizarProjecao();
}

void Teclado(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        zoom -= zoomIncrement;
        if (zoom < 0.1) zoom = 0.1; // Evita zoom muito pequeno
        AtualizarProjecao();
    }
    if (key == GLUT_KEY_DOWN)
    {
        zoom += zoomIncrement;
        AtualizarProjecao();
    }
    if (key == GLUT_KEY_LEFT)
    {
        offsetX -= offsetIncrement;
        AtualizarProjecao();
    }
    if (key == GLUT_KEY_RIGHT)
    {
        offsetX += offsetIncrement;
        AtualizarProjecao();
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Desenho");

    Inicializar();
    glutDisplayFunc(Desenhar);
    glutSpecialFunc(Teclado); // Define a função de teclado especial
    glutMainLoop();

    return 0;
}
