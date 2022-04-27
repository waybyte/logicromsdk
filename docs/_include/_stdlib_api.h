/**
 * @brief Allocate memory
 * 
 * @param size size in bytes
 * @return on success a pointer to newly allocated memory, NULL on error
 */
void *malloc(size_t size);

/**
 * @brief Release an allocated memory
 * 
 * @param ptr pointer to memory
 */
void free(void *ptr);

/**
 * @brief allocates memory for an array of @a nmemb elements of @a size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 * 
 * @param nmemb number of element
 * @param size element size
 * @return on success a pointer to newly allocated memory, NULL on error
 */
void *calloc(size_t nmemb, size_t size);

/**
 * @brief changes the size of the memory block pointed to by @a ptr to @a size bytes
 * 
 * @param ptr pointer to previously allocated memory
 * @param size new size
 * @return on success a pointer to newly allocated memory, NULL on error
 */
void *realloc(void *ptr, size_t size);
