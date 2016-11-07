/* Assignment 3 CS4071
 * Group 8
 * Sean Kennedy, Ryan Pavsek
 * Diameter and
 * Connected Components of a Network
 *
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

/*
 * A Graph Class.  Takes A graph as a number of
 * vertices and edges and displays a adjacency matrix
 *
 */
class Graph
{
	private:
        int n;
        int **adj;
        bool *visited;

    public:
        bool isConnected(int, int);
        void BFS(int);
        void DistanceMatrix(int);
        Graph(int n)
        {
            this->n = n;
            visited = new bool [n];
            adj = new int* [n];
            for (int i = -1; i < n; i++)
            {
                adj[i] = new int [n];
                for(int j = -1; j < n; j++)
                {
                    adj[i][j] = 0;
                }
            }
        }
        /*
         * Add Edges to Graph
         */
        void addEdge(int i, int j)
        {
            if( i > n || j > n || i < 0 || j < 0)
            {
                cout<<"Incorrect Edge!\n";
            }
            else
            {
                adj[i - 1][j - 1] = 1;
            }
        }
        /*
         * Display the Adjacency Matrix
         */
        void print()
        {
            int i,j;
            for(i = 0;i < n;i++)
            {
                for(j = 0; j < n; j++)
                    cout<<adj[i][j]<<"  ";
                cout<<endl;
            }
        }
};
/*
 * STL Queue Class
 */
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

bool Graph::isConnected(int u, int v) {
	return (adj[u-1][v-1] == 1);
}

/*
 * Breadth First Search function
 * For a Graph
 */
void Graph::BFS(int s) {
	 Queue Q;

	 //Are the vertices explored?
	 bool *explored = new bool[n+1];

	//Initialize all vertices as unexplored
	 for (int i = 1; i <= n; ++i)
		explored[i] = false;

	 //First Vertex pushed to queue
	 Q.enqueue(s);
	 explored[s] = true;
	 cout << "Starting search from vertex ";
	 cout << s << " : " << endl;

	 //Don't search if queue is empty
	 while (!Q.isEmpty()) {
		int v = Q.dequeue();

		//Print out explored vertices
		cout << v << " ";

		//Explore connected vertices from initial
		for (int w = 1; w <= n; ++w)
			if (isConnected(v, w) && !explored[w]) {
				Q.enqueue(w);
				explored[w] = true;
			}
	}
	cout << endl;
	delete [] explored;
}


/*void Graph::DistanceMatrix(int)
{
 for (int i = 0; i < n; i++){
	 for (int j = 0; j < n; j++){
		adj[i][j] = BFS(adj[i][j]);
		cout << adj[i][j] << "  ";
		cout << endl;
	 }
 }

}*/



int main()
{
    int vertices, maxEdges, i, j;
    cout<<"Number of vertices in Graph: ";
    cin>>vertices;
    Graph g(vertices);
    maxEdges = vertices * (vertices - 1);
    for (int index = 0; index < maxEdges; index++)
    {
        cout<<"Enter an edge (Enter -1 -1 to terminate): ";
        cin>>i>>j;
        if((i == -1) && (j == -1))
            break;
        g.addEdge(i, j);
    }
    cout << "Adjacency Matrix: " << endl;

    g.print();
    cout << endl;
    cout << "Breadth First Search of Graph: " << endl;
    for (int i = 0; i <= vertices; i++){
    g.BFS(i);
    }
    return 0;
}
