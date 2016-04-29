
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

//Definimos variables

GLfloat X = 0.0;
GLfloat Y = 0.0;

GLfloat mat_ambient[] = {};
GLfloat mat_diffuse[] = {};
GLfloat mat_specular[] = {};
GLfloat mat_shine[]={};

GLfloat light_position [] = { 0.0, 0.0, 3.0, 2.0 };


void figura(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
	glutSolidSphere(1.0,50,50);

}


void display()
{
   	//borrar pantalla y z-buffer
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//resetear transformaciones
	//Aplicado de la Luz
	
	glTranslatef((-X*0.01),(Y*0.01),3.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLoadIdentity();
	//llamado de la esfera
    figura();
	glFlush();
	glutSwapBuffers();
}

void mouse(int x, int y){
	 X=600-x-300;
	 Y=600-y-300;
	 glutPostRedisplay();
	 display();
	}
void motion(int button,int state,int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
			X=600-x-300;
			Y=600-y-300;
		}
		display();
	}

	void reshape(int w,int h){
				
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
	 
		}
	
	
void init(){
			mat_ambient[0] =  (0.329412,0.223528,0.027451);
		mat_diffuse[0] =  (0.780392,0.568627,0.113725);
		mat_specular[0] =  (0.992157,0.941176,0.807843);
		mat_shine[0]=(0.21794872);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//habilitar la prueba de profundiad de z-buffer
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	}

void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 'b'://brass
		mat_ambient[0] =  (0.329412,0.223528,0.027451);
		mat_diffuse[0] =  (0.780392,0.568627,0.113725);
		mat_specular[0] =  (0.992157,0.941176,0.807843);
        mat_shine[0]=(0.21794872);
        break;
    case 's'://silver
		mat_ambient[0] = (0.19225,0.19225,0.19225);
		mat_diffuse[0] = (0.40754,0.40754,0.40754);
		mat_specular[0] = (0.408273,0.408273,0.408273);
        mat_shine[0]=(0.4);
        break;
    case 'g' ://gold		
		mat_ambient[0] =  (0.529412,0.523528,0.027451);
		mat_diffuse[0] =  (0.780392,0.768627,0.113725);
		mat_specular[0] =  (0.992157,0.941176,0.807843);
        mat_shine[0]=(0.21794872);
        break;
    case 'r' ://red plastic	
		mat_ambient[0] = (0.0,0.0,0.0);
		mat_diffuse[0] = (1.0,0.6,0.6);
		mat_specular[0] = (1.0,0.5,0.5);
        mat_shine[0]=(0.0);
        break;
    case 'c' ://cyan plastic
		mat_ambient[0] = (0.25,0.25,0.25);
		mat_diffuse[0] = (0.4,0.4,0.4);
		mat_specular[0] = (0.00940392,0.00940392,0.00940392);
        mat_shine[0]=(1.0);
        break;
    }
    glutPostRedisplay();
}



int main(int argc, char* argv[])
{

    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);

    // Solicitar ventana con color real y doble buffer con Z-buffer
    //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (0, 0);
    // Crear ventana
    glutCreateWindow("Textura y Luz");
	init();
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMotionFunc(mouse);
    glutMouseFunc(motion);
    // Pasar el control de eventos a GLUT
    glutMainLoop();

    // Regresar al sistema operativo
    return 0;

}


