#include <GL/glut.h> 
#include <stdio.h>


void dda(float px1, float py1, float px2, float py2){
    

    float dx = px2 - px1;
    float dy = py2 - py1;
    float n = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));

    

    float x = dx / n, y = dy / n;
    for(int i = 0 ; i <= n ; i++){        
        glBegin(GL_POINTS);
        glVertex2i(px1, py1);
        glEnd();
        px1 += x;    py1 += y;
            
    }


}


void getAns(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    for(int i = -200 ; i <= 200 ; i++){
        for(int j = -200 ; j <= 200 ; j++){
            int fact = i/50 + j/50;
            fact %= 2;  fact += 2;  fact %= 2;
            if(fact%2 && i <= 0 && j >= 0){
                glBegin(GL_POINTS);
                glVertex2i(i, j);
                glEnd();
            }else if(fact%2 == 0 && i >= 0 && j >= 0){
                glBegin(GL_POINTS);
                glVertex2i(i, j);
                glEnd();
            }else if(fact%2 == 0 && i <= 0 && j <= 0){
                glBegin(GL_POINTS);
                glVertex2i(i, j);
                glEnd();
            }else if(fact%2 == 1 && i >= 0 && j <= 0){
                glBegin(GL_POINTS);
                glVertex2i(i, j);
                glEnd();
            }
        }
    }

    // along x axis
    for(int i = -200 ; i <= 200 ; i += 50){
        dda((float)-200, (float)i, (float)200, (float)i);
    }
    for(int i = -200 ; i <= 200 ; i += 50){
        dda((float)i, (float)-200, (float)i, (float)200);
    }


    glFlush();

}

void init(){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);      
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Chess Algo");
    init();
    glutDisplayFunc(getAns);
    glutMainLoop();
    
    return 0;
}
