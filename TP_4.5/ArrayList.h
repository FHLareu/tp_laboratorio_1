#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

typedef struct
{
    int size;
    void **pElements;
    int reservedSize;

    int (*add)();
    int (*len)();
    int (*contains)();
    int (*set)();
    int (*remove)();
    int (*clear)();
    int (*push)();
    int (*indexOf)();
    int (*isEmpty)();
    void* (*get)();
    void* (*pop)();
    int (*containsAll)();
    int (*sort)();
    struct ArrayList* (*clone)();
    struct ArrayList* (*subList)();
    int (*deleteArrayList)();
}ArrayList;

/** \brief Crea e inicializa un nuevo ArrayList.
 * \param Vacio (void).
 * \return Retorna un puntero al nuevo ArrayList (ArrayList*) u nulo (NULL) en caso de error (no se pudo reservar espacio en memoria).
 */
ArrayList* al_newArrayList(void);

/** \brief Añade un elemento al ArrayList y lo redimensiona en caso de que sea necesario.
 * \param Un puntero al ArrayList (ArrayList*).
 * \param Un puntero al elemento (void*).
 * \return Retorna un entero (-1) en caso de error (el puntero al ArrayList o al elemento apuntan a nulo) o (0) si todo esta correcto.
 */
int al_add(ArrayList* , void*);

/** \brief Retorna el tamaño del ArrayList.
 * \param Un puntero al ArrayList (ArrayList*).
 * \return Retorna un entero (-1) en caso de error (el puntero al ArrayList apunta a nulo) o la longitud del Array si todo esta correcto.
 */
int al_len(ArrayList*);

/** \brief Comprueba si existe el elemento que se le pasa como parámetro.
 * \param Un puntero al ArrayList (ArrayList*).
 * \param Un puntero al elemento (void*).
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist o al elemento apuntan a nulo), (1) si se encontro el elemento o (0) si no.
 */
int al_contains(ArrayList* , void*);

/** \brief Inserta un elemento en el ArrayList, en el índice especificado.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al elemento (void*).
 * \param Un entero.
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist o al elemento apuntan a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o (0) si todo esta correcto.
 */
int al_set(ArrayList* , void* , int);

/** \brief Elimina un elemento del ArrayList, en el índice especificado.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un entero.
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist apunta a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o (0) si todo esta correcto.
 */
int al_remove(ArrayList* , int);

/** \brief Elimina todos los elementos del Arraylist.
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist apunta a nulo) o (0) si todo esta correcto.
 */
int al_clear(ArrayList*);

/** \brief Añade un elemento al ArrayList en el indice especificado y desplaza los demas elementos.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al elemento (void*).
 * \param Un entero.
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist o al elemento apuntan a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o (0) si todo esta correcto.
 */
int al_push(ArrayList* , void* , int);

/** \brief Retorna el índice de la primera aparición de un elemento en el ArrayList.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al elemento (void*).
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist o al elemento apuntan a nulo) o el indice del elemento si todo esta correcto.
 */
int al_indexOf(ArrayList* , void*);

/** \brief Verifica la existencia de elementos en el Arraylist.
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist apunta a nulo), (1) si el Arraylis esta vacio o (0) si contiene elementos.
 */
int al_isEmpty(ArrayList*);

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un entero.
 * \return Retorna un entero nulo (NULL) en caso de error (el puntero al Arraylist apunta a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o el puntero al elemento si todo esta correcto.
 */
void* al_get(ArrayList* , int);

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un entero.
 * \return Retorna un entero nulo (NULL) en caso de error (el puntero al Arraylist apunta a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o el puntero al elemento si todo esta correcto.
 */
void* al_pop(ArrayList* , int);

/** \brief Comprueba si los elementos pasados son contenidos por el ArrayList.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna nulo (NULL) en caso de error (el puntero al Arraylist apunta a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o el puntero al elemento si todo esta correcto.
 */
int al_containsAll(ArrayList* , ArrayList*);

/** \brief Ordena los elementos del ArrayList.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero a una funcion.
 * \param Un entero.
 * \return Retorna (-1) en caso de error (el puntero al Arraylist o a la funcion apuntan a nulo) o (1) si todo esta correcto.
 */
int al_sort(ArrayList* , int (*pFunc)(void* , void*) , int);

/** \brief Copia un ArrayList.
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna nulo (NULL) en caso de error (el puntero al Arraylist apunta a nulo) o el puntero del nuevo Arraylist si todo esta correcto.
 */
ArrayList* al_clone(ArrayList*);

/** \brief Crea un nuevo ArrayList, producto de un subconjunto de elementos del Arraylist original.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un entero.
 * \param Un entero.
 * \return Retorna nulo (NULL) en caso de error (el puntero al Arraylist apunta a nulo o alguno de los enteros es menor a cero o mayor al tamaño del Arraylist) o el puntero del nuevo Arraylist si todo esta correcto.
 */
ArrayList* al_subList(ArrayList* , int , int);

/** \brief Elimina el ArrayList.
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna (-1) en caso de error (el puntero al Arraylist apunta a nulo), (1) si esta vacio o (0) si contiene elementos.
 */
int al_deleteArrayList(ArrayList*);

/** \brief Incrementa la cantidad maxima de elementos del ArrayList en INCREMENTO elementos.
 * \param Un puntero al Arraylist (Arraylist*).
 * \return Retorna (-1) en caso de error (el puntero al Arraylist apunta a nulo o no se pudo reservar memoria) o (0) si todo esta correcto.
 */
int resizeUp(ArrayList*);

/** \brief  Contrae los elementos del ArrayList hasta el index especificado
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un entero.
 * \return Retorna un entero (-1) en caso de error (el puntero al Arraylist apunta a nulo o el index es menor a cero o mayor al tamaño del Arraylist) o (0) si todo esta correcto.
 */
int contract(ArrayList* , int);

#endif
