#ifndef UV_SRC_LIST_H_
#define UV_SRC_LIST_H_

/* Doubly linked list. 

   Items intended to be placed in a list
   must embed a list_elem element. Each list_elem can be in
   at most one list at a time. 

   This is a reimplementation of the Pintos linked-least scheme. 

   For example:

   struct Foo
   {
     struct list_elem elem;
     int bar;
     ...
   };

   struct list_elem *elem = list_pop_front (&foo_list);
   struct Foo *foo = list_entry (elem, struct Foo, elem); */ 
struct list_elem
{
  struct list_elem *prev;
  struct list_elem *next;
};

/* Converts pointer to list element LIST_ELEM into a pointer to
   the structure that LIST_ELEM is embedded inside.  Supply the
   name of the outer structure STRUCT and the member name MEMBER
   of the list element. */
#define list_entry(LIST_ELEM, STRUCT, MEMBER)           \
        ((STRUCT *) ((uint8_t *) &(LIST_ELEM)->next     \
                     - offsetof (STRUCT, MEMBER.next)))


#define LIST_MAGIC 12345678
struct list
{
  int magic;
  struct list_elem head;
  struct list_elem tail;
};

void list_init (struct list *list);
int list_size (struct list *list);
int list_empty (struct list *list);
int list_looks_valid (struct list *list);

struct list * list_split (struct list *list, int split_size);

void list_insert (struct list_elem *, struct list_elem *);
struct list_elem * list_remove (struct list_elem *elem);

void list_push_front (struct list *list, struct list_elem *elem);
void list_push_back (struct list *list, struct list_elem *);

struct list_elem * list_pop_front (struct list *list);
struct list_elem * list_pop_back (struct list *list);

/* For iteration:

   struct list_elem *e;
   for (e = list_begin (&list); e != list_end (&list); e = list_next (e))
   {
      foo
   } 

   Or destructively:

   struct list_elem *e;
   while (!list_empty (&list))
   {
      e = list_pop_front (&list);
      //Do stuff with e
   } */
struct list_elem * list_next (struct list_elem *elem);
struct list_elem * list_front (struct list *list);
struct list_elem * list_back (struct list *list);
struct list_elem * list_begin (struct list *list);
struct list_elem * list_end (struct list *list);
struct list_elem * list_head (struct list *list);
struct list_elem * list_tail (struct list *list);

#endif  /* UV_SRC_LIST_H_ */
