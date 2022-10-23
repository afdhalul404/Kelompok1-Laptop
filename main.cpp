//E1E120024_AFDHALUL RAHMAT S
//E1E120018_NURUL FATIMAH
//E1E120066_FADILAH HAIRUL NISA
//E1E120026_DENI HIDAYAT
//E1E120106_KATHARINA AMELIA
//E1E120064_DERIS ALFIKAR
//E1E12062_ASRI SAMSUDIN
#include<gl/glut.h>
#include <math.h>

//Deklarasi fungsi Mouse agar gambar 3d dapat diputar putar menggunakan Mouse
float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;

//DEKLARASI UNTUK MEMBUAT BENDA BERGERAK
int gerak = 0;
bool atas = true;


//Deklarasi pengaturan lembaran kerja agar Gambar 3d yang kita buat saat diputar atau di geser tidak kemana mana
void ukur(int lebar, int tinggi){
    if(tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,lebar/tinggi, 5, 450);
    glTranslatef(0,0,-400);// jarak object dari lembaran kerja
    glMatrixMode(GL_MODELVIEW);
}


void myinit(void){
    glClearColor (0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glPointSize(10.0);
    glLineWidth(7.0f);
}

//Dan selanjutnya yaitu fungsi mouse
void idle(){
    if (!mouseDown){
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    } else
        mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void dda(int i, int j, int a, int k, int l, int b) {
	int x1, y1, x2, y2, z1, z2;
	float x,y,dx, dy, steps, x_inc, y_inc;
	//tentukan titik awal dan akhir
	x1 = i;
	y1 = j;
	x2 = k;
	y2 = l;
	x = x1;
	y = y1;
	z1 = a;
	z2 = b;

	//hitung dx dan dy
	dx = x2 - x1;
	dy = y2 - y1;

	//hitung steps
	if (abs(dx) > abs(dy)) {
		steps = abs(dx);
	}
	else steps = abs(dy);

	//hitung perubahan nilai x (x_inc) dan y (y_inc)
	x_inc = dx / (float) steps;
	y_inc = dy / (float )steps;

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex3i(round(x), round(y), z1); // gambar titik awal

	//perulangan untuk menggambar titik-titik
	do {
		x += x_inc; // x = x + x_inc
		y += y_inc; // y = y + y_inc
		glVertex3i(round(x), round(y), z2); //gambar titik
	} while (x < x2);

	glEnd();
	glFlush();
}

//void dda(){
//
//}

//Dibawah ini dimulai koding untuk membuat object
void laptop(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();
    glTranslatef( gerak, 0,0);//UNTUK MENGGERAKKAN BENDA

//layar
    //lcd
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-67, 70, 5.5);
    glVertex3f(67, 70, 5.5);
    glVertex3f(67, -15, 5.5);
    glVertex3f(-67, -15, 5.5);
    glEnd();

    //camera
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-10, 75.8, 5.5);
    glVertex3f(10, 75.8, 5.5);
    glVertex3f(10, 74.5, 5.5);
    glVertex3f(-10, 74.5, 5.5);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3ub(82, 82, 82);
    glVertex3f(-70, 80, 0);
    glVertex3f(70, 80, 0);
    glVertex3f(70, -20, 0);
    glVertex3f(-70, -20, 0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3ub(82, 82, 82);
    glVertex3f(-70, 80, 5);
    glVertex3f(70, 80, 5);
    glVertex3f(70, -20, 5);
    glVertex3f(-70, -20, 5);
    glEnd();

    //tutup atas
    glBegin(GL_QUADS);
    glColor3ub(82, 82, 82);
    glVertex3f(-70, 80, 0);
    glVertex3f(70, 80, 0);
    glVertex3f(70, 80, 5);
    glVertex3f(-70, 80, 5);
    glEnd();

    //tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(82, 82, 82);
    glVertex3f(70, -20, 5);
    glVertex3f(70, 80, 5);
    glVertex3f(70, 80, 0);
    glVertex3f(70, -20, 0);
    glEnd();

    //tutup bawah
    glBegin(GL_QUADS);
    glColor3ub(82, 82, 82);
    glVertex3f(-70, -20, 5);
    glVertex3f(70, -20, 5);
    glVertex3f(70, -20, 0);
    glVertex3f(-70, -20, 0);
    glEnd();

    //tutup kiri
    glBegin(GL_POLYGON);
    glColor3ub(82, 82, 82);
    glVertex3f(-70, 80, 5);
    glVertex3f(-70, 80, 0);
    glVertex3f(-70, -20, 0);
    glVertex3f(-70, -20, 5);
    glEnd();



//Bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.8, 0.8);
    glVertex3f(-70, -20, 0);
    glVertex3f(70, -20, 0);
    glVertex3f(80, -110, 10);
    glVertex3f(-80, -110, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.8, 0.8);
    glVertex3f(-70, -20, 5);
    glVertex3f(70, -20, 5);
    glVertex3f(80, -100, 15);
    glVertex3f(-80, -100, 15);
    glEnd();

    //tutup depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.8, 0.8);
    glVertex3f(80, -100, 15);
    glVertex3f(80, -110, 10);
    glVertex3f(-80, -110, 10);
    glVertex3f(-80, -100, 15);
    glEnd();

    //tutup kanan
    glBegin(GL_QUADS);
    glColor3f(.7, 0.8, 0.8);
    glVertex3f(70, -20, 5);
    glVertex3f(70, -20, 0);
    glVertex3f(80, -110, 10);
    glVertex3f(75, -100, 15);
    glEnd();

    //tutup kiri
    glBegin(GL_QUADS);
    glColor3f(.7, 0.8, 0.8);
    glVertex3f(-70, -20, 5);
    glVertex3f(-70, -20, 0);
    glVertex3f(-80, -110, 10);
    glVertex3f(-75, -100, 15);
    glEnd();


//keyboard
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-68, -23, 6);
    glVertex3f(68, -23, 6);
    glVertex3f(73, -65, 11);
    glVertex3f(-73, -65, 11);
    glEnd();

    //kursor
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.8);
    glVertex3f(-25, -68, 16);
    glVertex3f(25, -68, 16);
    glVertex3f(26, -97, 15);
    glVertex3f(-26, -97, 15);
    glEnd();

    //keycaps
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    dda(-61, -30, 10, 61, -30, 10);
    dda(-63, -40, 10, 63, -40, 10);
    dda(-65, -50, 10, 65, -50, 10);
    dda(-67, -60, 13, 67, -60, 13);
    glEnd();

glPushMatrix();
glPopMatrix();
glutSwapBuffers();
}





int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(240, 80);
    glutInitWindowSize(750, 600);
    glutCreateWindow("OBJECT LAPTOP 3D");
    myinit();
    glutDisplayFunc(laptop);
//    glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukur);
    glutMainLoop();
    //kettypuny
}
// perubahan fatimah lagi
