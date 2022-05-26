#include<fstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<GL/freeglut.h>
#include<string>

GLfloat x = 0.20, z = 0.25, x2 = -0.20, z2 = -0.25, txp = -0.20, tzp = 0.110, txm = -0.100, tzm = -0.110, ty = -0.025, dx = 0.030, PI = 3.14;

void table();
void face();
void chairs();
void room();
void plant();
void plant2();

GLuint text_2d;
GLfloat texBoard[8][8][4];

float _angle = 0.0;

void drawLine(GLfloat x, GLfloat y, GLfloat angle) {
	glVertex3f(x, x, -0.39f);
	glVertex3f(y * cos(angle), y * sin(angle), -0.39f);
}
GLfloat T[8][3] = {
    {0.020, -0.015, 0.025},
    {-0.020, -0.015, 0.025},
    {-0.020, -0.015, -0.025},
    {0.020, -0.015, -0.025},

    {-0.020, 0.015, 0.025},
    {-0.020, 0.015, -0.025},
    {0.020, 0.015, 0.025},
    {0.020, 0.015, -0.025}
};

void laptop() {
    GLfloat cam[] = { 0.15,0.15,0.15 ,1 };
    GLfloat cam1[] = { 1,1,1 ,1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam);

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0.158, -0.111, 0.01);
    glScalef(3, 0, 1);
    glutSolidCube(0.03);
    glPopMatrix();

    //zavesaa
    GLfloat col[] = { 1,0,0 ,1 };
    glMaterialfv(GL_RED,GL_AMBIENT_AND_DIFFUSE, col);
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslatef(-0.2, -0.210, 0.10);
    glScalef(6, 0, 2);
    glutSolidCube(0.03);
    glPopMatrix();
    //monitor
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0.02, -0.169, -0.01);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.04);
    glPopMatrix();

    //
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0.15, -0.3, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.10);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0.16, -0.299, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.09);
    glPopMatrix();
}
void plant() {
    GLfloat lam[] = { 0.46, 0.75, 0.50,1 };
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();
    glTranslatef(0.31, -0.05, -0.300);
    glScalef(0.08,0.05, 0.078);
    glutSolidCube(1);
    glPopMatrix();

    GLfloat lam1[] = { 0, 1, 0.5,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0.31, 0.30, -0.03);
    glutSolidCone(0.04, 0.05, 11, 11);
    glPopMatrix();
}

