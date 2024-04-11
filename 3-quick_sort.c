#include "sort.h"

/**
 * swap - Echange les valeurs de deux éléments d'un tableau.
 * @a: le premier élément
 * @b: le second élément
 * Return: rien.
 */
void swap(int *a, int *b)
{   
    int tmp; 
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition - Partitionne le tableau
 * @array: tableau à travailler
 * @low: l'indice de départ
 * @high: l'indice de fin
 * @size: la taille du tableau
 * Return: l'indice du pivot
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = (low - 1);
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;            
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    
    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    
    return (i + 1);
}

/**
 * quick_sort_rec - Fonction récursive pour appliquer le tri rapide.
 * @array: le tableau
 * @low: l'indice de départ
 * @high: l'indice de fin
 * @size: taille du tableau
 * Return: rien.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
    int i;

    if (low < high)
    {
        i = partition(array, low, high, size);
        quick_sort_rec(array, low, i - 1, size);
        quick_sort_rec(array, i + 1, high, size);
    }
}

/**
 * quick_sort - Trie un tableau d'entiers ordre croissant.
 * @array: le tableau
 * @size: taille du tableau
 * Return: rien.
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_rec(array, 0, size - 1, size);
}