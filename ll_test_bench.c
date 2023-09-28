#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* next;
};

/*Function to swap the nodes */
struct node* swap(struct node* ptr1, struct node* ptr2)
{
	struct node *tamp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tamp;
	return ptr2;
}

/* Function to sort the list */
int bubbleSort(struct node** head, int count)
{
	struct node** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {

		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {

			struct node* p1 = *h;
			struct node* p2 = p1->next;

			if (p1->data > p2->data) {

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

/* Function to print the list */
void printList(struct node* n)
{
	while (n != NULL) {
		printf("%d -> ", n->data);
		n = n->next;
	}
	printf("\n");
}

/* Function to insert a struct node
at the beginning of a linked list */
void insertAtTheBegin(struct node** start_ref, int data)
{
	struct node* ptr1
		= (struct node*)malloc(sizeof(struct node));

	ptr1->data = data;
	ptr1->next = *start_ref;
	*start_ref = ptr1;
}

// Driver Code
int main()
{
	int arr[] = { 78, 20, 10, 32, 1, 5 };
	int list_size, i;

	/* start with empty linked list */
	struct node* start = NULL;
	list_size = sizeof(arr) / sizeof(arr[0]);

	/* Create linked list from the array arr[] */
	for (i = list_size - 1; i >= 0; i--)
		insertAtTheBegin(&start, arr[i]);

	/* print list before sorting */
	printf("Linked list before sorting\n");
	printList(start);

	/* sort the linked list */
	bubbleSort(&start, list_size);

	/* print list after sorting */
	printf("Linked list after sorting\n");
	printList(start);

	return 0;
}
