#include <GL/glut.h> 
#include <stdio.h>

int px1, px2, py1, py2;

void getAns(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    int incr = 2 * (py2 - py1);
    int decr = (px2 - px1);
    int err = incr - decr;
    int j = py1;
    for(int i = px1 ; i <= px2 ; i++){
        glBegin(GL_POINTS);
        glVertex2i(i, j);
        err += incr;
        if(err >= 0){
            j++;
            err -= 2 * decr;
        }

        glEnd();
        
    }
    glFlush();

}

void init(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);      
}

int main(int argc, char** argv){

    printf("Enter points as x1, y1, x2, y2\n");
    scanf("%d%d%d%d", &px1, &py1, &px2, &py2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bresenham Algo");
    init();
    glutDisplayFunc(getAns);
    glutMainLoop();
    
    return 0;
}
