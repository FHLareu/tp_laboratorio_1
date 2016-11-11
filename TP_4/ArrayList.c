#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
//#include "Estudiante.h"
#define VALOR_INICIAL 10
#define INCREMENTO 5

ArrayList* al_newArrayList(void)
{
    ArrayList* pList = (ArrayList*) malloc(sizeof(ArrayList));

    if(pList == NULL)
    {
        free(pList);
        return NULL;
    }

    pList->size = 0;
    pList->pElements = malloc(sizeof(void*)*VALOR_INICIAL);

    if(pList->pElements == NULL)
    {
        free(pList);
        return NULL;
    }

    pList->reservedSize = VALOR_INICIAL;

    pList->add = al_add;
    pList->len = al_len;
    pList->contains = al_contains;
    pList->set = al_set;
    pList->remove = al_remove;
    pList->clear = al_clear;
    pList->push = al_push;
    pList->indexOf = al_indexOf;
    pList->isEmpty = al_isEmpty;
    pList->get = al_get;
    pList->pop = al_pop;
    pList->containsAll = al_containsAll;
    pList->sort = al_sort;
    pList->clone = al_clone;
    pList->subList = al_subList;
    pList->deleteArrayList = al_deleteArrayList;

    return pList;
}

int al_add(ArrayList* pList , void* pElement)
{
    if(pList == NULL || pElement == NULL)
    {
        return -1;
    }

    if(pList->size == pList->reservedSize)
    {
        printf("Redimenzionando espacio en memoria.\n");
        system("pause");
        pList->pElements = realloc(pList , sizeof(void*) * (pList->reservedSize + INCREMENTO));
        pList->reservedSize += INCREMENTO;
    }

    *(pList->pElements + (pList->size)) = pElement;
    pList->size++;

    return 0;
}

int al_len(ArrayList* pList)
{
    if(pList == NULL)
    {
        return -1;
    }

    return pList->size;
}

int al_contains(ArrayList* pList , void* pElement)
{
    int i;

    if(pList == NULL || pElement == NULL)
    {
        return -1;
    }

    for(i=0 ; i<pList->size ; i++)
    {
        if(pElement == pList->pElements+i)
        {
            return 1;
        }
    }

    return 0;
}

int al_set(ArrayList* pList , void* pElement , int index)
{
    //index--;

    if(pList==NULL || pElement==NULL || index<0 || index>=pList->size)
    {
        return -1;
    }

    *(pList->pElements+index) = pElement;

    return 0;
}

int al_remove(ArrayList* pList , int index)
{
    int i;
    //index--;

    if(pList == NULL || index<0 || index>=pList->size)
    {
        return -1;
    }

    for(i=0 ; i<pList->reservedSize ; i++)
    {
        *(pList->pElements+index) = *(pList->pElements+(index+1));
        index++;
    }

    *(pList->pElements+(pList->size-1)) = NULL;

    pList->size--;

    return 0;
}

int al_clear(ArrayList* pList)
{
    if(pList == NULL)
    {
        return -1;
    }

    //free(pList->pElements);

    //pList->pElements = malloc(sizeof(void*) * VALOR_INICIAL);

    //pList->reservedSize = VALOR_INICIAL;
    pList->size = 0;

    return 0;
}

int al_push(ArrayList* pList , void* pElement , int index)
{
    int i, sizeAuxiliar;
    void* pAuxiliar;

    sizeAuxiliar = pList->size;

    if(pList != NULL && pElement != NULL && index>=0 && index<pList->size)
    {
        if(pList->size == pList->reservedSize)
        {
            pAuxiliar = malloc(sizeof(void*) * (pList->reservedSize+INCREMENTO));
            if(pAuxiliar != NULL)
            {
                pList->pElements = pAuxiliar;
            }
        }

        for(i=0 ; i<pList->reservedSize ; i++)
        {
            if(index-1 == sizeAuxiliar)
            {
                break;
            }

           *(pList->pElements+(sizeAuxiliar+1)) = *(pList->pElements+sizeAuxiliar);
            sizeAuxiliar--;
        }

        *(pList->pElements+index) = pElement;
        pList->size++;

        return 0;
    }

    return -1;
}

int al_indexOf(ArrayList* pList , void* pElement)
{
    int i;

    if(pList == NULL || pElement == NULL)
    {
        return -1;
    }

    for(i=0 ; i<pList->size ; i++)
    {
        if(pElement == pList->pElements+i)
        {
            return i;
        }
    }

    return 0;
}

