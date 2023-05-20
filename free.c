#include "shell.h"
/**
 * free_arr - free array
 *   * @array: array
 *    */
void free_arr(char **array)
{
	 size_t i;

	  for (i = 0; array[i] != NULL; i++)
		   {
			     free(array[i]);
			      }
	   free(array);
}
