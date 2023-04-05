#include <stdio.h>
 
typedef struct PointType {
    int x;
    int y;
} Point;
 
Point getPoint(void);
void displayPoint(Point); // debug function
void displayPointLoc(Point);
 
int main(void)
{
    Point coordinate = getPoint();
    displayPointLoc(coordinate);
}
 
Point getPoint(void)
{
    Point output;
    
    printf("Enter x: ");
    scanf("%d", &(output.x));
    printf("Enter y: ");
    scanf("%d", &(output.y));
    
    return output;
}
 
void displayPoint(Point p)
{
    printf("(%d, %d)", p.x, p.y);
}
 
void displayPointLoc(Point p)
{
    printf("The location of coordinate "), displayPoint(p), printf(" is: ");
    
    if (p.x == 0 && p.y == 0)
        printf("Center of Origin");
    else if (p.x == 0)
        printf("Y-axis");
    else if (p.y == 0)
        printf("X-axis");
    else if (p.x > 0 && p.y > 0)
        printf("First Quadrant");
    else if (p.x < 0 && p.y > 0)
        printf("Second Quadrant");
    else if (p.x < 0 && p.y < 0)
        printf("Third Quadrant");
    else if (p.x > 0 && p.y < 0)
        printf("Fourth Quadrant");
        
}