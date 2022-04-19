#include <stdio.h>
#include <string.h>
#define DEBUG
#define ShapeText(TYPE) \
char name[10];\
double (*perimeter)(struct TYPE*);
double (*perimeter)(struct TYPE*);
typedef struct shape_s {
    ShapeText(shape_s);
} shape_t;
typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle_t;
typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double length;
    double width;
} rectangle_t;
typedef struct square_s {
    ShapeText(square_s);
    double sideLength;
} square_t;
typedef struct triangle_s {
    ShapeText(triangle_s);
    double firstSide;
    double secondSide;
    double thirdSide;
} triangle_t;
double circlePerimeter(circle_t *circle){return (2 * 3.14 * circle->radius);}
double rectanglePerimeter(rectangle_t *rectangle){return (2* (rectangle->length + rectangle->width));}
double squarePerimeter(square_t *square){return (4 * square->sideLength);}
double trianglePerimeter(triangle_t *triangle){return ( triangle->firstSide + triangle->secondSide + triangle->thirdSide );}
void CreateCircle(double r,circle_t *obj){
    strcpy(obj->name,"Circle");
    obj->perimeter=circlePerimeter;
    obj->radius=r;
}
void CreateRectangle(double length,double width,rectangle_t *obj){
    strcpy(obj->name,"Rectangle");
    obj->perimeter=rectanglePerimeter;
    obj->length=length;
    obj->width=width;
}
void CreateSquare(double sideLength,square_t *obj){
    strcpy(obj->name,"Square");
    obj->perimeter=squarePerimeter;
    obj->sideLength=sideLength;
}
void CreateTriangle(double FSL,double SSL,double TSL,triangle_t *obj){
    strcpy(obj->name,"Triangle");
    obj->perimeter=trianglePerimeter;
    obj->firstSide=FSL;
    obj->secondSide=SSL;
    obj->thirdSide=TSL;
}
int main(){
    int Amount;
    scanf(" %d",&Amount);
    char inputType;

    square_t square;
    double sideLength;

    rectangle_t rectangle;
    double width;
    double length;

    circle_t circle;
    double r;

    triangle_t triangle;
    double FSL;
    double SSL;
    double TSL;
    double total=0;
    double tmp;
    for(int i=0;i<Amount;i++){
        scanf(" %c",&inputType);
        switch(inputType){
            case 'C':
                scanf(" %lf",&r);
                CreateCircle(r,&circle);
                tmp=circle.perimeter(&circle);
                tmp=(int)(tmp*100+0.5)/100.0;
                printf("%.2f\n",tmp);
                break;
            case 'R':
                scanf(" %lf",&width);
                scanf(" %lf",&length);
                CreateRectangle(length,width,&rectangle);
                tmp=rectangle.perimeter(&rectangle);
                tmp=(int)(tmp*100+0.5)/100.0;
                printf("%.2f\n",tmp);
                break;
            case 'S':
                scanf(" %lf",&sideLength);
                CreateSquare(sideLength,&square);
                tmp=square.perimeter(&square);
                tmp=(int)(tmp*100+0.5)/100.0;
                printf("%.2f\n",tmp);
                break;
            case 'T':
                scanf(" %lf",&FSL);
                scanf(" %lf",&SSL);
                scanf(" %lf",&TSL);
                //scanf(" %lf %lf %lf",&FSL,&SSL,&TSL);
                CreateTriangle(FSL,SSL,TSL,&triangle);
                tmp=triangle.perimeter(&triangle);
                tmp=(int)(tmp*100+0.5)/100.0;
                printf("%.2f\n",tmp);
                break;
        }
        total+=tmp;
    }
    printf("%.2f",total);
    return 0;
}
