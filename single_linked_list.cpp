#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;        //Data of the node
	struct node *next_ptr;   //Adress of next node
};

struct node *start_node;

static void creating_node_list(int total_node);
static void displaying_list();


int main(){
	int number_of_nodes;
	printf("Enter the number of nodes :");
	scanf("%d",&number_of_nodes);
	
	creating_node_list(number_of_nodes);     //Calling creating nodes function
	
	printf("Data entered in the list :\n");
	
	displaying_list();
	
	return 0;
}


static void creating_node_list(int total_nodes)
{
	struct node *new_node;   
	struct node *node_buffer;  //Vaaible for temporary data
	int node_data;     //Variable for holding user input
	int node_counter;   //Variable for counting nodes
	
	start_node = (struct node*)malloc(sizeof(struct node));   //Allocating memory for starting node
	
	if (start_node == NULL)
	{
		printf("Memory can't be allocated.");
	} 
	else
	{
		printf("Input data for node 1: ");
		scanf("%d",&node_data);
		
		start_node->data = node_data;      //Saving user input to the data element of the node.
		start_node->next_ptr = NULL;      //Initializing the node's next pointer to NULL
		
		node_buffer=start_node;     //Point the buffer to the first address of the node
		
		for(node_counter = 2;node_counter <= total_nodes;node_counter++)   //A loop to fill the rest of nodes
		{
			new_node = (struct node*)malloc(sizeof(struct node));    //Allocating memory for new node
			
			if(new_node == NULL)
			{
				printf("Memory can not be allocated .");
				break;
			}
			else
			{
				printf("Input data for node %d: ",node_counter);
				scanf("%d",&node_data);
				
				new_node->data = node_data;       //Saving user input to the data element of the ne node.
				new_node->next_ptr = NULL;      //Initializing the node's next pointer to NULL
				
				node_buffer->next_ptr = new_node;    //Link the old node to the current node
				node_buffer = node_buffer->next_ptr;  //copining the address of the current node
			}
		}
	}
}

static void displaying_list()     //A function to display the lists
{
	struct node *node_buffer;  //Declaring a temporary pointer to the node
	node_buffer = start_node;
	
	if (node_buffer == NULL)    //Check if the list is empty
	{
		printf("List is empty .");
	}
	else
	{
		while(node_buffer != NULL)   //Check if the node is empty
		{
			printf("Data = %d\n",node_buffer->data);
			
			node_buffer = node_buffer->next_ptr;
		}
	}
}






