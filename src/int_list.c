#include <stdlib.h>
#include "int_list.h"

/* Create a new list. */
int_node_t *list_new(int first_value)
{
    int_node_t *root = (int_node_t *)malloc(sizeof(int_node_t));
    root->data = first_value;
    root->next = NULL;
    return root;
}

/* Return list size. */
unsigned int list_size(int_node_t *root)
{
    if (root == NULL)
        return 0;
    else
    {
        unsigned int size = 1;
        while (root->next != NULL)
        {
            root = root->next;
            size++;
        }
        return size;
    }
}

/* Get the element at index. */
int list_get(int_node_t *root, unsigned int index)
{
    int size = list_size(root);
    if (index >= size)
        index = size - 1;
    int j;
    for (j = 0; j < index; j++)
        root = root->next;
    return (root->data);
}

/* Add a new element at index. */
int_node_t *list_add(int_node_t *root, unsigned int index, int value)
{
    int size = list_size(root);
    int_node_t *new_node = (int_node_t *)malloc(sizeof(int_node_t));
    int_node_t *temp = root;
    if (index > size)
        index = size;

    new_node->data = value;
    if (index != 0)
    {
        int i;
        for (i = 0; i < index; i++)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
        return root;
    }
    else
    {

        new_node->next = root;
        root = new_node;
        return root;
    }
}

/* Remove the element at index. */
int_node_t *list_remove(int_node_t *root, unsigned int index)
{
    int size = list_size(root);
    int_node_t *temp = root;
    if (index >= size)
        index = size - 1;

    if (index != 0)
    {
        int i;
        for (i = 1; i < index; i++)
            temp = temp->next;
        int_node_t *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
    else
    {
        root = root->next;
        free(temp);
    }
    return root;
}

/* Push an element to the list */
int_node_t *list_push(int_node_t *root, int value)
{
    int_node_t *temp = root;
    if (root == NULL)
    {
        root = (int_node_t *)malloc(sizeof(int_node_t));
        root->data = value;
        root->next = NULL;
        return root;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = (int_node_t *)malloc(sizeof(int_node_t));
    temp = temp->next;
    temp->data = value;
    temp->next = NULL;
    return root;
}

/* Pop the last element from the list. */
int list_pop(int_node_t *root)
{
    while (root->next->next != NULL)
        root = root->next;
    int_node_t *temp = root->next;
    int value = temp->data;
    free(temp);
    root->next = NULL;
    return value;
}

/* Print the list. */
void list_print(int_node_t *root)
{
    if (root == NULL)
        printf("Liste bos");
    else
    {
        while (root != NULL)
        {
            printf("%d ", root->data);
            root = root->next;
        }
    }
    printf("\n");
}

/* Remove the list. */
int_node_t *list_free(int_node_t *root)
{
    int_node_t *temp = root;
    while (root != NULL)
    {
        root = root->next;
        free(temp);
        temp = root;
    }
    return NULL;
}
