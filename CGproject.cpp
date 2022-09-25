#define M_PI 3.142
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<GL/glut.h>
GLfloat summary_para1_fade, summary_para2_fade, summary_para3_fade, summary_para4_fade,summary_next_text_appear;
int m, id = 0;
int sceneid = 0;
float sun = 0.0;
int p, q, r;
int nig = 0;//night time flag
int count = 0;
int st = 0;//movement of train
GLint x = 50, y = 50, xx = 0, theta = 0;
int i, j, n;
int s = 0;
char a[] = "your name";
void fronttrain();
void night();
void *currentfont;

void print(char *string,GLfloat r, GLfloat g, GLfloat b, GLfloat a,GLint x, GLint y,GLfloat w, GLfloat h,GLfloat strokeSize)
 {
	glPushMatrix();

	glColor4f(r, g, b, a);
	glTranslatef(x, y, 0);
	glScalef(w, h, 0);

	glPointSize(strokeSize);
	glLineWidth(strokeSize);

	while (*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *string++);

	glPopMatrix();

	glLineWidth(1);
	glPointSize(1);
}

void summary()
{
glClearColor(0.05, 0.05, 0.05, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Summary Title
	print("Summary",
		1, 1, 1, 1, 75, 470, .1, .1, 1.5);



void reinit()
{
	m, id = 0;
	sun = 0.0;
	p, q, r;
	nig = 0;//night time flag
	count = 0;
	st = 0;//movement of train
	x = 50, y = 50, xx = 0, theta = 0;
	i, j, n;
	s = 0;
}
void setFont(void *font)
{
 currentfont=font;                      // Set the currentfont to the font
}

void Display_on_screen(char *string)
{
	while(*string)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	}

}
void cityname(char *string)
{
	while(*string)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++);
	}

}
void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
  glutBitmapCharacter(currentfont,*c);

}

void text(void)           
{
	glColor3f(1.0,1.0,1.0);
 //setFont(GLUT_BITMAP_HELVETICA_18);
 glRasterPos3f(150,455,0);
Display_on_screen("FR CRCE")	;
 //glColor3f(0.0,1.0,1.0);
 //drawstring(150.0,455.0,1.0,"FR CRCE"); 
 
 glColor3f(0.0,1.0,1.0); // RGB color R=0 ; G=0 ; B =1; so blue!
// setFont(GLUT_BITMAP_HELVETICA_18);
// drawstring(150.0,405.0,1.0,"COMPSB");   

 setFont(GLUT_BITMAP_HELVETICA_12); //Font set to helvetica with size 12
 glColor3f(1.0,1.0,0.0);
 drawstring(190.0,350.0,1.0,"A MINI PROJECT ON-");
 setFont(GLUT_BITMAP_HELVETICA_18);
drawstring(195.0,330.0,1.0," TRAIN SIMULATION");//TRAIN SIMULATION

      setFont(GLUT_BITMAP_TIMES_ROMAN_24);
      glColor3f(0.0,1.0,1.0);
     drawstring(60.0,160.0,1.0,"BY- ");

 setFont(GLUT_BITMAP_8_BY_13);
 glColor3f(1.0,0.0,0.0);
 drawstring(60.0,140.0,1.0,"rahul bothra");
drawstring(60.0,130.0,1.0,"harsh kadam");
drawstring(60.0,120.0,1.0,"asher lopes");
drawstring(60.0,120.0,1.0,"samuel emmathy");	
 
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 glColor3f(1.0,1.0,1.0);
 drawstring(340.0,155.0,1.0,"Guided By-");
  setFont(GLUT_BITMAP_8_BY_13);
 drawstring(330.0,135.0,1.0,"Prof.dipali koshti.");

 glFlush();
                
}

