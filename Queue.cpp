//Here is a queue I found online
//Should Work for implementing BFS

struct node {
	int info;
	node *next;
};

	class Queue {
		private:
		node *front;
		node *rear;
		public:
			Queue();
			~Queue();
			bool isEmpty();
			void enqueue(int);
			int dequeue();
			void display();

	};

void Queue::display(){
	node *p = new node;
	p = front;
	if(front == NULL){
		cout<<"\nNothing to Display\n";
	}else{
		while(p!=NULL){
			cout<<endl<<p->info;
			p = p->next;
		}
	}
}

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	delete front;
}

void Queue::enqueue(int data) {
	node *temp = new node();
	temp->info = data;
	temp->next = NULL;
	if(front == NULL){
		front = temp;
	}else{
		rear->next = temp;
	}
	rear = temp;
}

int Queue::dequeue() {
	node *temp = new node();
	int value;
	if(front == NULL){
		cout<<"\nQueue is Emtpty\n";
	}else{
		temp = front;
		value = temp->info;
		front = front->next;
		delete temp;
	}
	return value;
}

bool Queue::isEmpty() {
	return (front == NULL);
}
