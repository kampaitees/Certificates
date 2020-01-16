// #include <GL/glut.h>
// #include <math.h>
// #include <stdlib.h>

// float a, b, c, d;

// void setpixel(GLint xCoordinate, GLint yCoordinate) {
//   glBegin(GL_POINTS);
//   glVertex2i(xCoordinate, yCoordinate);
//   glEnd();
//   glFlush();
// }

// void DDA(int X1, int Y1, int X2, int Y2) {
//   int I;
//   float Length;
//   float X, Y, Xinc, Yinc;
//   Length = abs(X2 - X1);
//   if (abs(Y2 - Y1) > Length)
//     Length = abs(Y2 - Y1);
//   Xinc = (X2 - X1) / (Length);
//   Yinc = (Y2 - Y1) / (Length);
//   X = X1;
//   Y = Y1;
//   for (I = 0; I < Length; I++) {
//     setpixel((X + 0.5), (Y + 0.5));
//     X = X + Xinc;
//     Y = Y + Yinc;
//   }
// }

// void drawmyline() { DDA(a, b, c, d); }

// void init(void) {

//   glClearColor(1.0, 1.0, 1.0, 0.0);
//   glMatrixMode(GL_PROJECTION);
//   gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
// }

// int main(int argc, char **argv) {
//   printf("DDA\nEnter co-ordinates to draw line(Co-ordinates in between (0 - "
//          "300))\n");




//   printf("X1 = ");
//   scanf("%f", &a);
//   printf("Y1 = ");
//   scanf("%f", &b);
//   printf("Xend = ");
//   scanf("%f", &c);
//   printf("Yend = ");
//   scanf("%f", &d);
//   glutInit(&argc, argv);
//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//   glutInitWindowSize(500, 500);
//   glutInitWindowPosition(0, 0);
//   glutCreateWindow("Digital Differential Analyzer Algorithm");
//   init();
//   glutDisplayFunc(drawmyline);
//   glutMainLoop();
//   return 0;
// }
