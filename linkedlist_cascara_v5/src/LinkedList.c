#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
   int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;// pnode es null solo cuando arranca
    int indexNodoActual=0;
    pNode=this->pFirstNode;

    for(indexNodoActual=0;indexNodoActual<nodeIndex;indexNodoActual++)
    {
        if(pNode!=NULL)
        {
            pNode=pNode->pNextNode;
        }
    }

    /*
    while(1)
    {
    //aca pnode coincide con el nodo actual
    if(indexNodoActual==nodoINdex)
        break;

        pNode=pNode->pNextNode;
        indexNodoActual++;
    }
*/
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && nodeIndex>=0 && nodeIndex>=this->size)//nodeindex >= al size de this(linkedlist)
    {
        Node* newNode;
        Node* nodeA;
        newNode=(Node*)malloc(sizeof(Node));
        newNode->pElement=pElement;

        if(nodeIndex==0) // si agrego en 0, agrago el primero
        {
            newNode->pNextNode=this->pFirstNode;
    //entiendo que nuevonodo que apunta a nextnodo = al primernodeo de this(listalinkedlist)
            this->pFirstNode=newNode;
    //this que apunta a primernodo = neuevonodo
            this->size++;
    //au,mento tamaño de la lista
            returnAux=0;
        }
        if(nodeIndex>0) // sumo a lago que ya existe
        {
            nodeA=getNode(this,nodeIndex-1);//nodeINdex-1 ¿nopuedo agregar en el ultimo ?
            newNode->pNextNode=nodeA->pNextNode;
    //nuevonodo que apunta a proximonodo=nodoa (que agrego)que apunta a proximonodo
            nodeA->pNextNode=newNode;
    //nodo a en nuevonodo=nuevonodo
            this->size++;
    //aumento amaño de this (lista linkedlist)
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* node = malloc(sizeof(Node));
    if(this != NULL && pElement != NULL && node != NULL)//tooodo !=NULL
    {
        returnAux = 0;
        node->pElement = pElement;
        node->pNextNode = NULL;

        Node* auxNode = this->pFirstNode;
        while(auxNode->pNextNode != NULL)
        {
            auxNode = auxNode->pNextNode;
        }
        auxNode->pNextNode = node;
        this->size++;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this!=NULL && index>=0 && index<=this->size)//valido - !que index sea menor al size de la lista
        {
            pNode=getNode(this,index); // llamo a fc getnode
            if(pNode!=NULL)
            {
                returnAux=pNode->pElement; //retorna pnode que apunta a pelement
            }
        }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this!=NULL && index>=0 && index<=this->size) // que el index sea menor o igual al size de this(lista linkedlist)
    {
        pNode=getNode(this,index); //llamo a la fc get node
        returnAux=0;
        if(pNode!=NULL)
        {
            pNode->pElement=pElement; // pnode que apunta a pelemento = pelemento
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode1;
    Node* pNode2;
    if(this!=NULL && index>=0 && index<=this->size)
    {
        if(this->size==1)// si el size es de un solo elemento
        {
            this->pFirstNode=NULL;// no nextnodes
            pNode1=getNode(this,index);
            free(pNode1);
            this->size--;
        }
        if(this->size>1)
        {
            pNode1=getNode(this,index);
            if(pNode1!=NULL)
            {
                pNode2=getNode(this,index-1);//INDEX -1!!!!!!!!!!!
                pNode2->pNextNode=pNode1->pNextNode;
                //1 EN 2 Y ELIMINO1?
                free(pNode1);
                this->size--;
            }
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* pNode1;
    Node* pNode2;
    int i;
    if(this!=NULL) // this no es null
    {
        if(!this->size) // sin contenido
        {
            returnAux=0;

        }
        else // si tiene elementos
        {
        for(i=0;i<this->size;i++)
        {
            /*pNode1=getNode(this,i); // fc get node
            if(pNode1!=NULL) // si nodo1 contiene
            {
                pNode2=pNode1->pNextNode;// en n2 pongo n1
                free(pNode1); //libero n1
            }
*/
            ll_remove(this,i);
            returnAux=0;
        }
            //free(pNode2); //libero n2
            //returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this); //
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) // elemento de un nodo de linkedlist
{
    int returnAux = -1;
    Node* pNode;
    int i;

    for(i=0;i<this->size;i++)// que i sea menor al size de this
    {
        pNode=getNode(this,i); // llamo a getNOde
        if(pNode!=NULL && pNode->pElement==pElement)
        //valido q nodo no sea null y que pelement en nodo sea igual a pelement
        {
            returnAux=i; // retorno la posicion
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    //int lenght=ll_len(this);
    if(this!=NULL)
    {
        if(this->size==0) //if(lenght==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) // trabaja en la lista
{
    int returnAux = -1;
        if(this!=NULL && index>=0 && index<=this->size)
        {
            if(addNode(this,index,pElement)==0)//
            {
                        returnAux=0;

            }
        }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<this->size)
    // valido lista distinta a null indexmas o=0 indice menor al indice de la lista
    {
        returnAux=ll_get(this,index);//llamo a fc get de la lista
        ll_remove(this,index);// llamo a fc remove de la lista
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int i;
    int lenghtThis2=ll_len(this2);// saco el largo de mi segunda lista
    if(this!=NULL && lenghtThis2!=NULL)// que lista y lista 2 sean distintas de null
    {

        if(this->size==this2->size)//
        {
            returnAux=1;

        }
        else
            for(i=0; i<lenghtThis2; i++)
            {
                pElement=ll_get(this2,i);// toma el elemento en lista 2
                if(!ll_contains(this,pElement));// ve que el elem est en lista1
                {
                    returnAux=0;
                    break;
                }
            }
        }
    }
   return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;


    if(this!=NULL && from<=0 && from<to && to<=this->size)
    //que la lista no sea null, que DESDE sea mayor o = 0, que DESDE sea menor que HACIA DONDE,
    //que HACIA DONDE
    {

    }



    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

// la funcion que pasas desde adentro le tenes que pasar los ELEMENTOS no LOS NODOS
// no sabe que existen los nodos, trabaja con los ELEMENTOS!!!!
