/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#include "../include/my.h"

node_t *get_from_ptr(void *addr)
{
    if (node == NULL || addr == NULL)
        return NULL;
    for (node_t *curr = node; curr; curr = curr->next)
        if (curr->addr == addr)
            return curr;
    return NULL;
}

void *find_best_chunk(size_t size)
{
    node_t *curr = NULL;
    node_t *tmp = NULL;

    if (!node)
        return NULL;
    for (curr = node; curr; curr = curr->next)
        if (tmp && curr->taken == false && curr->size >= size &&\
            tmp->size < curr->size);
        else if (curr->taken == false && curr->size >= size)
            tmp = curr;
    if (tmp && tmp->addr) {
        tmp->taken = true;
        tmp->size = size;
        return tmp->addr;
    }
    return NULL;
}

void *give_space(size_t size)
{
    void *tmp = NULL;

    for (int i = 0; i * getpagesize() < size; i++) {
        tmp = sbrk(getpagesize());
        if (tmp == (void *)-1)
            return NULL;
    }
    tmp = sbrk(getpagesize());
    if (tmp == (void *)-1)
        return NULL;
    return tmp;
}

void *add_in_list(size_t size)
{
    node_t *curr = NULL;
    node_t *newblock = NULL;
    newblock = sbrk(getpagesize());
    if (newblock == (void *)-1)
        return NULL;
    newblock->addr = newblock + sizeof(node_t);
    newblock->taken = true;
    newblock->size = size;
    newblock->next = NULL;
    if (give_space(size) == NULL)
        return NULL;
    if (node) {
        for (curr = node; curr->next != NULL; curr = curr->next);
        curr->next = newblock;
    } else
        node = newblock;
    return newblock->addr;
}