int al_isEmpty(ArrayList* pList)
{
    if(pList == NULL)
    {
        return -1;
    }

    if(pList->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void* al_get(ArrayList* pList , int index)
{
    //index--;

    if(pList == NULL || index<0 || index>=pList->size)
    {
        return NULL;
    }

    return *(pList->pElements+index);
}

void* al_pop(ArrayList* pList , int index)
{
    //index--;
    void* pAuxiliar;

    if(pList == NULL || index<0 || index>=pList->size)
    {
        return NULL;
    }

    pAuxiliar = pList->pElements+index;

    *(pList->pElements+index) = NULL;
    pList->size--;

    return pAuxiliar;
}

int al_containsAll(ArrayList* pList , ArrayList* pList2)
{
    int i, contador=0;

    if(pList == NULL || pList2 == NULL)
    {
        return -1;
    }

    if(pList->len(pList) != pList2->len(pList2))
    {
        return 0;
    }

    for(i=0 ; i<pList->len(pList) ; i++)
    {
        if(pList->pElements+i == pList2->pElements+i)
        {
            contador++;
        }
    }

    if(contador == pList->len(pList))
    {
        return 1;
    }

    return 0;
}

int al_sort(ArrayList* pList , int (*pFunc)(void* , void*) , int order)
{
    return 1;
}

ArrayList* al_clone(ArrayList* pList)
{
    int i;
    void* pAuxiliar;

    if(pList != NULL)
    {

        ArrayList* pList2 = (ArrayList*) malloc(sizeof(ArrayList));

        if(pList2 != NULL)
        {
            pAuxiliar = malloc(sizeof(void*) * pList->reservedSize);

            if(pAuxiliar != NULL)
            {
                pList2->pElements = pAuxiliar;

                for(i=0 ; i<pList->size ; i++)
                {
                    *(pList2->pElements+i) = *(pList->pElements+i);
                }

                pList2->size = pList->size;
                pList2->reservedSize = pList->reservedSize;

                pList2->add = al_add;
                pList2->len = al_len;
                pList2->contains = al_contains;
                pList2->set = al_set;
                pList2->remove = al_remove;
                pList2->clear = al_clear;
                pList2->push = al_push;
                pList2->indexOf = al_indexOf;
                pList2->isEmpty = al_isEmpty;
                pList2->get = al_get;
                pList2->pop = al_pop;
                pList2->containsAll = al_containsAll;
                pList2->sort = al_sort;
                pList2->clone = al_clone;
                pList2->subList = al_subList;
                pList2->deleteArrayList = al_deleteArrayList;

                return pList2;
            }
        }
    }

    return NULL;
}

ArrayList* al_subList(ArrayList* pList , int from , int to)
{
    int i;
    int incremento=0;
    ArrayList* pList2;

    if(pList != NULL && from>=0 && from<pList->size && to>=0 && to<pList->size && from<to)
    {
        pList2 = (ArrayList*) malloc(sizeof(ArrayList));

            if(pList2 != NULL)
            {
                pList2->pElements = malloc(sizeof(void*) * pList->size);

                if(pList2->pElements != NULL)
                {
                    for(i=from ; i<to ; i++)
                    {
                       *(pList2->pElements+incremento) = *(pList->pElements+i);
                       incremento++;
                       printf("hola\n");
                    }

                    pList2->size = to - from;
                    pList2->reservedSize = pList->size;

                    pList2->add = al_add;
                    pList2->len = al_len;
                    pList2->contains = al_contains;
                    pList2->set = al_set;
                    pList2->remove = al_remove;
                    pList2->clear = al_clear;
                    pList2->push = al_push;
                    pList2->indexOf = al_indexOf;
                    pList2->isEmpty = al_isEmpty;
                    pList2->get = al_get;
                    pList2->pop = al_pop;
                    pList2->containsAll = al_containsAll;
                    pList2->sort = al_sort;
                    pList2->clone = al_clone;
                    pList2->subList = al_subList;
                    pList2->deleteArrayList = al_deleteArrayList;

                    return pList2;
                }
            }
    }

    else
    {
        return NULL;
    }
}

int al_deleteArrayList(ArrayList* pList)
{
    if(pList == NULL)
    {
        return -1;
    }

    free(pList);

    return 0;
}
