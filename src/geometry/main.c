#include <malloc.h>
#include <stdio.h>

#include <libgeometry/geometry.h>
#include <libgeometry/libcalculate.h>

int main()
{
    double a, p;
    struct FigureInfo* current
            = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
    current->prev = NULL;
    while (1) {
        current->circle = (char*)malloc(sizeof(struct FigureInfo));
        fgets(current->circle, 64, stdin);
        int errcode = circle(current->circle);
        if (errcode == 9) {
            return 0;
        }
        if (circle(current->circle) == 0) {
            current->next
                    = (struct FigureInfo*)malloc(sizeof(struct FigureInfo));
            p = perimeter(current->circle, current);
            a = area(current->circle, current);
            int i = intersections(current->circle, current);
            printf("perimeter: %f\narea: %f\nintersections: %d", p, a, i);
            struct FigureInfo* node = current;
            current = current->next;
            current->prev = node;
        }
    }
}