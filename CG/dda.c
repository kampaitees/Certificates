#include <GL/glut.h> 
#include <stdio.h>


float px1, px2, py1, py2;

int abs(int x){
    if(x > 0){
        return x;
    }
    return -x;
}

void getAns(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    float dx = px2 - px1;
    float dy = py2 - py1;
    float n = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));

    

    float x = dx / n, y = dy / n;
    for(int i = 0 ; i <= n ; i++){        
        glBegin(GL_POINTS);
        glVertex2i(px1, py1);
        px1 += x;    py1 += y;
        glEnd();    
    }

    glFlush();
    

}

void init(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);      
}

int main(int argc, char** argv){

    printf("Enter points as x1, y1, x2, y2\n");
    scanf("%f%f%f%f", &px1, &py1, &px2, &py2);


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("DDA Algo");
    init();
    glutDisplayFunc(getAns);
    glutMainLoop();
    
    return 0;
}



