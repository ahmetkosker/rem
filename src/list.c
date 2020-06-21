#include <stdlib.h>
#include "list.h"

node *list_new(int first_value)
{
    node *root = (node *)malloc(sizeof(node));
    root->data = first_value;
    root->next = NULL;
    return root;
}

unsigned int list_size(node *start)
{
    if (start == NULL)
        return 0;
    else
    {
        int size = 1;
        node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
}

int list_get(node *start, unsigned int index)
{
    node *temp = start;
    int size = list_size(start);
    if (index > size)
    {
        printf("Gecersiz sayi ");
        return 0;
    }
    else
    {
        int i;
        for (i = 0; i < index; i++)
            temp = temp->next;
        return (temp->data);
    }
}

node *list_add(node *start, unsigned int index, int value)
{
    int size = list_size(start);
    node *iter = (node *)malloc(sizeof(node));
    node *temp = start;
    if (index > size)
    {
        printf("Gecersiz sayi ");
        return NULL;
    }
    else
    {
        int i;
        if (index != 0)
        {
            for (i = 1; i < index; i++)
                temp = temp->next;
            iter->data = value;
            iter->next = temp->next;
            temp->next = iter;
            return start;
        }
        else
        {
            iter->data = value;
            iter->next = start;
            start = iter;
            return start;
        }
    }
}

node *list_remove(node *start, unsigned int index)
{
    int size = list_size(start);
    node *temp = start;
    if (index > size)
    {
        printf("Gecersiz sayi\n");
        return NULL;
    }
    else
    {
        int i;
        if (index != 0)
        {
            for (i = 1; i < index; i++)
                temp = temp->next;
            node *iter = temp->next;
            temp->next = temp->next->next;
            free(iter);
        }
        else
        {
            start = start->next;
            free(temp);
        }
        return start;
    }
}

void list_push(node *start, int value)
{
    node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = (node *)malloc(sizeof(node));
    temp = temp->next;
    temp->data = value;
    temp->next = NULL;
}

int list_pop(node *start)
{
    node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    node *iter = temp->next;
    int value = iter->data;
    free(iter);
    temp->next = NULL;
    return value;
}

void list_print(node *start)
{
    node *temp = start;
    if (start == NULL)
        printf("Liste bos");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

node *list_free(node *start)
{
    node *temp = start;
    node *iter = start;
    while (temp != NULL)
    {
        temp = temp->next;
        free(iter);
        iter = temp;
    }
    return NULL;
}
