/**
 * \file
 * \brief Linked Node module header
*/


typedef enum {
    INVALID_ARG  =  1,       ///< Function get invalid argument
    INVALID_PTR  =  2,       ///< Function get invalid pointer
    NULL_BUFFER  =  3,       ///< Node has null buffer
    INV_NEXT_ID  =  4,       ///< Element next index is wrong
    INV_PREV_ID  =  5,       ///< Element previous index is wrong
    ITER_FAIL    =  6,       ///< Logical list iteration end before tail
    RECURSIVE_ID =  7,       ///< Infinite iteration
    ALLOC_FAIL   =  8,       ///< Failed to allocate memory
    REALLOC_FAIL =  9,       ///< Failed to reallocate memory
    INV_FREE     = 10,       ///< Free element has prev = -1
    SECOND_CHECK = 11,       ///< Function second returns error
} ERROR_CODES;


/// Contains all information about element
struct Node {
    int data = 0;                  ///< element value
    Node *next = nullptr;           ///< next element pointer
    Node *prev = nullptr;           ///< previous element pointer
};


/**
 * \brief List constructor
 * \param [out] list Not allocated or free list
 * \param [in]  size Specifies buffer size
 * \return Non zero value means error
*/
int construct(Node *list);


/**
 * \brief Inserts element in list
 * \param [out] list Allocated list
 * \param [in]  ptr New element will be inserted after this one
 * \param [in]  value New element will store this value
 * \return Pointer to the new element. Please, store it to improve perfomance of your program
*/
[[nodiscard]] Node *insert(Node *ptr, int value);


/**
 * \brief Removes element from list
 * \param [out] list Allocated list
 * \param [in]  index Actual index in buffer
 * \return Non zero value means error
*/
int remove(Node *ptr);


/**
 * \brief Node descructor
 * \param [out] list Allocated list
 * \return Non zero value means error
*/
int destruct(Node *list);


/**
 * \brief Prints list info
 * \param [in] list Allocated list
 * \param [in] output Output file 
 * \return Non zero value means error
*/
int dump(Node *list, FILE *output);


/**
 * \brief Checks list for mistakes
 * \param [in] list Allocated list
 * \return Non zero value means error
*/
int verifier(Node *list);


/**
 * \brief Gets element real index in buffer
 * \param [out] list Allocated list
 * \param [in]  logical_index Element index in logical order
 * \return Pointer to the element
*/
Node *get_node(Node *list, int logical_index);


/**
 * \brief Pushes value to list front
 * \param [out] list Allocated list
 * \param [in]  value New element will store this value
 * \return Pointer to the new element. Please, store it to improve perfomance of your program
*/
[[nodiscard]] Node *push_front(Node *list, int value);


/**
 * \brief Pushes value to list back
 * \param [out] list Allocated list
 * \param [in]  value New element will store this value
 * \return Pointer to the new element. Please, store it to improve perfomance of your program
*/
[[nodiscard]] Node *push_back(Node *list, int value);


/**
 * \brief Removes front element from list
 * \param [out] list Allocated list
 * \return Non zero value means error
*/
int pop_front(Node *list);


/**
 * \brief Removes back element from list
 * \param [out] list Allocated list
 * \return Non zero value means error
*/
int pop_back(Node *list);