void print(int x, int y, int z, char *string)
{
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(x, y);
	int len = (int)strlen(string);

	for (i = 0; i<n; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
}
//draw circle 
void circle(GLint theta1, GLint theta2, GLfloat x, GLfloat y, GLfloat radius)
{
	glBegin(GL_POLYGON);
	for (int i = theta1; i<theta2; i++)
	{
		float degInRadian = i*(3.14159 / 180);
		glVertex2f(cos(degInRadian)*radius + x, sin(degInRadian)*radius + y);
	}
	glEnd();
}

void draw_pixel(GLint cx, GLint cy)
{ 
	//glColor3f(0.4, 0.45, 0.45);
	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}
void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}
void circle_draw(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y>x)
	{
		plotpixels(h, k, x, y);
		if (d<0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}
void plotsemi(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	//draw_pixel(x + h, -y + k);
	//draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	//draw_pixel(y + h, -x + k);
	//draw_pixel(-y + h, -x + k);
}

void semicircle(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotsemi(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotsemi(h,k,x,y);
}
void cylinder_draw(GLint xc)
{
	GLint r = 15, yc = 50;
	circle_draw(xc, yc, r);
	circle_draw(xc + 115, yc, r);
	circle_draw(xc + 185, yc, r);
	circle_draw(xc + 225, yc, r);
	circle_draw(xc + 310, yc, r);
	circle_draw(xc + 350, yc, r);
	circle_draw(xc + 57, yc, r);

}


void train(int x)
{
	int y;
	if(sceneid==3||sceneid==4)
		y=50;
	else
		y=150;
	glColor3ub(240, 240, 241);
	glBegin(GL_POLYGON);
	glVertex2f(x, y + 50);
	glVertex2f(x, y + 15);
	glVertex2f(x - 15, y + 15);
	glEnd();
	circle(0, 360, x, y + 15, 15);

	//moving train
	glBegin(GL_POLYGON); // ENGINE //
	glColor3ub(240, 240, 241);
	glVertex2f(x, y);
	glVertex2f(x + 165, y);
	glVertex2f(x + 165, y + 100);
	glVertex2f(x + 25, y + 100);
	glVertex2f(x, y + 50);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	glVertex2f(x + 5, y + 20);
	glVertex2f(x + 165, y + 20);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 5, y + 30);
	glVertex2f(x + 165, y + 30);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 5, y + 30);
	glVertex2f(x - 5, y + 40);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 5, y + 20);
	glVertex2f(x - 9, y + 32);
	glEnd();



	glBegin(GL_POLYGON);  //COACH 1//
	glColor3ub(240, 240, 241);
	glVertex2f(x + 175, y);
	glVertex2f(x + 282, y);
	glVertex2f(x + 282, y + 100);
	glVertex2f(x + 175, y + 100);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(x + 175, y + 30);
	glVertex2f(x + 282, y + 30);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 175, y + 20);
	glVertex2f(x + 282, y + 20);
	glEnd();

	glBegin(GL_POLYGON); //COACH 1 WINDOW //
	glColor3f(0, 1, 1);
	glVertex2f(x + 245, y + 60);
	glVertex2f(x + 270, y + 60);
	glVertex2f(x + 270, y + 85);
	glVertex2f(x + 245, y + 85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 215, y + 60);
	glVertex2f(x + 240, y + 60);
	glVertex2f(x + 240, y + 85);
	glVertex2f(x + 215, y + 85);
	glEnd();

	glBegin(GL_POLYGON); //ENGINE WINDOW //
	glColor3f(0, 1, 1);
	glVertex2f(x + 25, y + 50);
	glVertex2f(x + 50, y + 50);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 25, y + 85);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(x + 25, y + 85);
	glVertex2f(x + 25, y + 50);
	glVertex2f(x + 8, y + 50);
	glEnd();


	glColor3ub(0, 0, 0);//bogey
	glBegin(GL_POLYGON);
	glVertex2f(x + 165, y + 5);
	glVertex2f(x + 175, y + 5);
	glVertex2f(x + 175, y + 95);
	glVertex2f(x + 165, y + 95);
	glEnd();


	glBegin(GL_POLYGON);  //COACH 2
	glColor3ub(240, 240, 241);
	glVertex2f(x + 293, y);
	glVertex2f(x + 400, y);
	glVertex2f(x + 400, y + 100);
	glVertex2f(x + 293, y + 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 282, y + 5);
	glVertex2f(x + 282, y + 95);
	glVertex2f(x + 293, y + 95);
	glVertex2f(x + 293, y + 5);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(x + 293, y + 30);
	glVertex2f(x + 400, y + 30);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(x + 293, y + 20);
	glVertex2f(x + 400, y + 20);
	glEnd();

	//COACH2 WINDOW

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 340, y + 60);
	glVertex2f(x + 365, y + 60);
	glVertex2f(x + 365, y + 85);
	glVertex2f(x + 340, y + 85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 370, y + 60);
	glVertex2f(x + 395, y + 60);
	glVertex2f(x + 395, y + 85);
	glVertex2f(x + 370, y + 85);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 1//
	glColor3f(0.8, 0.78, 0.78);
	glVertex2f(x + 180, y + 20);
	glVertex2f(x + 200, y + 20);
	glVertex2f(x + 200, y + 70);
	glVertex2f(x + 180, y + 70);
	glEnd();

	glBegin(GL_POLYGON);
	
	glVertex2f(x + 180, y + 20);
	glVertex2f(x + 190, y + 25);
	glVertex2f(x + 190, y + 60);
	glVertex2f(x + 180, y + 70);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 2//
	glColor3f(0.8, 0.78, 0.78);
	glVertex2f(x + 300, y + 20);
	glVertex2f(x + 320, y + 20);
	glVertex2f(x + 320, y + 70);
	glVertex2f(x + 300, y + 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.78, 0.78, 0.78);
	glVertex2f(x + 300, y + 20);
	glVertex2f(x + 310, y + 25);
	glVertex2f(x + 310, y + 60);
	glVertex2f(x + 300, y + 70);
	glEnd();

	/*glLineWidth(2.5);
	glBegin(GL_LINES);//FRONT
	glColor3f(0, 0, 0);
	glVertex2f(x, y + 20);
	glVertex2f(x - 10, y + 20);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x, y + 35);
	glVertex2f(x - 10, y + 35);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x - 10, y + 20);
	glVertex2f(x - 10, y + 40);
	glEnd();
	*/

	// ELECTRIC
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 50, y + 100);
	glVertex2f(x + 60, y + 110);
	glVertex2f(x + 90, y + 110);
	glVertex2f(x + 100, y + 100);
	glEnd();
	glFlush();


	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(x + 75, y + 110);
	glVertex2f(x + 75, y + 130);
	glVertex2f(x + 130, y + 180);
	glVertex2f(x + 125, y + 150);
	glVertex2f(x + 75, y + 130);
	glEnd();

	/*	while(i==1)
	{
	glLineWidth(2.0); //wheel
	glPushMatrix();
	glTranslatef(x + 25, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 25, -y, 0);
	glBegin(GL_LINES);//wheel spokes//
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 25, y + 15);
	glVertex2f(x + 25, y - 15);
	glEnd();
	glPopMatrix();
	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 25, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 25, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 40, y);
	glVertex2f(x + 10, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 25, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 25, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 16, y - 12);
	glVertex2f(x + 33, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0);//2nd wheel spokes
	glPushMatrix();
	glTranslatef(x + 82, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 82, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 82, y + 15);
	glVertex2f(x + 82, y - 15);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 82, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 82, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 97, y);
	glVertex2f(x + 67, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 82, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 82, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 90, y - 12);
	glVertex2f(x + 72, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0);
	glPushMatrix();
	glTranslatef(x + 140, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 140, -y, 0);//3rd wheel spokes
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 140, y + 15);
	glVertex2f(x + 140, y - 15);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 140, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 140, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 125, y);
	glVertex2f(x + 155, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 140, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 140, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 132, y - 12);
	glVertex2f(x + 148, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0); //coach1 wheel spokes
	glPushMatrix();
	glTranslatef(x + 210, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 210, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 210, y + 15);
	glVertex2f(x + 210, y - 15);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 210, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 210, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 225, y);
	glVertex2f(x + 195, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 210, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 210, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 217, y - 12);
	glVertex2f(x + 202, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0);//coach1 2nd wheel
	glPushMatrix();
	glTranslatef(x + 250, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 250, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 250, y + 15);
	glVertex2f(x + 250, y - 15);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 250, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 250, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 265, y);
	glVertex2f(x + 235, y);
	glEnd();
	glPopMatrix();
	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 250, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 250, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 240, y - 12);
	glVertex2f(x + 257, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0);
	glPushMatrix();
	glTranslatef(x + 335, y, 0);//coach2 wheel spokes
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 335, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 335, y + 15);
	glVertex2f(x + 335, y - 15);
	glEnd();
	glPopMatrix();
	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 335, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 335, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 320, y);
	glVertex2f(x + 350, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 335, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 335, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 340, y - 12);
	glVertex2f(x + 325, y + 12);
	glEnd();
	glPopMatrix();

	glLineWidth(2.0);//coach 2nd
	glPushMatrix();
	glTranslatef(x + 375, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 375, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 375, y + 15);
	glVertex2f(x + 375, y - 15);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 375, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 375, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 360, y);
	glVertex2f(x + 390, y);
	glEnd();
	glPopMatrix();

	glLineWidth(3.0);
	glPushMatrix();
	glTranslatef(x + 375, y, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-x - 375, -y, 0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 365, y - 12);
	glVertex2f(x + 380, y + 12);
	glEnd();

	glPopMatrix();


	*/
	glFlush();
}
void electricwire()
{
	int y;
	if(sceneid==2||sceneid==3)
		y=200;
	else
		y=300;
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-1000, y);
	glVertex2f(5000, y);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-1000, y+30);
	glVertex2f(5000, y+30);
	glEnd();
	//glBegin(GL_LINES);
	//glVertex2f(750,300);
	//glVertex2f(1000,300);
	//glEnd();

}


