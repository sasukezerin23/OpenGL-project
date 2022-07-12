
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<bits/stdc++.h>
#include <stdlib.h>
#include<math.h>
#define PI 3.141592

#include "RGBpixmap.cpp"


RGBpixmap pix[7];
static int slices = 16;
static int stacks = 16;

double tx = 0;
double ty = 0;
double tz = 0;


float degreeX = 0.0 ;
float degreeY = 0.0 ;
float degreeZ = 0.0 ;

double z = 1;
double angle = 360 ;




double ex = 0;
double ey = 0;
double ez = 25;


void scale(double x, double y, double z){
    GLfloat mat[] ={
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    };
    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(mat);
}



void  cube()
{
    glEnableClientState(GL_VERTEX_ARRAY);
	static GLfloat vertices[] = {
      0, 0, 2,
	  0, 2, 2,
      2, 2, 2,
	  2, 0, 2,
      2, 2, 0,
      2, 0, 0,
      0, 0, 0,
      0, 2, 0
};

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	static GLubyte allIndices[] = {
	    0,3,2,1,
	    6,0,1,7,
	    5,6,7,4,
	    3,5,4,2,
	    6,5,3,0,
	    1,2,4,7};


glDrawElements (GL_QUADS, 24, GL_UNSIGNED_BYTE, allIndices);
}


const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 5.0f, -10.0f, 0.0f };



const GLfloat qaAmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
const GLfloat qaDiffuseLight[]    = {1, 1, 1, 1.0};
const GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
const GLfloat qaLightPosition[]    = {0.0f, 10.0f, -35.0f, 1.0};
//GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
//GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
    // Light source position

//const GLfloat qaLightDirection[]    = {1, 1, -1, 0};
//const GLfloat dirVector0[]={ 0.0f, 0.0f, -5.0f, 0.0};
const GLfloat dirVector0[]={ 0.0f, -0.1f, 0.0f, 0.0};



const GLfloat light_ambient2[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse2[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position2[] = { 0.5f, 5.0f, -2.5f, 0.0f };
//const GLfloat light_position2[] = { 0.5f, 5.0f, -20.5f, 0.0f };



int width1,height1;

static void resize(int width, int height)
{
    width1=width;
    height1=height;

    const float ar = (float) (width/2) / (float) height;

    //glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(0, 0, 25, 0, 0, 0, 0, 1, 0);
}


void circle(double r, double g, double b){
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for(double i = 360; i >=0; i--)

    {
        double theta = 2.0f * 3.1415926f * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, -.1);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for(double i = 0; i <= 360; i++)
    {
        double theta = 2.0f * 3.1415926f * i / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);

        glVertex3f(x, y, .1);
    }
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    for(double i = 0; i <= 360; i++)
    {
        double theta = 2.0f * 3.1415926f * i / 360;
        double theta2 = 2.0f * 3.1415926f * (i == 360? 0: i + 1) / 360;

        double x = 2 * cosf(theta);
        double y = 2 * sinf(theta);
        double nx = 2 * cosf(theta2);
        double ny = 2 * sinf(theta2);

        glVertex3f(x, y, .1);
        glVertex3f(x, y, -.1);
        glVertex3f(nx, ny, -.1);
        glVertex3f(nx, ny, .1);
    }
    glEnd();
}

static GLdouble r = 1;
static GLdouble q = 0;
static GLdouble camHeight = 0;
static GLdouble cr = 90;

static GLdouble ccX = 0;
static GLdouble ccY = 0;
static GLdouble ccZ = 0;




 void wings(GLdouble rot)
 {
   glPushMatrix();


    glTranslated(1.2,8.1,-2.1);
    glRotated(rot,0,0,1);
    glRotatef(angle, 0, 0, 1);

    const GLfloat mat_ambient3[]    = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_diffuse3[]    = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat mat_specular3[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess3[] = { 100.0f };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_ambient3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_diffuse3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_specular3);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess3);


   // glColor3d(r,g,b);
    glScalef(2,.3,.05);
    cube();
  glPopMatrix();
 }

