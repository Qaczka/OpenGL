#include <gl/freeglut.h>

void init();
void display(void);
void drawObject();
//wymiary okna
int w_width = 1920;
int w_height = 1080;


void timer(int value)
{
	//Wyœwietlenie sceny
	display();

	//Kolejne wywo³anie funkcji timera
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

	glutTimerFunc(20, timer, 0);


	//Uruchomienie pêtli przetwarzania zdarzen GLUT

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
	//drawObject2();
	drawObject();


	//Kopiowanie z bufora na ekran

	glutSwapBuffers();
}

//Funcja rysowania obiektu
void drawObject()
{
	
	double a = 0.2;
	double b = 0.3;
	double h = (1.73*a) / 2;

	//glLoadIdentity();

	//glRotatef(40.0f, 0.0f, 0.0f, 1.0f);
	//glRotatef(5.0f, 0.0f, 1.0f, 0.0f);


	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//glOrtho(5.0, 0.0, 0.0, 0.0, 0.0, 0.0);


	//gluLookAt(0.5f+a, -0.5f+b, 0.0f, 0.0f, 0.0f, -100.0f, 0.0f, 1.0f, 0.0f);

	/*
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0f, 0.1f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.0f, -0.1f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.1f, 0.0f, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);


	glEnd();

	*/

	//--------------------------------------------------------------------------//

	/*
	//PRZOD
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2f, 0.2f, 0.1f);
	glVertex3f(0.2f, 0.2f, 0.1f);
	glVertex3f(0.2f, -0.2f, 0.1f);
	glVertex3f(-0.2f, -0.2f, 0.1f);
	glEnd();

	//TYL
	glColor3f(0.5f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2f, 0.2f, -0.1f);
	glVertex3f(0.2f, 0.2f, -0.1f);
	glVertex3f(0.2f, -0.2f, -0.1f);
	glVertex3f(-0.2f, -0.2f, -0.1f);
	glEnd();

	//Gora
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2f, 0.2f, 0.1f);
	glVertex3f(0.2f, 0.2f, 0.1f);
	glVertex3f(0.2f, 0.2f, -0.1f);
	glVertex3f(-0.2f, 0.2f, -0.1f);
	glEnd();

	//DOL
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, -0.2f, 0.1f);
	glVertex3f(-0.2f, -0.2f, 0.1f);
	glVertex3f(-0.2f, -0.2f, -0.1f);
	glVertex3f(0.2f, -0.2f, -0.1f);
	glEnd();

	//LEWA
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2f, 0.2f, 0.1f);
	glVertex3f(-0.2f, -0.2f, 0.1f);
	glVertex3f(-0.2f, -0.2f, -0.1f);
	glVertex3f(-0.2f, 0.2f, -0.1f);
	glEnd();

	//PRAWA
	glColor3f(0.0f, 0.0f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex3f(0.2f, 0.2f, 0.1f);
	glVertex3f(0.2f, -0.2f, 0.1f);
	glVertex3f(0.2f, -0.2f, -0.1f);
	glVertex3f(0.2f, 0.2f, -0.1f);
	glEnd();


	//==================================================================//

	glColor3f(1.0f, 0.0f, 0.0f);
	//
	//glTranslatef(-0.3f, 0.0f, 0.0f);
	//

	//glRotatef(45.0, 1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.4f, 0.0f);
	glVertex3f(0.7f, 0.0f, 0.0f);
	glEnd();

	//glRotatef(5, 0.0f, 0.0f, 0.0f);

	//TROJKAT
	glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(-0.7f, -0.5f, 0.0f);
	glVertex3f(-0.7f, -0.7f, 0.0f);
	glEnd();

	//PRZOD
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);
	glVertex3f(0.5f, -0.7f, 0.0f);
	glEnd();

	//TYL
	glColor3f(0.5f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.5f, -0.5f, -0.2f);
	glVertex3f(0.7f, -0.5f, -0.2f);
	glVertex3f(0.7f, -0.7f, -0.2f);
	glVertex3f(0.5f, -0.7f, -0.2f);
	glEnd();

	//Gora
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.5f, -0.2f);
	glVertex3f(0.5f, -0.5f, -0.2f);
	glEnd();

	//DOL
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.7f, -0.7f, 0.0f);
	glVertex3f(0.5f, -0.7f, 0.0f);
	glVertex3f(0.5f, -0.7f, -0.2f);
	glVertex3f(0.7f, -0.7f, -0.2f);
	glEnd();

	//LEWA
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.7f, 0.0f);
	glVertex3f(0.5f, -0.7f, -0.2f);
	glVertex3f(0.5f, -0.5f, -0.2f);
	glEnd();

	//PRAWA
	glColor3f(0.0f, 0.0f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex3f(0.7f, -0.5f, 0.0f);
	glVertex3f(0.7f, -0.7f, 0.0f);
	glVertex3f(0.7f, -0.7f, -0.2f);
	glVertex3f(0.7f, -0.5f, -0.2f);
	glEnd();

	*/


int i;


	for (i = 0; i < 6; i++)
	{
		
		glBegin(GL_POLYGON);
		glColor3f(0.7f, 0.0f, 0.7f);
		glVertex3f(-a / 2, h, 0.0f);
		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(a / 2, h, 0.0f);
		glColor3f(0.5f, 0.8f, 0.5f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glEnd();

		glBegin(GL_POLYGON);
		glColor3f(0.7f, 0.0f, 0.7f);
		glVertex3f(-a / 2, h, -a);
		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(a / 2, h, -a);
		glColor3f(0.5f, 0.8f, 0.5f);
		glVertex3f(0.0f, 0.0f, -a);
		glEnd();



		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex3f(-a / 2, h, -a);
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex3f(a / 2, h, -a);
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex3f(a / 2, h, 0.0f);
		glColor3f(0.5f, 0.0f, 0.0f);
		glVertex3f(-a/2, h, 0.0f);
		glEnd();

		glRotatef(60.0f, 0.0f, 0.0f, 1.0f);

	}

	glRotatef(0.6f, 1.0f, 1.0f, 0.0f);

	//glLoadIdentity();
	//glPushMatrix();

	//glRotatef(0.3f, 1.0f, 1.0f, 0.0f);
	//glPopMatrix();
	/*
	glBegin(GL_POLYGON);
	glColor3f(0.5f, 0.8f, 0.5f);
	glVertex3f(0.0f+b, 0.0f, 0.0f);
	glColor3f(0.7f, 0.0f, 0.7f);
	glVertex3f(-a / 2+b, h, 0.0f);
	glColor3f(0.5f, 0.0f, 1.0f);
	glVertex3f(a / 2+b, h, 0.0f);
	glEnd();
	*/
	glFlush();

}
