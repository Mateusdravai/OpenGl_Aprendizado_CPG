#include <GL/freeglut.h>

//Posição do quadrado
float quadradoX = 0.0f;
float quadradoY = 0.0f;

float quadradoTamanho = 0.1f;

int windowHeight = 800;
int windowWidth = 800;

void DesenharQuadrado()
{
	glBegin(GL_QUADS);
	glVertex2d(quadradoX - quadradoTamanho, quadradoY - quadradoTamanho);
	glVertex2d(quadradoX + quadradoTamanho, quadradoY - quadradoTamanho);
	glVertex2d(quadradoX + quadradoTamanho, quadradoY + quadradoTamanho);
	glVertex2d(quadradoX - quadradoTamanho, quadradoY + quadradoTamanho);
	glEnd();
}

void Projecao(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); 
	glMatrixMode(GL_MODELVIEW);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	DesenharQuadrado();
	glutSwapBuffers();
};

void Teclado(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		quadradoX -= 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		quadradoX += 0.1f;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("Movendo o Quadrado");

	// Configurações de cor de fundo
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Registra callbacks
	glutDisplayFunc(Display);
	glutReshapeFunc(Projecao);
	glutSpecialFunc(Teclado);

	glutMainLoop();
	return 0;
}