void track()
{	int y;
if(sceneid==2||sceneid==3)
	y=35;
else
	y=135;
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-1000, y);
	glVertex2f(5000, y);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-1000, y+10);
	glVertex2f(5000, y+10);
	glEnd();
	//int i;
	glPointSize(8);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	for (i = -3000; i <= 5000; i = i + 10)
	{
		glVertex2f(i, y);
		glVertex2f(i, y+10);
	}
	glEnd();


}


void sky()
{



	if (nig == 0)
	{

		glBegin(GL_POLYGON);
		glColor3f(0.4, 0.6, 1);
		glVertex2f(0, 230);
		glVertex2f(0, 700);
		glVertex2f(700, 700);
		glVertex2f(700, 230);
		glEnd();

		int l;
		//sun
		glColor3f(1.0, 1.0, 0.0);
		for (l = 0; l <= 35; l++)
		{

			circle_draw(100 + sun, 450, l);
		}
	}
	else if (nig == 1)
	{
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 230);
		glVertex2f(0, 700);
		glVertex2f(700, 700);
		glVertex2f(700, 230);
		glEnd();

		//moon
		int l;
		glColor3f(1.0, 1.0, 1.0);
		for (l = 0; l <= 35; l++)
		{

			circle_draw(100 + sun, 400, l);
		}

		//star1

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(200, 380);
		glVertex2f(195, 372);
		glVertex2f(205, 372);
		glVertex2f(200, 369);
		glVertex2f(195, 377);
		glVertex2f(205, 377);
		glEnd();

		//star2
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(400, 420);
		glVertex2f(395, 412);
		glVertex2f(405, 412);
		glVertex2f(400, 409);
		glVertex2f(395, 417);
		glVertex2f(405, 417);
		glEnd();

		//star3
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(50, 370);
		glVertex2f(45, 362);
		glVertex2f(55, 362);
		glVertex2f(50, 359);
		glVertex2f(45, 367);
		glVertex2f(55, 367);
		glEnd();

		//star4
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(400, 350);
		glVertex2f(395, 342);
		glVertex2f(405, 342);
		glVertex2f(400, 339);
		glVertex2f(395, 347);
		glVertex2f(405, 347);
		glEnd();

		//star5
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(120, 450);
		glVertex2f(115, 442);
		glVertex2f(125, 442);
		glVertex2f(120, 439);
		glVertex2f(115, 447);
		glVertex2f(125, 447);
		glEnd();



	}
}

