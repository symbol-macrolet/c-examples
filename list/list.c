#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list* list_append(list *plist, void *data) {
    if (NULL == plist) {
        list *plist = (list *) malloc(sizeof(list));
        
        plist->data = data;
        plist->next = NULL;
        plist->prev = NULL;
        
        return plist;
    }
    else {
        while(1) {
            if (NULL == plist->next) {
                list *p = malloc(sizeof(list));
                
                plist->next = p;
                p->next = NULL;
                p->prev = plist;
                p->data = data;

                return p;
            }
            plist = plist->next;
        }
    }
}

list* list_find(list const *plist, int position) {
    list *p = plist;
    int current_position;
    for (current_position = 0;; ++current_position) {
        if (NULL == p) {
            return NULL;
        }
        if (current_position == position) {
            return p;
        }
        p = p->next;
    }
}


void list_apply(list const *plist, fp f) {
    list *p = plist;
    while(p) {
        (*f)(p->data);
        p = p->next;
    }
}

void list_print_int(list const *plist) {
    list *p = plist;
    while(p) {
        printf("%p -> %p [%d] -> %p\n",
               p->prev,
               p,
               (int) p->data,
               p->next);
        p = p->next;
    }
}

list* list_insert(list const *plist, int position, void *data) {
    list *current = plist;
    int i;

    for (i = 0; ; ++i) {
        if (NULL == current) {
            return 0;
        }
        if (i == position) {
            list *prev = current->prev;
            list *node = (list *) malloc(sizeof(list));
            
            node->data = data;
            node->next = current;

            node->prev = current->prev;

            current->prev = node;

            if (NULL != prev) {
                prev->next = node;
                return plist;
            }

            return node;
        }
        current = current->next;
    }
}


int list_join(list const *plist_a, list const *plist_b) {
    list *last;
    list *pa = plist_a;
    list *pb = plist_b;

    if (NULL == pa || NULL == pb) {
        return 0;
    }

    while(1) {
        if (NULL == pa->next) {
            pa->next = pb;
            pb->prev = pa;
            return 1;
        }
        pa = pa->next;
    }
}

int list_is_empty(list const *plist) {
    return NULL == plist;
}

void list_free(list const *plist) {
    list *p = plist;
    while (p) {
        list *next = p->next;
        free((list *) p);
        printf("debug: free %p\n", p);
        p = next;
    }
}