void plant2()
{
    GLfloat lam[] = { 0.46, 0.75, 0.50,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();
    glTranslatef(-0.28, -0.05, 0.300);
    glScalef(0.08,0.05, 0.078);
    glutSolidCube(1.04);
    glPopMatrix();

    GLfloat lam1[] = { 0, 1, 0.5,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.28, -0.300, -0.03);
    glutSolidCone(0.04, 0.05, 11, 11);
    glPopMatrix();
}
void bed() {
    glPushMatrix();
    glTranslatef(0.2, -0.10, 0.15);
    glScalef(2.5, 0.5, 4);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.10, -0.05);
    glScalef(2.5, 1.5, 0.005);
    glutSolidCube(0.1);
    glPopMatrix();


}
void chairs() {

    GLfloat cha[] = { 0.62352, 0.372549, 0.623529,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, cha);

    glPushMatrix();
    glTranslatef(0.0, -0.05, -0.15);
    glScalef(2, 0.1, 2);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.20);
    glRotatef(90, 1, 0, 0);
    glScalef(2, 0.1, 2);
    glutSolidCube(0.05);
    glPopMatrix();

    //noge
    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.50, -0.07, -1.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.45, -0.075, -1.95);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(-0.50, -0.075, -1.1);
    glutSolidCube(0.1);
    glPopMatrix();
}
void photo()
{
    GLfloat col[] = { 0,1,1 ,1 };
    glMaterialfv(GL_RED,GL_AMBIENT_AND_DIFFUSE, col);
    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslatef(-0.2, -0.210, -0.05);
    glScalef(3, 0, 2);
    glutSolidCube(0.03);
    glPopMatrix();
}
void lamps(){

    GLfloat ram1[] = { 1,1,0.61,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ram1);
    glPushMatrix();

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -0.29);
    glColor3f(0, 0, 0);
    glutSolidCylinder(0.015, 0.05, 10, 10);
    glColor3f(0.36, 0.25, 0.2);
    glutSolidCylinder(0.0025, -0.1, 10, 10);
    glPopMatrix();

}
void ormar() {
    GLfloat clo[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo);
    glPushMatrix();
    glTranslatef(0, 0.2, -0.4);
    glutSolidCube(0.06);
    glPopMatrix();

    GLfloat clo1[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo1);
    glPushMatrix();
    glTranslatef(0, 0.13, -0.4);
    glutSolidCube(0.06);
    glPopMatrix();

    GLfloat clo2[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo2);
    glPushMatrix();
    glTranslatef(-0.09, 0.2, -0.4);
    glutSolidCube(0.06);
    glPopMatrix();

    GLfloat clo3[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo3);
    glPushMatrix();
    glTranslatef(-0.09, 0.13, -0.4);
    glutSolidCube(0.06);
    glPopMatrix();

    GLfloat clo5[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo5);
    glPushMatrix();
    glTranslatef(-0.05, 0.01, -0.4);
    glutSolidCube(0.15);
    glPopMatrix();
}
void table() {

    GLfloat tab[] = { 1,1,0.65,0.71};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, tab);
    glBegin(GL_QUADS);

    //LEGS
    glClearColor(1, 1, 0.58,0.0);
    glNormal3f(txp, -0.1, -0.01);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp, ty, tzp - 0.010);
    glVertex3f(txp, ty - 0.100, tzp - 0.010);
    glVertex3f(txp, ty - 0.100, tzp);

    glColor3f(1, 1, 0.58);
    glNormal3f(-0.01, -0.1, tzp);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp - 0.010, ty, tzp);
    glVertex3f(txp - 0.010, ty - 0.100, tzp);
    glVertex3f(txp, ty - 0.100, tzp);

    glColor3f(1, 1, 0.58);
    glNormal3f(txm, -0.1, -0.01);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm, ty, tzp - 0.010);
    glVertex3f(txm, ty - 0.100, tzp - 0.010);
    glVertex3f(txm, ty - 0.100, tzp);

    glColor3f(1, 1, 0.58);
    glNormal3f(0.01, -0.1, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm + 0.010, ty, tzp);
    glVertex3f(txm + 0.010, ty - 0.100, tzp);
    glVertex3f(txm, ty - 0.100, tzp);

    glColor3f(1, 1, 0.58);
    glNormal3f(txp, -0.1, 0.01);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp, ty, tzm + 0.010);
    glVertex3f(txp, ty - 0.100, tzm + 0.010);
    glVertex3f(txp, ty - 0.100, tzm);

    glColor3f(1, 1, 0.58);
    glNormal3f(-0.01, -0.1, tzm);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp - 0.010, ty, tzm);
    glVertex3f(txp - 0.010, ty - 0.100, tzm);
    glVertex3f(txp, ty - 0.100, tzm);

    glColor3f(1, 1, 0.58);
    glNormal3f(txm, -0.1, 0.01);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txm, ty, tzm + 0.010);
    glVertex3f(txm, ty - 0.100, tzm + 0.010);
    glVertex3f(txm, ty - 0.100, tzm);

    glColor3f(1, 1, 0.58);
    glNormal3f(0.01, -0.1, tzm);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txm + 0.010, ty, tzm);
    glVertex3f(txm + 0.010, ty - 0.100, tzm);
    glVertex3f(txm, ty - 0.100, tzm);

    //TABLE TOP
    glColor3f(1, 1, 0.58);
    glNormal3b(0, ty, 0);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txp, ty, tzm);

    glColor3f(1, 1, 0.58);
    glNormal3b(0, ty-0.010, 0);
    glVertex3f(txp, ty-0.010, tzp);
    glVertex3f(txm, ty-0.010, tzp);
    glVertex3f(txm, ty-0.010, tzm);
    glVertex3f(txp, ty-0.010, tzm);

    glColor3f(1, 1, 0.58);
    glNormal3b(0, 0, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp, ty - 0.010, tzp);
    glVertex3f(txm, ty - 0.010, tzp);

    glColor3f(1, 1, 0.58);
    glNormal3b(txp, 0, 0);
    glVertex3f(txp, ty - 0.010, tzp);
    glVertex3f(txp, ty - 0.010, tzm);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp, ty, tzp);
    glEnd();

    bed();
    ormar();
    laptop();
    plant2();
    chairs();
    photo();
    plant();
    glutSwapBuffers();
}

