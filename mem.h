typedef struct Node
{	int info;
	int memory;	
	int status;
	struct Node* next;
	struct Node* prev;

}node;

int total;
int freememnow;
node* freeptr;
node* head;
int count;

void initialize(int );
void allocate(int);
void map(void);
void freemem(int);
//node* initialize(node* head, int mem);
