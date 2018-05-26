#include <gl/freeglut.h>
#include <iostream>

void init();
void display(void);
void drawObject();

//wymiary okna
int w_width = 640;
int w_height = 480;

void timer(int value)
{
	display();

	glutTimerFunc(20, timer, 0);

}

int main(int argc, char **argv)
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);
	glutInitWindowSize(w_width, w_height);
	//wybor opcji wyswietlania okna 
	//parametr GLUT_RGBA - definicja kolorów w modelu RGBA
	//parametr GLUT_DOUBLE - podwojne buforowanie
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Okno w OpenGL FreeGlut");
	init();
	//Funkcja wykonuj¹ca wywo³anie zwrotne
	glutDisplayFunc(display);
	//glPushMatrix();
	glRotatef(30.0f, 1.0f, 1.0f, 0.0f);
	//glPopMatrix();
	//Uruchomienie pêtli przetwarzania zdarzen GLUT

	glutTimerFunc(20, timer, 0);
	glutMainLoop();

	return 0;
}

//Inicjalizacja maszyny stanu OpenGL
void init()
{
	//kolor t³a - zawartoœæ bufora koloru
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
//Definicja funkcji przekazywanej do glutDisplayFunc
void display(void)
{
	//Czyszczenie bufora ramki do koloru okreslonego w funkcji maszyny stanu
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	drawObject();
	//Kopiowanie z bufora na ekran
	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//Funcja rysowania obiektu
void drawObject()
{
	float a=0.5;
	float g=1;
	float h=1.74*a/2;
	int i = 0;


	

	for (i = 0; i < 6; i++)
	{
		g = i % 2;



		glBegin(GL_POLYGON);
		glColor3f(1.0f*g, 0.0f, 0.0f);
		glVertex3f(-a / 2, h, 0.0f);
		glColor3f(0.4f*g, 0.0f, 0.0f);
		glVertex3f(-a / 2, h, -a);
		glColor3f(0.4f*g, 0.0f, 0.5f);
		glVertex3f(a / 2, h, -a);
		glColor3f(0.4f*g, 0.0f, 0.5f);
		glVertex3f(a / 2, h, 0.0f);
		glEnd();

		glRotatef(60, 0.0f, 0.0f, 1.0f);

	}

	for (i = 0; i < 6; i++)
	{
		g = i % 2;


		glBegin(GL_POLYGON);
		glColor3f(0.3f*g, 0.0f, 0.4f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.4f*g, 0.0f, 0.4f);
		glVertex3f(-a / 2, h, 0.0f);
		glColor3f(0.4f*g, 0.0f, 0.2f);
		glVertex3f(a / 2, h, 0.0f);
		glEnd();

		glRotatef(60, 0.0f, 0.0f, 1.0f);
	}

	for (i = 0; i < 6; i++)
	{
		g = i % 2;


		glBegin(GL_POLYGON);
		glColor3f(0.3f*g, 0.0f, 0.4f);
		glVertex3f(0.0f, 0.0f, -a);
		glColor3f(0.4f*g, 0.0f, 0.4f);
		glVertex3f(-a / 2, h, -a);
		glColor3f(0.4f*g, 0.0f, 0.2f);
		glVertex3f(a / 2, h, -a);
		glEnd();

		glRotatef(60, 0.0f, 0.0f, 1.0f);
	}

	//glRotatef(2, 1.0f, 1.0f, 0.0f);


	glFlush();

}
