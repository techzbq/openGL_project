#include <gl\glut.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.1415926
#define QUAD_STRIP 1
#define TRI_STRIP 2
#define TRIS 3
#define QUAD 4

double sum = 0;
int select;
int click_x,click_y;

void disp_func(void)

{
	double c = M_PI/180.0;
	double theta;
	int phi;
	double x,y,z;
	glClear(GL_COLOR_BUFFER_BIT);
	for(phi = -80;phi < 80; phi+=20)
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		if(select == QUAD_STRIP)
			glBegin(GL_QUAD_STRIP);
		else if(select == TRI_STRIP)
			glBegin(GL_TRIANGLE_STRIP);
		for(theta = -180.0; theta <= 180.0; theta+=20.0)
		{
			x = sin(c*theta)*cos(c*phi);
			y = cos(c*theta)*cos(c*phi);
			z = sin(c*phi);
			//printf("%lf,%lf,%lf\n",x,y,z);
			glVertex3d(x,y,z);
			x = sin(c*theta)*cos(c*(phi+20.0));
			y = cos(c*theta)*cos(c*(phi+20.0));
			z = sin(c*(phi+20.0));
			glVertex3d(x,y,z);
		}
		glEnd();
	}

	x = y = 0;
	z = 1;
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	c=M_PI/180.0; 
	z=sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd(); 

	x=y=0; 
	z=-1; 
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	z=-sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd(); 

	glFlush();

}
void dis_tri_strip(void)
{
	double c = M_PI/180.0;
	double theta;
	int phi;
	double x,y,z;
	glClear(GL_COLOR_BUFFER_BIT);
	for(phi = -80;phi < 80; phi+=20)
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_TRIANGLES);
		for(theta = -180.0; theta <= 180.0; theta+=20.0)
		{
			x = sin(c*theta)*cos(c*phi);
			y = cos(c*theta)*cos(c*phi);
			z = sin(c*phi);
			glVertex3d(x,y,z);
			x = sin(c*theta)*cos(c*(phi+20.0));
			y = cos(c*theta)*cos(c*(phi+20.0));
			z = sin(c*(phi+20.0));
			glVertex3d(x,y,z);
			x = sin(c*(theta+20))*cos(c*phi);
			y = cos(c*(theta+20))*cos(c*phi);
			z = sin(c*phi);
			glVertex3d(x,y,z);
		}
		glEnd();
	}

	x = y = 0;
	z = 1;
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	c=M_PI/180.0; 
	z=sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd();

	x=y=0; 
	z=-1; 
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	z=-sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd(); 

	glFlush();
}

void disp_quad(void)
{
	double c = M_PI/180.0;
	double theta;
	int phi;
	double x,y,z;
	glClear(GL_COLOR_BUFFER_BIT);
	for(phi = -80;phi < 80; phi+=20)
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glBegin(GL_QUADS);
		for(theta = -180.0; theta <= 180.0; theta+=20.0)
		{
			x = sin(c*theta)*cos(c*phi);
			y = cos(c*theta)*cos(c*phi);
			z = sin(c*phi);
			glVertex3d(x,y,z);
			x = sin(c*theta)*cos(c*(phi+20.0));
			y = cos(c*theta)*cos(c*(phi+20.0));
			z = sin(c*(phi+20.0));
			glVertex3d(x,y,z);
			x = sin(c*(theta+20))*cos(c*phi);
			y = cos(c*(theta+20))*cos(c*phi);
			z = sin(c*phi);
			glVertex3d(x,y,z);
			x = sin(c*(theta+20))*cos(c*(phi+20.0));
			y = cos(c*(theta+20))*cos(c*(phi+20.0));
			z = sin(c*(phi+20.0));
			glVertex3d(x,y,z);

		}
		glEnd();
	}

	x = y = 0;
	z = 1;
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	c=M_PI/180.0; 
	z=sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd();

	x=y=0; 
	z=-1; 
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3d(x,y,z); 
	z=-sin(c*80.0); 
	for(theta=-180.0; theta<=180.0; theta+=20.0) 
	{ 
		x=sin(c*theta)*cos(c*80.0); 
		y=cos(c*theta)*cos(c*80.0); 
		glVertex3d(x,y,z); 
	} 
	glEnd(); 

	glFlush();
}


void prossMenuEvents(int position)
{
	switch (position)
	{
	case 1:
		printf("test1 is press\n");
		select = QUAD_STRIP;
		disp_func();
		glutDisplayFunc(&disp_func);
		break;
	case 2:
		printf("test2 is press\n");
		select = TRI_STRIP;
		disp_func();
		glutDisplayFunc(&disp_func);
		break;
	case 3:
		printf("3 is presss\n");
		select = TRIS;
		dis_tri_strip();
		glutDisplayFunc(&dis_tri_strip);
		break;
	case 4:
		select = QUAD;
		disp_quad();
		glutDisplayFunc(&disp_quad);
		break;
	default:
		break;
	}
}


void CreateMenu()
{
	int menu;
	menu = glutCreateMenu(prossMenuEvents);
	glutAddMenuEntry("四边形带",1);
	glutAddMenuEntry("三角形带",2);
	glutAddMenuEntry("三角形",3);
	glutAddMenuEntry("四边形",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MouseListener(int x, int y)
{
	//glRotated(20.0,1.0,0.0,0.0);
	double angle = 3;
	printf("%d,%d--%lf\n",x,y,sum);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*sum+= angle;
	if(sum == 360)
		sum = 0;*/
	glRotated(angle*(x-click_x),0.0,1.0,0.0);
	glRotated(angle*(y-click_y),1,0,0);
	glutPostRedisplay();
}

void MouseClickListener(int Button,int State,int X,int Y)
{
	if(Button==GLUT_LEFT_BUTTON)
	{
		if(State == GLUT_DOWN)
		{
			click_x = X;
			click_y = Y;
		}
	}

}


//int main(int argc, char *argv[])
int main()
{

	//glutInit(&argc, argv);
	select = QUAD_STRIP;
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);

	glutInitWindowSize(400, 400);

	glutCreateWindow("第一个OpenGL程序");

	glutDisplayFunc(&disp_func);
	
	glutMotionFunc(&MouseListener);
	glutMouseFunc(&MouseClickListener);

	CreateMenu();
	printf("time is %f\n",glutGet(GLUT_ELAPSED_TIME));
	glutMainLoop();

	return 0;

}