void road()
{
	glColor3f(0.2, 0.7, 0.3); //road
	glBegin(GL_POLYGON);
	glVertex2f(0, 200);
	glVertex2f(0, 12);
	glVertex2f(10000, 12);
	glVertex2f(10000, 200);
	glEnd();
	glColor3f(0.3, 0.5, 0.2);  //lower road
	glBegin(GL_POLYGON);
	glVertex2f(550, 180);
	glVertex2f(600, 180);
	glVertex2f(600, 280);
	glVertex2f(550, 280);
	glEnd();
	glColor3f(0.3, 0.3, 0.5);		//first bar
	glBegin(GL_POLYGON);
	glVertex2f(10, 55);
	glVertex2f(425, 55);
	glVertex2f(425, 105);
	glVertex2f(10, 105);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);		//second bar
	glVertex2f(325, 105);
	glVertex2f(330, 105);
	glVertex2f(330, 165);
	glVertex2f(325, 165);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(375, 105);
	glVertex2f(380, 105);
	glVertex2f(380, 165);
	glVertex2f(375, 165);
	glEnd();

	//overhead
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	for (i = -3000; i <= 5000; i = i + 20)
	{
		glVertex2f(i + 5, 200);
		glVertex2f(i + 10, 230);
	}
	glEnd();

	glColor3f(1.0, 1.0, 0.0);			//nameplate
	glBegin(GL_POLYGON);
	glVertex2f(315, 165);
	glVertex2f(315, 205);
	glVertex2f(390, 205);
	glVertex2f(390, 165);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos3f(320,190,0);
	cityname("MUMBAI");//MUM
	glRasterPos3f(320,170,0);
	cityname("STATION.");//ST

	glColor3ub(200, 233, 240);//poles
	glBegin(GL_POLYGON);
	glVertex2f(25, 25);
	glVertex2f(25, 280);
	glVertex2f(35, 280);
	glVertex2f(35, 25);
	glEnd();
	glLineWidth(0.5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(25, 25);
	glVertex2f(25, 280);
	glVertex2f(35, 280);
	glVertex2f(35, 25);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(35, 275);
	glVertex2f(65, 230);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(35, 230);
	glVertex2f(65, 230);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(35, 230);
	glVertex2f(65, 200);
	glEnd();




}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);		
	glLoadIdentity();
	gluOrtho2D(0, 499, 0, 499);

}
 
