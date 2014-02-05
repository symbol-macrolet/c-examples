struct list;

typedef struct list {
    void *data;
    struct list *next;
    struct list *prev;
} list;

typedef void (*fp)(void*);


/*
  Принимает список и данные нового узла;
  возвращает head модифицированного списка
*/
list* list_append(list *plist, void *data);

/*
  Принимает список и позицию (начиная с 0);
  возвращает указатель на узел или NULL, если список короче, чем position
 */
list* list_find(list const *plist, int position);

/*
  Вставляет новый узел в список plist в position с данными data;
  возвращает head модифицированного списка
 */
list* list_insert(list const *plist, int position, void *data);

/*
  Проверяет пустой ли список (фактически проверка на NULL)
 */
int list_is_empty(list const *plist);

/*
  Очищает память выделенного под список plist
 */
void list_free(list const *plist);

/*
  Применяет к данным каждого элемента списка функцию f
 */
void list_apply(list const *plist, fp f);

/*
  Объединяет 2 списка
 */
int list_join(list const *plist_a, list const *plist_b);

/*
  Для отладки
 */
void list_print_int(list const *plist);
