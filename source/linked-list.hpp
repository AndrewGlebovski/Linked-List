/**
 * \file
 * \brief Linked Node module header
*/


typedef enum {
    INVALID_ARG  =  1,       ///< Function get invalid argument
    ALLOC_FAIL   =  8,       ///< Failed to allocate memory
} ERROR_CODES;


/// Contains all information about element
struct Node {
    int data = 0;                   ///< element value
    Node *next = nullptr;           ///< next element pointer
    Node *prev = nullptr;           ///< previous element pointer
};


/**
 * \brief Allocates memory for Node
 * \return Pointer to node or nullptr
*/
Node *create_node(void);


/**
 * \brief Inserts element in list
 * \param [out] list Allocated list
 * \param [in]  ptr New element will be inserted after this one
 * \param [in]  value New element will store this value
 * \return Non zero value means error
*/
int insert(Node *node, int value);


/**
 * \brief Removes element from list
 * \param [out] list Allocated list
 * \param [in]  index Actual index in buffer
 * \return Non zero value means error
*/
int remove(Node *node);


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
 * \brief Gets pointer to Node
 * \param [out] list Allocated list
 * \param [in]  index Element index in logical order
 * \return Pointer to the element
*/
Node *get_node(Node *list, int index);


/**
 * \brief Gets list size
 * \param [out] list Allocated list
 * \return List size
*/
int get_size(Node *list);
