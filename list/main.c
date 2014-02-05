#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void f(void *data) {
    printf("%d\n", (int) data);
}

int main(void) {

    printf("Construct list [0 <-> 1 <-> 2 <-> 3]:\n");
    list *plist = list_append(NULL, (void*) 0);
    list_append(plist, (void *) 1);
    list_append(plist, (void *) 2);
    list_append(plist, (void *) 3);
    list_print_int(plist);
    printf("\n\n\n");

    printf("Insert 2 (777), 0 (666):\n");
    plist = list_insert(plist, 2, (void *) 777);
    plist = list_insert(plist, 0, (void *) 666);
    list_print_int(plist);
    printf("\n\n\n");


    printf("Construct list [100 <-> 200]:\n");
    list *plist_2 = list_append(NULL, (void*) 100);
    list_append(plist_2, (void *) 200);
    list_print_int(plist_2);
    printf("\n\n\n");


    printf("Join lists:\n");
    list_join(plist, plist_2);
    list_print_int(plist);
    printf("\n\n\n");


    printf("Find fourth element:\n");
    printf("%d\n", (int) list_find(plist, 3)->data);
    printf("\n\n\n");


    printf("Out list data:\n");
    list_apply(plist, f);
    printf("\n\n\n");

    printf("Free:\n");
    list_free(plist);
}