void mouse(int btn, GLint state, GLint x, int y)
{
	if (btn == GLUT_LEFT_BUTTON&&state == GLUT_DOWN)
		printf("x=%d y = %d", x, y);


	//glutPostRedisplay();
}
/*
void drawstring(float p, float q, float r, char *string)
{
	char *c;
	glRasterPos3f(p, q, r);

	for (c = string; *c != '\0'; c++)
	{
		glColor3f(0.0, 1.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
	}
}

*/
void overhead()
{
	int y;
	if(sceneid==2||sceneid==3)
		y=200;
	else
		y=300;
	glLineWidth(1);
	glColor3f(0, 0, 0);
	glVertex2f(0, y);
	glVertex2f(1000, y);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, y+30);
	glVertex2f(10000, y+30);
	glEnd();
	//int i;
}

void hill()
{
	glColor3f(0.5f, 0.3f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(100, 400);
	glVertex2f(280, 230);
	glVertex2f(0, 230);
	glEnd();

	glColor3f(0.5f, 0.3f, 0.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(280, 230);
	glVertex2f(380, 400);
	glVertex2f(500, 230);
	glEnd();
}

void stoptrain()
{
	int y = 50;
	glBegin(GL_POLYGON); // ENGINE //
	glColor3f(0, 0, 1);
	glVertex2f(x, y);
	glVertex2f(x + 165, y);
	glVertex2f(x + 165, y + 100);
	glVertex2f(x + 25, y + 100);
	glVertex2f(x, y + 50);
	glEnd();

	glBegin(GL_POLYGON);  //COACH 1//
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x + 175, y);
	glVertex2f(x + 282, y);
	glVertex2f(x + 282, y + 100);
	glVertex2f(x + 175, y + 100);
	glEnd();

	glBegin(GL_POLYGON); //COACH 1 WINDOW //
	glColor3f(0, 1, 1);
	glVertex2f(x + 245, y + 60);
	glVertex2f(x + 270, y + 60);
	glVertex2f(x + 270, y + 85);
	glVertex2f(x + 245, y + 85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 215, y + 60);
	glVertex2f(x + 240, y + 60);
	glVertex2f(x + 240, y + 85);
	glVertex2f(x + 215, y + 85);
	glEnd();

	glBegin(GL_POLYGON); //ENGINE WINDOW //
	glColor3f(0, 1, 1);
	glVertex2f(x + 25, y + 50);
	glVertex2f(x + 50, y + 50);
	glVertex2f(x + 50, y + 85);
	glVertex2f(x + 25, y + 85);
	glEnd();
	glLineWidth(4);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 165, y + 25);
	glVertex2f(x + 175, y + 25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 165, y + 75);
	glVertex2f(x + 175, y + 75);
	glEnd();
	glBegin(GL_POLYGON);  //COACH 2
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(x + 293, y);
	glVertex2f(x + 400, y);
	glVertex2f(x + 400, y + 100);
	glVertex2f(x + 293, y + 100);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 282, y + 25);
	glVertex2f(x + 293, y + 25);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(x + 282, y + 75);
	glVertex2f(x + 293, y + 75);
	glEnd();

	//COACH2 WINDOW

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 340, y + 60);
	glVertex2f(x + 365, y + 60);
	glVertex2f(x + 365, y + 85);
	glVertex2f(x + 340, y + 85);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 1, 1);
	glVertex2f(x + 370, y + 60);
	glVertex2f(x + 395, y + 60);
	glVertex2f(x + 395, y + 85);
	glVertex2f(x + 370, y + 85);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 1//
	glColor3f(1, 1, 1);
	glVertex2f(x + 180, y + 20);
	glVertex2f(x + 200, y + 20);
	glVertex2f(x + 200, y + 70);
	glVertex2f(x + 180, y + 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.78, 0.78);
	glVertex2f(x + 180, y + 20);
	glVertex2f(x + 190, y + 25);
	glVertex2f(x + 190, y + 60);
	glVertex2f(x + 180, y + 70);
	glEnd();

	glBegin(GL_POLYGON); //DOOR 2//
	glColor3f(1, 1, 1);
	glVertex2f(x + 300, y + 20);
	glVertex2f(x + 320, y + 20);
	glVertex2f(x + 320, y + 70);
	glVertex2f(x + 300, y + 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.78, 0.78, 0.78);
	glVertex2f(x + 300, y + 20);
	glVertex2f(x + 310, y + 25);
	glVertex2f(x + 310, y + 60);
	glVertex2f(x + 300, y + 70);
	glEnd();

	glLineWidth(2.5);
	glBegin(GL_LINES);//FRONT
	glColor3f(0, 0, 0);
	glVertex2f(x, y + 20);
	glVertex2f(x - 10, y + 20);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x, y + 35);
	glVertex2f(x - 10, y + 35);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(x - 10, y + 20);
	glVertex2f(x - 10, y + 40);
	glEnd();

	// ELECTRIC
	/*	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(x + 50, y + 100);
	glVertex2f(x + 60, y + 110);
	glVertex2f(x + 90, y + 110);
	glVertex2f(x + 100, y + 100);
	glEnd();f
	glFlush();
	*/
}

