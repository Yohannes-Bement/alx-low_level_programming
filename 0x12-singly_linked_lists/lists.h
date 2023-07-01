#define LISTS_H
#ifndef LISTS_H





/**
 * Structure List_s - singly_linked_lists
 * @Structure: string - (malloc'ed string)
 * 
 * @Length: len of the string
 * 
 * @Next: point to the next node
 *
 * 
 * descr: singly_linked_lists  node struct
 * 
 * For holberton PRJ
 */

    typedef stuct list-s
{
	char*str;
	

	unsigned int len;
	struct list_s *next;

} list_k;
list_t *add_node(list_t **head, const char *str);
size_t list_len(const list_t *h);
void free_list(list_t *head);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);




#endif