void fan()
{


glPushMatrix();
    glTranslated(1.1,8.2,-2.9);
    glRotatef(angle, 0, 0, 1);
    glScalef(.35,.35,5.8);
    circle(0,0,1);
glPopMatrix();

    wings(0);
    wings(120);
    wings(240);


   glPushMatrix();

    glTranslated(1.1,8.1,-2.3);
    glScalef(.3,.3,4.8);
    circle(.8,.8,0);

    glPopMatrix();

    glPushMatrix();

    glTranslated(1.1,8.1,-2.3);
    glScalef(.15,.15,5.8);
    circle(.8,0,0);

    glPopMatrix();

}



void stand(GLdouble tx, GLdouble ty,GLdouble tz,GLdouble rotan, GLdouble rx, GLdouble ry,GLdouble rz, GLdouble sx, GLdouble sy,GLdouble sz)

{
    glPushMatrix();

    glTranslated(tx,ty,tz);
        glRotated(rotan,rx,ry,rz);

const GLfloat mat_ambient[]    = { 0.0f, 0.0f, 0.1f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.9f, 0.8f, 0.6f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

       // glColor3d(.9,.8,.6);
    glScalef(sx,sy,sz);
    cube();
  glPopMatrix();



}


//const GLfloat mat_ambient2[]    = { 0.4f, 1.0f, 0.4f, 1.0f };

const GLfloat mat_ambient2[]    = { 1.0f, 0.0f, 0.0f, 1.0f };
//const GLfloat mat_diffuse2[]    = { 0.4f, 1.0f, 0.8f, 1.0f };
const GLfloat mat_diffuse2[]    = { 0.93f, 0.76f, 0.72f, 1.0f };
const GLfloat mat_specular2[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess2[] = { 100.0f };


void standwall(GLdouble tx, GLdouble ty,GLdouble tz,GLdouble rotan, GLdouble rx, GLdouble ry,GLdouble rz, GLdouble sx, GLdouble sy,GLdouble sz)

{
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess2);

    glTranslated(tx,ty,tz);
        glRotated(rotan,rx,ry,rz);

    glScalef(sx,sy,sz);

    cube();

  glPopMatrix();

}



/////////////////

const GLfloat mat_ambient6[]    = { 1.0f, 0.0f, 0.0f, 1.0f };
//const GLfloat mat_diffuse2[]    = { 0.4f, 1.0f, 0.8f, 1.0f };
const GLfloat mat_diffuse6[]    = { 0.97f, 0.97f, 0.90f, 1.0f };
const GLfloat mat_specular6[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess6[] = { 100.0f };


void standwall1(GLdouble tx, GLdouble ty,GLdouble tz,GLdouble rotan, GLdouble rx, GLdouble ry,GLdouble rz, GLdouble sx, GLdouble sy,GLdouble sz)

{
    glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient6);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse6);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular6);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess6);

    glTranslated(tx,ty,tz);
        glRotated(rotan,rx,ry,rz);

    glScalef(sx,sy,sz);

    cube();

  glPopMatrix();

}


///////////////////////


const GLfloat mat_ambient1[]    = { 0.7f, 0.2f, 0.0f, 1.0f };
const GLfloat mat_diffuse1[]    = { 0.7f, 0.2f, 0.0f, 1.0f };
//const GLfloat mat_diffuse1[]    = { 0.1f, 0.5f, 0.0f, 1.0f };
const GLfloat mat_specular1[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess1[] = { 100.0f };




void standtable(GLdouble tx, GLdouble ty,GLdouble tz,GLdouble rotan, GLdouble rx, GLdouble ry,GLdouble rz, GLdouble sx, GLdouble sy,GLdouble sz)

{
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse1);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular1);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess1);



    glTranslated(tx,ty,tz);
    glRotated(rotan,rx,ry,rz);

    glScalef(sx,sy,sz);

    cube();

  glPopMatrix();



}


