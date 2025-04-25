#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
// Structure de données pour stocker une arête de graphe
struct Edge {
    int init, dest;
};
 
// Une classe pour représenter un objet graph
class Graph
{
public:
    // un vector de vectors pour représenter une liste d'adjacence
    vector<vector<int>> adjList;
 
    // Constructeur de graphe
    Graph(vector<Edge> const &edges, int n)
    {
        // redimensionne le vector pour qu'il contienne `n` éléments de type `vector<int>`
        adjList.resize(n);
 
        // ajoute des arêtes au graphe orienté
        for (const Edge &edge: edges)
        {
            // insère à la fin
            adjList[edge.init].push_back(edge.dest);
 
            // non orienté : 
            //adjList[edge.dest].push_back(edge.init);
        }
    }
};

Graph transpose(Graph graph){
    int taille = graph.adjList.size();
    vector<Edge> arrete(taille);
    for(int i = 0; i<taille; i++){
        for(int j : graph.adjList[i]){
            arrete.push_back({j,i});
        }
    }
    Graph resultat(arrete, taille);
    return resultat;
}

void visit_1(int sommet, Graph graph, stack<int>& sommet_v, vector<bool>& visiter){
        if(!visiter[sommet]){
            visiter[sommet] = true;
            for(int i : graph.adjList[sommet]){
                visit_1(i, graph, sommet_v, visiter);
            }
            sommet_v.push(sommet);
        }
}

void visit_2(int sommet, Graph graph, vector<bool>& visiter){
    if(!visiter[sommet]){
        visiter[sommet] = true;
        for(int i : graph.adjList[sommet]){
            visit_2(i, graph, visiter);
        }
        cout << sommet << " ";;
    }
}


int main()
{
    // vector des arêtes du graphe selon le diagramme ci-dessus.
    // Veuillez noter que le vector d'initialisation dans le format ci-dessous sera
    // fonctionne correctement en C++11, C++14, C++17 mais échouera en C++98.
    vector<Edge> edges =
    {
        {1, 0}, {2, 1}, {2, 3}, {3, 4}, {4, 2}
    };
 
    // nombre total de nœuds dans le graphe (étiquetés de 0 à 5)
    int n = 5;
 
    // construit le graphe
    Graph graph(edges, n);
    //kosarajuuuuuuu
    vector<bool> visiter(n); // créer directement a false
    stack<int> sommet_v;

    for(int i = 0; i<n;i++){
        visit_1(i, graph, sommet_v, visiter);
    }
    Graph graph_t = transpose(graph);
    vector<bool> visiter2(n);

    while(!sommet_v.empty()){
        int val = sommet_v.top();
        sommet_v.pop();
        if(!visiter2[val]){
            visit_2(val, graph_t, visiter2);
            cout << endl;
        }
    }

    return 0;
}