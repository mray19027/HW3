#include <assert.h>
#include <stdlib.h>

#include "list.h"

// typedef struct list_t {
// 	uint32_t index;
// 	struct list_t *next;
// } list_t;

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	list_t* temp = head;
	if(new_element->index < head->index) {
		new_element->next = head;
		return new_element;
	}
	while (temp->next!=NULL) {
		if (new_element->index < temp->next->index) {
			new_element->next = temp->next;
			temp->next = new_element;
			return head;
		}
		temp = temp->next;
	}
	temp->next = new_element;
	new_element->next = NULL;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* next_head;
	list_t* temp;
	next_head = head->next;
	int first_run = 1;
	while(next_head!=NULL) {
		temp = head;
		head = next_head;
		next_head = head->next;
		head->next = temp;
		if (first_run) {
			temp->next = NULL;
			first_run = 0;
		}
	}
	return head;
}

