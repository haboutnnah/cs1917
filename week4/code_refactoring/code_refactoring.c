/*
* Test if a point is inside a triangle.
* Julian Saknussemm
*
* Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
* the triangle.
*
* This is determined by satisfying the following rule:
* A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
* iff
* P is on the same side of the line AB as C
* P is on the same side of the line BC as A
* and
* P is on the same side of the line AC as B
*
* A special case exits for a vertical line (inf gradient) when testing the side of the line
*/
     
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define IS_ABOVE_LINE 1
#define IS_ON_LINE    0
#define IS_UNDER_LINE -1

#define TRUE  1
#define FALSE 0

int isAboveLine( double px, double py, double m, double b );
int testThreePoints (double x0,double y0,
                     double x1,double y1,
                     double x2,double y2,
                     double px, double py);
int pointsOnSameSide (double px, double py, 
                      double m,double b, 
                      double lx, double ly);
void testProgram(void);

int main (int argc, char* argv[]) {
    testProgram();
    double x0,y0,x1,y1,x2,y2;
    double px,py;
     
    int countValues = 0;
    int exitStatus;

    // get input
    printf("Triangle Vertex A (x,y): ");
    countValues += scanf("%lf,%lf", &x0,&y0);
    printf("Triangle Vertex  B (x,y): ");
    countValues += scanf("%lf,%lf", &x1,&y1);
    printf("Triangle Vertex  C (x,y): ");
    countValues += scanf("%lf,%lf", &x2,&y2);
    printf("Test Point (x,y): ");
    countValues += scanf("%lf,%lf", &px,&py);
     
    // print error
    if(countValues != 8 ) {
        printf("Please only input what is asked, ");
        printf("two values seperated by a comma.\n");
        exitStatus = EXIT_FAILURE;
    } else {
        // print answer
        printf("Point (%.2lf,%.2lf) is ", px,py);
        
        if(testThreePoints(x0, y0, x1, y1, x2, y2, px, py)) {
            printf("inside");
        } else {
            printf("outside");
        }
        printf(" the triangle\n");
        exitStatus = EXIT_SUCCESS;
    }
    // return 0
    return exitStatus;
}

void testProgram (void) {
    printf("running tests . . . ");
    assert(testThreePoints(3, 2, 2, 3, 0, 2, 2, 2) == FALSE);
    assert(testThreePoints(1, 1, 1, 1, 1, 1, 1, 1) == TRUE);
    assert(testThreePoints(11, 2, 7, 4, 4, 9, 10, 5) == FALSE);
    assert(testThreePoints(11, 2, 7, 4, 4, 9, 15, 5) == FALSE);
    assert(testThreePoints(11, 2, 7, 4, 4, 9, 15, 1) == FALSE);
    printf("all tests passed");
}

int isAboveLine( double px, double py, double m, double b ) {
    int lineStatus = IS_ABOVE_LINE;

    if( py < m * px + b ) {
        lineStatus =  IS_UNDER_LINE; 
    } else if ( py == m * px + b ) {
        lineStatus = IS_ON_LINE;
    } 

    return lineStatus;
}

// two points lie on the same side of a line  
int pointsOnSameSide (double px, double py, 
                      double m,double b, 
                      double lx, double ly) {
    int status = FALSE;
    if (isAboveLine(px, py, m, b ) == isAboveLine(lx, ly ,m, b)) {
        status = TRUE;
    }
    return status;
}
    
int testThreePoints (double x0,double y0,
                     double x1,double y1,
                     double x2,double y2,
                     double px, double py){

    int line1, line2, line3;
    double gradient1, gradient2;
    double constant1, constant2;
    double gradient1and2, constant1and2;
    int status = FALSE;
    // line eqns
     
    gradient1 = (y1-y0)/(x1-x0);
    constant1 = gradient1 * -x1 + y1;
    gradient2 = (y2-y0)/(x2-x0);
    gradient1and2 = (y2-y1)/(x2-x1);
    constant2 = gradient2 * -x2 + y2;
    constant1and2 = gradient1and2 * -x2 + y2;
     
    // vertical line checks
    if ( x1 == x0 ) {
       line1 = ( (px <= x0) == (x2 <= x0) );
    } else {
       line1 = pointsOnSameSide(px, py, gradient1, constant1, x2, y2);
    }
     
    if ( x1 == x2 ) {
            line2 = ( (px <= x2) == (x0 <= x2) );
    } else {
        line2 = pointsOnSameSide(px, py, 
                                 gradient1and2, constant1and2,
                                 x0, y0);
    }
     
    if ( x2 == x0 ) {
        line3 = ( (px <= x0 ) == (x1 <= x0) );
    } else {
        line3 = pointsOnSameSide(px, py, gradient2,constant2,x1,y1);
    }
    if (line1 && line2 && line3) {
        status = TRUE;
    }
     
    return status;
}

