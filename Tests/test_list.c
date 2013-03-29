#include <acknex.h>
#include "..\\Source\\tust.h"

int compare_int(int a, int b)
{
	return a - b;
}

function main()
{
	int array[3];
	array[0] = 4;
	array[1] = 5;
	array[2] = 6;
	
	List *list = list_create();
	
	list_add(list, 1);
	list_add(list, 2);
	list_add(list, 3);
	list_add(list, 3);
	list_add(list, 3);
	list_add(list, 4);	// Double 4 entry to remove one
	list_add_range(list, array, 3);
	
	list_remove_all(list, 3);	// Test multiple entries
	list_remove(list, 4);		// Test double entry
	list_remove(list, 1);		// Test first entry
	list_remove(list, 6);		// Test last entry
	
	list_remove_at(list, 1);	// Remove second entry (should be 4)
	
	if(list_contains(list, 4) != 0)
		error("Test failed at \"list_contains(list, 4)\"");
	if(list_contains(list, 5) == 0)
		error("Test failed at \"list_contains(list, 5)\"");
	if(list_item_at(list, 0) != 2)
		error("Test failed at \"list_item_at(list, 0)\"");

	list_clear(list);
	
	list_add(list, 1);
	list_add(list, 3);
	list_add(list, 5);
	list_add(list, 6);
	list_add(list, 4);
	list_add(list, 2);
	
	list_sort(list, compare_int);
	
	list_reverse(list);


	error("List Iteration:");
	int value;
	ListIterator *it = list_begin_iterate(list);
	for(value = list_iterate(it); it->hasNext; value = list_iterate(it))
	{
		error(str_for_int(NULL, value));
	} 
	list_end_iterate(it);
	
	error("Count:");
	error(str_for_int(NULL, list_get_count(list)));
	
	error("Copy test...");
	list_copy_to(list, array, 3);
	error(str_for_int(NULL, array[0]));
	error(str_for_int(NULL, array[1]));
	error(str_for_int(NULL, array[2]));
	
	
	
	list_delete(list);
}




















