#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "LinkedList.h"

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
    //au,mento tama�o de la lista
            returnAux=0;
        }
        if(nodeIndex>0) // sumo a lago que ya existe
        {
            nodeA=getNode(this,nodeIndex-1);//nodeINdex-1 �nopuedo agregar en el ultimo ?
            newNode->pNextNode=nodeA->pNextNode;
    //nuevonodo que apunta a proximonodo=nodoa (que agrego)que apunta a proximonodo
            nodeA->pNextNode=newNode;
    //nodo a en nuevonodo=nuevonodo
            this->size++;
    //aumento ama�o de this (lista linkedlist)
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
    //o mejor int lenght=ll_len(this);
    //if(this!=NULL && addNode(this,lenght,pElement)==0)
    //{ returnAux=0;}
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
    //int size=ll_len(this)
    //if(this != NULL && index >=0 && index<size
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
    //int size =ll_len(this)
    if(this!=NULL && index>=0 && index<=this->size) // que el index sea menor o igual al size de this(lista linkedlist)
    {
        pNode=getNode(this,index); //llamo a la fc get node
        if(pNode!=NULL)
        {
            pNode->pElement=pElement; // pnode que apunta a pelemento = pelemento
            returnAux=0;
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
    //int size=ll_len(this)
    // index<size
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
    //int size=ll_len(this)
    //&&index<=size

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
    int i;
    if(this!=NULL)
    {
        if(pElement!=NULL)
        {
            for(i=0; i<this->size;i++)
            {
                if(this->pElement[i]==pElement)
                {
                    returnAux=1;
                    break;
                }
                else
                {
                    returnAux=0;

                }
            }
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
    int i;
    void* pAux;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for(i=0;i<ll_len(this2);i++)
        {
            pAux=ll_get(this2,i);
            if(ll_contains(this,pAux))
            {
                returnAux=0;
                break;
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
    LinkedList* newList = NULL;
    void* pElement;
    int i;

    if(this!=NULL && from>=0 && from<(this->size) && to>=0 && to<=(this->size) && from<to)
    {
        newList=ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pElement=ll_get(this,i);
            ll_add(newList,this->pElement[i]);
        }
    }
    return newList;
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
    int i;
    int cloneListSize=ll_len(this);

    if(this!=NULL)
    {
        if(this->size>0)
        {
            cloneArray=malloc(sizeof(LinkedList));
            if(cloneArray!=NULL)
            {
                for(i=0;i<cloneListSize;i++)
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
            }
        }
    }
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
    Node* pNode;
    Node* pNxtNode;
    int i;
    int flagSwap=0;
    int lenght=ll_len(this);
    int returnValue;
    int auxiliar;

    if(this!=NULL && lenght>0 && pFunc!=NULL && (order==0 || order==1))
    {
        pNode=this->FirstNode;
        if(pNode!=NULL)
        {
            pNxtNode=Node->pNextNode;
            for(i=0; i<(lenght-1);i++)
            {
                if ((pFunc((pNode->pElement,pNxtNode->pElement)==1 && order) ||
                    (pFunc(pNode->pElement,pNxtNode->pElement)==-1) && !order))
                {
                    auxiliar=pNode->pElement;
                    pNode->pElement=pNxtNode->pElement;
                    pNxtNode->pElement=auxiliar;
                    flagSwap=1;
                }
                if(pNode->pNextNode!=NULL)//pNxtNode->
                {
                    pNode=pNxtNode;
                }
                else
                {
                    pNextNode=pNode->pNextNode;

                }
            }
        }while(flagSwap);
        returnAux=0;
    }
    return returnAux;

}

// la funcion que pasas desde adentro le tenes que pasar los ELEMENTOS no LOS NODOS
// no sabe que existen los nodos, trabaja con los ELEMENTOS

/** \brief devuelve el puntero al primer nodo de la lista
 * \param pList LinkedList* Puntero a la lista
 * \return void*, null si vacia o no existe
 */

void* ll_startIter(LinkedList* this)
{
    if(this!= NULL)
    {
        this->pNodeIter=this->pFirstNode;
        return this->pNodeIter;
    }
    return NULL;
}

/** \brief devuelve el puntero al prioximo nodo de la lista
 * \param pList LinkedList* Puntero a la lista
 * \return void* Retorna NULL si no hay mas nodos en lista o no existe la lista
 */

void* ll_getNextNode(LinkedList* this)
{
    Node* nodeAux=NULL;
    nodeAux=this->pIterNode;
    if(this->pIterNode!=NULL)
    {
        this->pIterNode=this->pIterNode->pNextNode;
    }
    return nodeAux;
}

/** \brief recorre la lista pasada por parametros y le pasa los elementos a una funcion
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc* puntero a FUNCION
 * \return void
 */
void mapping(LinkedList* this,void(*pFunc)(void*))
{
    Node* pNode;
    if(this!= NULL && pFunc != NULL)
    {
        pNode=startIter(this);
        if(pNode!=NULL)
        {
            do
                {
                    pFunc(pNode->pElement);
                    pNode=nextNodeIter(this);
                }
            while(pNode!=NULL);
        }
    }
}
/** \brief pasa lislta por fc y contabiliza
 * \param pLista
 * \param pFc
 * \return cantidad acumulada
 *
 */

LinkedList* ll_count(LinkedList* this, int(*pFunc)(void*))
{
    void* pElement;
    Node* this1;//pNode
    int contador=0;

    //valido
    if(this!=NULL && pFunc!=NULL)//ni list ni fc son null
    {
        ll_startIter(this);//fc en reemplazo del for
        do
        {
            this1=ll_getNextNode(this);//si el proximonodo es !=de null
            if(this1==NULL)
            {
                break;
            }
            pElement=this1->pElement;
            if(pFunc(pElement)==1)
            {
                contador++;
            }
        }(this1!=NULL)

    }
    return contador;
}