void windmill()
{

//vertical stand
stand(0,0,-4,10,1,0,-1,.15,4,.1);
stand(0,0,-2,10,-1,0,-1,.15,4,.1);
stand(2,0,-2,10,-1,0,1,.15,4,.1);
stand(2,0,-4,10,1,0,1,.1,4,.1);


//horizontal stand middle
stand(0.2,2.5,-3.8,0,0,0,0,.9,.15,.15);
stand(0.2,2.5,-2.3,0,0,0,0,.9,.15,.15);
stand(0.2,2.5,-3.9,0,0,0,0,.15,.15,.9);
stand(1.8,2.5,-3.75,0,0,0,0,.15,.15,.9);


//horizontal stand lower
stand(0.7,5.5,-3.5,0,0,0,0,.45,.15,.15);
stand(0.8,5.5,-2.6,0,0,0,0,.45,.15,.15);
stand(0.6,5.5,-3.25,0,0,0,0,.15,.15,.4);
stand(1.5,5.5,-3.3,0,0,0,0,.15,.15,.4);


//horizontal stand upper
stand(0,0.2,-4,0,0,0,0,1.2,.15,.15);
stand(0,0.2,-2,0,0,0,0,1.2,.15,.15);
stand(0,0.2,-4.2,0,0,0,0,.15,.15,1.2);
stand(2,0.2,-4,0,0,0,0,.15,.15,1.2);

}



void spin()
{
    angle = angle - .1;
    if (angle <= 0)
    {
        angle = 360;
    }
    glutPostRedisplay();
}


const GLfloat mat_ambient4[]    = { 0.0f, 0.0f, 0.2f, 1.0f };
const GLfloat mat_diffuse4[]    = { 0.0f, 0.0f, 1.0f, 0.6f };
const GLfloat mat_specular4[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess4[] = { 100.0f };

spherical(GLdouble tx, GLdouble ty,GLdouble tz,GLdouble rotan, GLdouble rx, GLdouble ry,GLdouble rz, GLdouble sx, GLdouble sy,GLdouble sz)
{

       glPushMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient4);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse4);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular4);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess4);
       glTranslated(tx,ty,tz);
       glRotated(rotan,rx,ry,rz);
       glScaled(sx,sy,sz);
        glutSolidSphere(4.0, 50, 50);
        glPopMatrix();


}


void jack()
{


    spherical(-12,5,8,90,1,0,0,1,.1,.1);
    spherical(-12,5,8,90,0,1,0,1,.1,.1);
    spherical(-12,5,8,90,0,0,1,1,.1,.1);


    spherical(-15.5,5,8,0,0,0,0,.2,.2,.2);
     spherical(-8.5,5,8,0,0,0,0,.2,.2,.2);
      spherical(-12,5,12,0,0,0,0,.2,.2,.2);
       spherical(-12,5,3.7,0,0,0,0,.2,.2,.2);
        spherical(-12,9,8,0,0,0,0,.2,.2,.2);
         spherical(-12,1,8,0,0,0,0,.2,.2,.2);

}



void wall()
{


glPushMatrix();
glBindTexture(GL_TEXTURE_2D,2);
	glEnable(GL_TEXTURE_2D);

//standwall(-25.1,-15,15,0,0,0,0,2,22,-18);


standwall(-25.1,-15,15,90,0,1,0,18,22,2);
standwall(-21,-15,-21,0,0,0,0,10,22,2);
standwall(22,-15,-21,0,0,0,0,10,22,2);


standwall(-3,21,-21,0,0,0,0,14,4,2);
standwall(-3,-15,-21,0,0,0,0,14,7,2);


//standwall(-21,-15,-21,0,0,0,0,32,22,2);
   glDisable(GL_TEXTURE_2D);
 glPopMatrix();


 glPushMatrix();
glBindTexture(GL_TEXTURE_2D,6);
	glEnable(GL_TEXTURE_2D);
standwall1(-25,-15,-21,90,1,0,0,33.5,18,2);
 //standwall(-25,-37.1,15,0,0,0,0,34,10,-18);
   glDisable(GL_TEXTURE_2D);
 glPopMatrix();



 // standwall(-25,-17.1,-25,20,10,0,0,34,1,-30);
 glPushMatrix();
glBindTexture(GL_TEXTURE_2D,7);
	glEnable(GL_TEXTURE_2D);
//standwall1(-25,-5,-80,0,0,0,0,34,22,2);
   glDisable(GL_TEXTURE_2D);
 glPopMatrix();
/*
glPushMatrix();
glTranslated(-20,-15,-21);
glScaled(26,18,.1);
glutSolidCube(1);
glPopMatrix();*/

}


