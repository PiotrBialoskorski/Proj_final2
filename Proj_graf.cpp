#include <iostream>
#include <new>
#include <string>
#include <vector>

using namespace std;

class Element // bedac szczerym to jest tu tylko po to aby byl jakis polimorfizm
{
	public:
		Element(): value(0) {}
		virtual void setValue(double v) = 0;
	protected:
		double value;
};

class Node: public Element // wierzcholek grafu
{
	public:
		Node() {}
		Node(double v) {value  = v;}
	
		void setValue(double v) override
		{
			value = v;
		}
		~Node() {}
	private:
		
};
class Edge: public Element // krawedz grafu
{
	public:
		Edge() {value = rand()%13+1;}
		Edge(double v) {value = v;}
		
		void setValue(double v) override
		{
			value = v;
		}

		~Edge() {}
	private:
};

class Pair //Klasa przechowujaca pary wierzcholek - krawedz - wierzcholek
{
	public:
		Pair() {}
		Pair(Node &one, Edge &con, Node &two) 
		{
			selfone = one;
			selftwo = two;
			selfcon = con;
		}
		~Pair() {}
	private:
		Node selfone, selftwo;
		Edge selfcon;
};

class Graph // graf
{
	public:
		Graph() 
		{
			Node initial;
			Node goal;
			nodes.push_back(initial);
			nodes.push_back(goal);
			Edge line1;
			edges.push_back(line1);
			Pair Pair1(nodes[0] ,edges[0],nodes[1]);
			Pairs.push_back(Pair1);
		}
		Graph(int n, int e, int *tab, int tab_size) // n - liczba wierzcholkow, e - liczba krawedzi, tab - tablica wierzcholkow w kolumnie, tab_size - rozmiar tablicy : D
		{	
			
			Node initial;
			Node goal;
			nodes.push_back(initial);
			nodes.push_back(goal);
			for(int i = 0; i < n; i++)
			{	
				auto pos = nodes.end();
				Node newNode;
				nodes.insert(pos - 1, newNode);
			}
			for(int i = 0; i < e; i++)
			{
				auto pos = edges.end();
				Edge newEdge;
				edges.insert(pos - 1, newEdge);
			}
			if(n == e)
			{
				for(int i = 0; i < tab_size; i++)
				{
					for(int j = i; j < tab[i]; j++)
					{

					}
				}
			}
		}

		~Graph() {}
	private:
		vector<Node> nodes;
		vector<Edge> edges;
		vector<Pair> Pairs;

};

int main()
{

	cout << "Hello World!" << endl;

}