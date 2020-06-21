#include <stdlib.h>
#include "int_list.h"

int_n *list_new(int first_value)
{
    int_n *root = (int_n *)malloc(sizeof(int_n));
    root->data = first_value;
    root->next = NULL;
    return root;
}

unsigned int list_size(int_n *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int size = 1;
        int_n *temp = root;
        while (temp->next != NULL)
        {
            temp = temp->next;
            size++;
        }
        return size;
    }
}

int list_get(int_n *root, unsigned int index)
{
    int_n *temp = root;
    int size = list_size(root);
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

int_n *list_add(int_n *root, unsigned int index, int value)
{
    int size = list_size(root);
    int_n *iter = (int_n *)malloc(sizeof(int_n));
    int_n *temp = root;
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
            return root;
        }
        else
        {
            iter->data = value;
            iter->next = root;
            root = iter;
            return root;
        }
    }
}

int_n *list_remove(int_n *root, unsigned int index)
{
    int size = list_size(root);
    int_n *temp = root;
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
            int_n *iter = temp->next;
            temp->next = temp->next->next;
            free(iter);
        }
        else
        {
            root = root->next;
            free(temp);
        }
        return root;
    }
}

void list_push(int_n *root, int value)
{
    int_n *temp = root;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = (int_n *)malloc(sizeof(int_n));
    temp = temp->next;
    temp->data = value;
    temp->next = NULL;
}

int list_pop(int_n *root)
{
    int_n *temp = root;
    while (temp->next->next != NULL)
        temp = temp->next;
    int_n *iter = temp->next;
    int value = iter->data;
    free(iter);
    temp->next = NULL;
    return value;
}

void list_print(int_n *root)
{
    int_n *temp = root;
    if (root == NULL)
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

int_n *list_free(int_n *root)
{
    int_n *temp = root;
    int_n *iter = root;
    while (temp != NULL)
    {
        temp = temp->next;
        free(iter);
        iter = temp;
    }
    return NULL;
}