GLfloat room_vertices[7][3] = {
    {-0.350, -0.115, 0.400},
    {-0.350, -0.115, -0.400},
    {0.400, -0.115, -0.400},
    {0.400, -0.115, 0.400},

    {-0.350, 0.300, -0.400},
    {-0.350, 0.300, 0.400},
     {0.400, 0.300, -0.400}

};

GLfloat room_normal[3][3] = {
    {0.050, -0.115, 0},
    {-0.350, 0.115,0},
    {0.050, 0.115, -0.400}
};

GLuint texture;
GLuint texture1;
GLuint texture2;
GLuint texture3;

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}
void room() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat wall[3][4] = { { 1,1,1,1 },
                            {1,1,0.7,0.1},
                            {1,1,0.59,1} };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, wall[0]);
    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glNormal3fv(room_normal[0]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[3]);

    glColor3f(0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[1]);
    glNormal3fv(room_normal[1]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[5]);


    glColor3f(0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[2]);
    glNormal3fv(room_normal[2]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[6]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[1]);
    glEnd();

    //pokreni texture

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture2);
    glBegin(GL_POLYGON);
        //texture
         glColor3f(1.0,0.0,1.0);
         glTexCoord2d(0.0, 0.0);glVertex3f(0.1,-0.05,0.0);
         glTexCoord2d(1.0, 0.0);glVertex3f(0.33,-0.05,0.0);
         glTexCoord2d(1.0, 1.0);glVertex3f(0.33,-0.05,0.35);
         glTexCoord2d(1.0, 1.0);glVertex3f(0.1,-0.05,0.35);
        glEnd();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,texture3);
    glBegin(GL_POLYGON);
        //lap teksture
         glColor3f(1.0,1.0,1.0);
         glTexCoord2d(0.0, 0.0);glVertex3f(-0.11,0.03,0.03);
         glTexCoord2d(0.0, 2.0);glVertex3f(-0.11,0.07,0.03);
         glTexCoord2d(2.0, 2.0);glVertex3f(-0.11,0.07,0.11);
         glTexCoord2d(2.0, 0.0);glVertex3f(-0.11,0.03,0.11);
        glEnd();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D,texture2);
    glBegin(GL_POLYGON);
        // teksture
         glColor3f(1.0,1.0,1.0);
         glTexCoord2d(0.0, 0.0);glVertex3f(-0.3,-0.077,-0.35);
         glTexCoord2d(0.0, 2.0);glVertex3f(-0.3,0.1,-0.35);
         glTexCoord2d(2.0, 2.0);glVertex3f(-0.3,0.1,0.42);
         glTexCoord2d(2.0, 0.0);glVertex3f(-0.3,-0.077,0.42);
        glEnd();
    glPopMatrix();
    glPushMatrix();
    glPushMatrix();
    table();
}

void lights() {

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    GLfloat light2_pos[] = { 0, 0.2, 0, 0.0f };

    GLfloat light1_pos[] = { -0.400, -0.115, 0.400 , 0.0f };
    GLfloat diffuse0[] = { 1, 1, 1, 1.0 };
    GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse2[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat ambient0[] = { 0.2, 0.2, 0.2, 1.0 };

    GLfloat specular0[] = { 2.0, 6.0, 4.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION,  room_vertices[0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular0);


}
void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Final Project");
    lights();
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    gluPerspective(30.0, (float)900 / (float)600, 1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    GLuint text_2d;
    GLfloat texBoard[8][8][4];
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &text_2d);
    glBindTexture(GL_TEXTURE_1D, text_2d);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 8, 0, GL_RGBA, GL_FLOAT, texBoard);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glEnable(GL_DEPTH_TEST);

}
int count = 0;

void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}
static void Resize(int width, int height)
{
       glViewport(0, 0, width, height);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       float odnos =(float) width/(float) height;
       gluPerspective(10,odnos, 1.0, 20.0);
}
int main(int argc, char** argv)
{

    init(argc, argv);
    glutDisplayFunc(room);
    glutKeyboardFunc(lightoff);
    //pozivanje texture
    texture=LoadTexture("./textures/texture.raw",256, 256);
    texture1=LoadTexture("./textures/texture1.raw",256, 256);
    texture2=LoadTexture("./textures/texture2.raw",256, 256);
    texture3=LoadTexture("./textures/texture3.raw",256, 256);
    glutMainLoop();
    return 0;
}