void wall1()
{


glPushMatrix();


//standwall(-25.1,-15,15,0,0,0,0,2,22,-18);


standwall(-25.1,-15,15,90,0,1,0,18,22,2);
standwall(-21,-15,-21,0,0,0,0,10,22,2);
standwall(22,-15,-21,0,0,0,0,10,22,2);


standwall(-3,21,-21,0,0,0,0,14,4,2);
standwall(-3,-15,-21,0,0,0,0,14,7,2);


//standwall(-21,-15,-21,0,0,0,0,32,22,2);

 glPopMatrix();


 glPushMatrix();

standwall1(-25,-15,-21,90,1,0,0,33.5,18,2);
 //standwall(-25,-37.1,15,0,0,0,0,34,10,-18);

 glPopMatrix();



 // standwall(-25,-17.1,-25,20,10,0,0,34,1,-30);
 glPushMatrix();

standwall(-25,-5,-80,0,0,0,0,34,22,2);
 glPopMatrix();


}






void table()
{



    //standtable(-5,-1,8,0,0,0,0,13,.5,-9);
    standwall1(-7.0,-1,-10,90,1,0,0,15,9,.5);
   standtable(-4,-1,5,0,0,0,0,.5,-5.5,.5);
    standtable(19,-1,5,0,0,0,0,.5,-5.5,.5);
    standtable(-4,-1,-8.5,0,0,0,0,.5,-5.5,.5);
    standtable(19,-1,-8.5,0,0,0,0,.5,-5.5,.5);


}

void tableelements()
{
      //scale(.7,.7,.7);
  glPushMatrix();
glBindTexture(GL_TEXTURE_2D,4);
	glEnable(GL_TEXTURE_2D);

        table();
    glDisable(GL_TEXTURE_2D);
      glTranslated(0,0,3);
      windmill();
      fan();
      glPopMatrix();

        //glTranslated(25,-1,-10);
        glTranslated(25,13,-7);
        glRotated(60,1,0,1);

        jack();

}



void tableelements2()
{
      //scale(.7,.7,.7);
  glPushMatrix();
        table();
      glTranslated(0,0,3);
      windmill();
      fan();
      glPopMatrix();

        //glTranslated(25,-1,-10);
        glTranslated(25,13,-7);
        glRotated(60,1,0,1);

        jack();

}




static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       //ryp();
    glPushMatrix();
 glViewport(0, 0, width1/2, height1);
   // glTranslated(0.0f, 10.0f, -35.0f);
    //glutSolidSphere(0.3, 50, 50);
    glPopMatrix();
        glPushMatrix();
    glTranslated(-2,-2,-7);
        glTranslated(tx, ty, tz);
        scale(z, z, z);
        glRotated(degreeX,1,0,0);
        glRotated(degreeY,0,1,0);
        glRotated(degreeZ,0,0,1);
        //scale(2.2,2.2,2.2);
        scale(.5,.5,.5);
       // glScaled(.8,.8,.8);

        scale(.6,.6,.6);
         wall();
        glTranslated(-8,-2.5,-3);

      tableelements();
    glPopMatrix();




