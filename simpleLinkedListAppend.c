#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;
    struct point * next;
};
void printPoints(struct point *);
struct point * appendPoints(struct point *, struct point *);
void initPoints(struct point *);

int main(void) {
    //! showMemory(start=65520)
    struct point *pt1, *pt2, *pt3;
    struct point * start, *end;
  
    pt1 = (struct point *) malloc(1 * sizeof(struct point));
    pt2 = (struct point *) malloc(1 * sizeof(struct point));
    pt3 = (struct point *) malloc(1 * sizeof(struct point));
    
    start = end = pt1;
    end = appendPoints(end, pt2);
    end = appendPoints(end, pt3);

    initPoints(start);    
    printPoints(start);
    
	return 0;
}

void initPoints(struct point * start){
    struct point * ptr;
    int factor = 1;
    ptr = start;
    while (ptr!=NULL){
        ptr->x = -1;
        ptr->y = factor * factor;
        ptr = ptr->next;
        factor++;
    }

}

void printPoints(struct point *start) {
    //! showMemory(start = 65520, cursors=[ptr])
    struct point * ptr;
    ptr = start;
    while (ptr!=NULL) {
        printf("(%d, %d)\n", ptr->x, ptr->y);
        ptr = ptr->next;
    }
}

struct point * appendPoints(struct point *end, struct point *newptr){
    end->next = newptr;
    return (end->next);
}