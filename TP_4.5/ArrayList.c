#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#define VALOR_INICIAL 2
#define INCREMENTO 2

ArrayList* al_newArrayList(void)
{
    ArrayList* pList = (ArrayList*) malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pList->pElements = malloc(sizeof(void*)*VALOR_INICIAL);

        if(pList->pElements != NULL)
        {
            pList->size = 0;
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
    }

    free(pList);

    return NULL;
}

int al_add(ArrayList* pList , void* pElement)
{
    int retorno=-1, espacioLibre=1;

    if(pList!=NULL && pElement!=NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            if(resizeUp(pList) != 0)
            {
                printf("No se a podido redimenzionar memoria.\n");
                espacioLibre = 0;
            }
        }

        if(espacioLibre != 0)
        {
            *(pList->pElements + (pList->size)) = pElement;
            pList->size++;

            retorno = 0;
        }
    }

    return retorno;
}

int al_len(ArrayList* pList)
{
    int retorno=-1;

    if(pList != NULL)
    {
        retorno = pList->size;
    }

    return retorno;
}

int al_contains(ArrayList* pList , void* pElement)
{
    int i, retorno=-1;

    if(pList!=NULL && pElement!=NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            if(pElement == *(pList->pElements+i))
            {
                retorno = 1;
                break;
            }
        }

        if(retorno != 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int al_set(ArrayList* pList , void* pElement , int index)
{
    int retorno=-1;

    if(pList!=NULL && pElement!=NULL && index>=0 && index<pList->size)
    {
        *(pList->pElements+index) = pElement;
        retorno = 0;
    }

    return retorno;
}

int al_remove(ArrayList* pList , int index)
{
    int retorno=-1;

    if(pList!=NULL && index>=0 && index<pList->size)
    {
        if(contract(pList , index) != -1)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int al_clear(ArrayList* pList)
{
    int retorno=-1;

    if(pList != NULL)
    {
        free(pList->pElements);

        pList->pElements = malloc(sizeof(void*) * VALOR_INICIAL);

        pList->reservedSize = VALOR_INICIAL;
        pList->size = 0;

        retorno = 0;
    }

    return retorno;
}

int al_push(ArrayList* pList , void* pElement , int index)
{
    int i, sizeAuxiliar, espacioLibre=1, retorno=-1;

    sizeAuxiliar = pList->size;

    if(pList != NULL && pElement != NULL && index>=0 && index<pList->size)
    {
        if(pList->size == pList->reservedSize)
        {
            if(resizeUp(pList) != 0)
            {
                printf("No se a podido redimenzionar memoria.\n");
                espacioLibre = 0;
            }
        }

        if(espacioLibre != 0)
        {
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

        retorno = 0;

        }
    }

    return retorno;
}

int al_indexOf(ArrayList* pList , void* pElement)
{
    int i, retorno=-1, encontrado=0;

    if(pList!=NULL && pElement!= NULL)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            if(*(pList->pElements+i) == pElement)
            {
                retorno = i;
                encontrado = 1;
            }
        }
        if(encontrado != 1)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int al_isEmpty(ArrayList* pList)
{
    int retorno=-1;

    if(pList != NULL)
    {
        if(pList->size == 0)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

void* al_get(ArrayList* pList , int index)
{
    if(pList!=NULL && index>=0 && index<pList->size)
    {
        return *(pList->pElements+index);
    }
    else
    {
        return NULL;
    }
}

void* al_pop(ArrayList* pList , int index)
{
    void* pAuxiliar;

    if(pList!=NULL && index>=0 && index<pList->size)
    {
        pAuxiliar = pList->pElements+index;

        contract(pList , index);

        return pAuxiliar;
    }

    return NULL;
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
    int i, j, retorno=-1;
    void* pAuxiliar;

    if(pList!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        if(order)
        {
            for(i=0 ; i<pList->size-1 ; i++)
            {
                for(j=i+1 ; j<pList->size ; j++)
                {
                    if(pFunc(al_get(pList , i) , al_get(pList , j)))
                    {
                        pAuxiliar = *(pList->pElements+i);
                        *(pList->pElements+i) = *(pList->pElements+j);
                        *(pList->pElements+j) = pAuxiliar;

                        retorno = 1;
                    }
                }
            }
        }
        else
        {
            for(i=0 ; i<pList->size-1 ; i++)
            {
                for(j=i+1 ; j<pList->size ; j++)
                {
                    if(!pFunc(al_get(pList , i) , al_get(pList , j)))
                    {
                        pAuxiliar = *(pList->pElements+i);
                        *(pList->pElements+i) = *(pList->pElements+j);
                        *(pList->pElements+j) = pAuxiliar;

                        retorno = 1;
                    }
                }
            }
        }
    }

    return retorno;
}

ArrayList* al_clone(ArrayList* pList)
{
    int i;

    if(pList != NULL)
    {
        ArrayList* pList2 = al_newArrayList();

        if(pList2 != NULL)
        {
            pList2->pElements = malloc(sizeof(void*) * pList->reservedSize);

            if(pList2->pElements != NULL)
            {
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
        ArrayList* pList2 = al_newArrayList();

            if(pList2 != NULL)
            {
                pList2->pElements = malloc(sizeof(void*) * pList->size);

                if(pList2->pElements != NULL)
                {
                    for(i=from ; i<to ; i++)
                    {
                       *(pList2->pElements+incremento) = *(pList->pElements+i);
                       incremento++;
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
    int retorno=-1;

    if(pList != NULL)
    {
        free(pList);

        retorno = 0;
    }

    return retorno;
}

int resizeUp(ArrayList* pList)
{
    int retorno=-1;
    void** pAuxiliar;

    if(pList != NULL)
    {
        printf("Redimencionando espacio en memoria.\n");
        system("pause");
        pAuxiliar = realloc(pList->pElements , sizeof(void*) * (pList->reservedSize+INCREMENTO)); //Preguntar por el primer parametro. Tener en cuanta que el primer parametro es un puntero de aquello que quiero redimensionar

        if(pAuxiliar != NULL)
        {
            pList->pElements = pAuxiliar;
            pList->reservedSize += INCREMENTO;

            retorno = 0;
        }
    }

    return retorno;
}

int contract(ArrayList* pList , int index)
{
    int i, retorno=-1;

    if(pList!=NULL && index>=0 && index<pList->size)
    {
        for(i=0 ; i<pList->size ; i++)
        {
            *(pList->pElements+index) = *(pList->pElements+(index+1));
            index++;
        }

        pList->size--;

        retorno = 0;
    }

    return retorno;
}