////////////////////////////
glPushMatrix();
 glViewport(width1/2, 0, width1/2, height1);
       //glTranslated(2.5f, 10.0f, -30.0f);
    //glutSolidSphere(0.3, 50, 50);
    glPopMatrix();
        glPushMatrix();
    glTranslated(-1,-2,-7);
        glTranslated(tx, ty, tz);
        scale(z, z, z);
        glRotated(degreeX,1,0,0);
        glRotated(degreeY,0,1,0);
        glRotated(degreeZ,0,0,1);
        //scale(2.2,2.2,2.2);
        scale(.5,.5,.5);
       // glScaled(.8,.8,.8);

        scale(.6,.6,.6);
         wall1();
        glTranslated(-8,-2.5,-3);

      tableelements2();
    glPopMatrix();
/////////////////////////////////////////////
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(ex, ey, ez, 0, 0, 0, 0, 1, 0);

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case ' ':
            exit(0);
            break;
        case 'x':
            degreeX +=2.5 ;
            break;

        case 'y':
            degreeY +=2.5;
            break;

        case 'z':
            degreeZ +=2.5 ;
            break;


        case 'X':
            tx++;
            break;
        case 'Y':
            ty++;
            break;
        case 'Z':
            tz++;
            break;
        case 'i':
            tx--;
            break;
        case 'j':
            ty--;
            break;
        case 'k':
            tz--;
            break;


        case '+':
            if(z >= 1.5) break;
            z += .2;
            break;
        case '-':
            if(z <= .5) break;
            z -= .2;
            break;


        case 'c':
            ex++;
            break;
        case 'd':
            ey++;
            break;
        case 'e':
            ez++;
            break;

        case 'C':
            ex--;
            break;
        case 'D':
            ey--;
            break;
        case 'E':
            ez--;
            break;
        case '0':
            glDisable(GL_LIGHT0);
            break;
        case '1':
             glEnable(GL_LIGHT0);
             break;

        case 'S':
            glDisable(GL_LIGHT1);
            break;
        case 's':
             glEnable(GL_LIGHT1);
             break;

        case '7':
            glDisable(GL_LIGHT2);
            break;
        case '8':
             glEnable(GL_LIGHT2);
             break;

    glutPostRedisplay();
}

}


void initLighting()
{


     // Set lighting intensity and color
       glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);

    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition);
    glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);


     glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);// set cutoff angle
     glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirVector0);
     glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2); // set focusing strength


}


static void idle(void)
{
    glutPostRedisplay();
}


/* Program entry point */


void Init()
{


    pix[0].makeCheckImage();
	pix[0].setTexture(1);

	pix[1].readBMPFile("F:\\Final Project\\brick.bmp");
	pix[1].setTexture(2);

	pix[2].readBMPFile("F:\\Final Project\\jack.bmp");
	pix[2].setTexture(3);

	pix[3].readBMPFile("F:\\Final Project\\table.bmp");
	pix[3].setTexture(4);

    pix[4].readBMPFile("F:\\Final Project\\cone.bmp");
	pix[4].setTexture(5);

	 pix[5].readBMPFile("F:\\Final Project\\tile9.bmp");
	pix[5].setTexture(6);

		 pix[6].readBMPFile("F:\\Final Project\\sunset3.bmp");
	pix[6].setTexture(7);


}




int main(int argc, char *argv[])
{
    printf("x-axis rotate x:\n y-axis rotate: y\nz-axis rotate: z\nx-translate: X\n y-translate: Y\n z-translate: Z\nzoom-in: +\nzoom-out: -\neye-x: c\neye-y: d\neye-z: e\neye-x-: C\n eye-y-: D\neye-z-: E");
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Windmill Animation");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(spin);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);



    glEnable(GL_NORMALIZE);
    //glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    initLighting();


    glLightfv(GL_LIGHT2, GL_AMBIENT,  light_ambient2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  light_diffuse2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular2);

    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);

    Init();
    glutMainLoop();




    return EXIT_SUCCESS;
}