void scene0()
{
	//myinit();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	text();
	glFlush();
}

void scene()
{
		summary();
}

void scene1()
{

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	sky();
	hill();
	electricwire();
	road();
	track();
	
	overhead();
	glFlush();
}

void scene2()
{
	glPushMatrix();
	sky();
	hill();
	electricwire();
	road();
	track();

	overhead();

	//stop();


	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	if (!st)
		glTranslated(-xx, 0, 0);
	train(50);
	train(750);
	train(1450);
	train(2150);
	train(2850);
	glColor3f(0.0, 0.0, 0.0);

	/*cylinder_draw(75);
	cylinder_draw(775);
	cylinder_draw(1475);
	cylinder_draw(2175);
	cylinder_draw(2875);
	*/
	glPopMatrix();
}

void scene4()
{
	int l;
	glClearColor(0.4, 0.6, 1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
		//cable
	glColor3f(0.0,0.0,0.0);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(250,200);
	glVertex2f(200,200);
	glVertex2f(400,700);
	glVertex2f(450,700);
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINES);
	
	glVertex2f(257,343);
	glVertex2f(307,341);
	glEnd();
	glColor3f(0.2, 0.7, 0.3);//land
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(700,0);
	glVertex2f(700,100);
	glVertex2f(0,100);
	glEnd();
	//side track
	glColor3f(0.5,0.3,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(180,100);
	glVertex2f(140,0);
	glVertex2f(370,0);
	glVertex2f(310,100);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);//track color
	glVertex2f(240,100);
	glVertex2f(200,0);
	glVertex2f(300,0);
	glVertex2f(260,100);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);//track
	glVertex2f(240,100);
	glVertex2f(200,0);
	glVertex2f(300,0);
	glVertex2f(260,100);
	glEnd();
	
	glColor3ub(220, 220, 221); //back body
	glBegin(GL_POLYGON);
	glVertex2f(200,70);
	glVertex2f(300,70);
	glVertex2f(317,175);
	glVertex2f(177,175);
	glEnd();
	
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(200,70);
	glVertex2f(205,50);
	glVertex2f(295,50);
	glVertex2f(300,70);
	glEnd();

	//toppart
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(240,260);
	glVertex2f(240,280);
	glVertex2f(260,280);
	glVertex2f(260,260);
	glEnd();
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(252,280);
	glVertex2f(257,343);
	glVertex2f(307,341);
	glEnd();
	glColor3ub(240, 240, 241); //body
	glBegin(GL_POLYGON);
	glVertex2f(230,100);
	glVertex2f(180,170);
	glVertex2f(180,220);
	glVertex2f(180,250);
	glVertex2f(250,265);
	glVertex2f(315,250);
	glVertex2f(315,220);
	glVertex2f(315,170);
	glVertex2f(270,100);
	glEnd();
		glColor3ub(225, 230, 225);//nose
	for(l=0;l<25;l++)
		circle_draw(250,110,l);
	glColor3ub(50,50,50);//lights
	glBegin(GL_POLYGON);
	glVertex2f(215,100);
	glVertex2f(205,100);
	glVertex2f(195,120);
	glVertex2f(205,120);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(295,100);
	glVertex2f(285,100);
	glVertex2f(295,120);
	glVertex2f(305,120);
	glEnd();
	glColor3f(1.0,1.0,0.0);
	for(l=0;l<4;l++)
	{
		circle_draw(208,105,l);
		circle_draw(292,105,l);
	}

	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);//windows
	glVertex2f(185,190);
	glVertex2f(185,240);
	glVertex2f(310,240);
	glVertex2f(310,190);
	glEnd();
	glLineWidth(3);
	glColor3ub(240, 240, 241);
	glBegin(GL_LINES);
	glVertex2f(247,190);
	glVertex2f(247,240);
	glEnd();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(200,140);
	glVertex2f(297,140);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(197,145);
	glVertex2f(300,145);
	glEnd();
	
	//polef
	glColor3ub(200, 233, 240);
	glBegin(GL_POLYGON);
	glVertex2f(120,50);
	glVertex2f(140,50);
	glVertex2f(140,380);
	glVertex2f(120,380);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(120,50);
	glVertex2f(140,50);
	glVertex2f(140,380);
	glVertex2f(120,380);
	glEnd();
	//connecting lines
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(140,370);
	glVertex2f(255,340);
	glVertex2f(140,320);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(140,320);
	glVertex2f(295,310);
	
	glEnd();

	

}
void scene5()
{
	int l;
	glClearColor(1, 1, 1,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	sky();
	if(nig==0)
		glColor3f(0.4,0.6,1);
	else
		glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,230);
	glVertex2f(1000,230);
	glVertex2f(1000,185);
	glVertex2f(0,185);
	glEnd();
	overhead();
	electricwire();
	track();	
		//grass
	glColor3ub(150,85,0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,135);
	glVertex2f(1000,135);
	glVertex2f(1000,0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0,145);
	glVertex2f(0,185);
	glVertex2f(1000,185);
	glVertex2f(1000,145);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(0,185);
	glVertex2f(1000,185);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(0,195);
	glVertex2f(1000,195);
	glEnd();
	glLineWidth(1);
	for (i = -3000; i <= 5000; i = i + 30)
	{	
		glBegin(GL_LINE_LOOP);
		glVertex2f(i, 185);
		glVertex2f(i, 195);
		glEnd();
	}



		

	glColor3f(1,1,1);
	for(l=0;l<300;l++)
		semicircle(250,-175,l);
	//river
	glColor3ub(80,90,250);
	glBegin(GL_POLYGON);
	glVertex2f(35,40);
	glVertex2f(465,40);
	glVertex2f(500,0);
	glVertex2f(0,0);
	glEnd();
	glLineWidth(2);
	glColor3ub(120,120,255);
	glBegin(GL_LINES);
	glVertex2f(45,20);
	glVertex2f(35,20);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(75,10);
	glVertex2f(90,10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(105,15);
	glVertex2f(115,15);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(170,17);
	glVertex2f(185,17);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(260,25);
	glVertex2f(270,25);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(210,10);
	glVertex2f(220,10);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(420,5);
	glVertex2f(410,5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(290,30);
	glVertex2f(280,30);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(350,10);
	glVertex2f(360,10);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(390,20);
	glVertex2f(400,20);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(345,5);
	glVertex2f(355,5);
	glEnd();

		glColor3f(0.0,0.0,0.0);//bridge
	for(l=0;l<4;l++)
		semicircle(250,-175,300+l);

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	if (!st)
		glTranslated(-xx, 0, 0);
	train(50);
	train(750);
	train(1450);
	train(2150);
	train(2850);
	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	switch (sceneid)
	{
	case 0: scene0();
			break;
	case 1:  scene();
			break;
	case 2:
		
		scene1();
		break;
	case 3:
		scene2();
		break;
	case 4:
		scene4();
		break;
	case 5:
		scene5();
		break;
	}

	glutSwapBuffers();

}

void mykey(unsigned char key, int x, int y)
{ 
	switch (key)
	{
	case'l':
	case'L':reinit();
		sceneid--;
		break;
	case'k':
	case'K':reinit();
		sceneid++;
		break;
	}
}



void menu(int id)
{
	int n = 0;
	while (n<1)
	{
		switch (id)
		{
		case 1:
			st = (st + 1) % 2;//stop train
			break;
		case 2://nightmode
			nig = (nig + 1) % 2;
			break;
		case 3:break;


		case 4:	exit(0);
			break;

		}
		n++;
	}
}

void idle()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	if (sceneid == 3||sceneid==2||sceneid==5)
	{
		if (st == 0)
		{
			xx += 1;
			theta += 1;
			sun += 0.5;
			if (sun > 700)
			{
				sun = 0;
				nig = (nig + 1) % 2;
			}
		}
		else
		{
			if (sun > 700)
			{
				nig = (nig + 1) % 2;
				sun = 0;
			}
			sun += 0.5;
		}
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	int c_menu;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Train Simulator");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	c_menu = glutCreateMenu(menu);
	glutAddMenuEntry("start/stop train", 1);
	glutAddMenuEntry("day/night color change", 2);
	glutAddMenuEntry("quit", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	myinit();
	glutMainLoop();
	return 0;}