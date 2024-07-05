#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"
#include <vector>

void menuAuswahl();
void graphEinlesen();

void printMST(const std::vector<Edge>& mst, const std::string& algorithm, double totalWeight) {
	std::map<int, std::vector<std::pair<int, double>>> adjList;


	for(const auto &edge : mst){
		int v = edge.either();
		int w = edge.other(v);
		double weight = edge.weight();
		adjList[v].push_back({w, weight});
		adjList[w].push_back({v, weight});
	}

	std::cout << "Minimaler Spannbaum (MST) nach " << algorithm << std::endl;
    std::cout << "Gewicht: " << totalWeight << std::endl;
    std::cout << "Adjazenzliste: " << std::endl;

	for (const auto& entry : adjList) {
        std::cout << char(entry.first + 65) << " -> ";
        for (const auto& adj : entry.second) {
            std::cout << char(adj.first + 65) << " [" << adj.second << "] -> ";
        }
        std::cout << std::endl;
    }

}

void printAdjList(const EdgeWeightedGraph& G) {
    for (int v = 0; v < G.getV(); ++v) {
        std::cout << char(v+65) << " -> ";
        for (const auto& e : G.getAdj(v)) {
            std::cout << char(e.other(v)+65) << " [" << e.weight() << "] -> ";
        }
        std::cout << std::endl;
    }
}

void printDijkstra(DijkstraSP& dsp, int start, int goal, const EdgeWeightedDigraph& G) {
    std::map<int, int> edgeTo;
    std::vector<double> distToVect(G.getV(), std::numeric_limits<double>::infinity());
	int eingabe = 0;
	std::cin >> eingabe;

    distToVect[start] = eingabe;

    for (int v = 0; v < G.getV(); ++v) {
        if (distToVect[v] < std::numeric_limits<double>::infinity()) {
            for (const DirectedEdge& e : G.getAdj(v)) {
                int w = e.to();
                if (distToVect[w] > distToVect[v] + e.weight()) {
                    distToVect[w] = distToVect[v] + e.weight();
                    edgeTo[w] = v;
                }
            }
        }
    }

    std::cout << "Knoten i | ";
    for (int i = 0; i < G.getV(); ++i) {
        std::cout << char(i + 65) << " ";
    }
    std::cout << std::endl << "-------------------------" << std::endl;
    std::cout << "edgeTo[i]| ";
    for (int i = 0; i < G.getV(); ++i) {
        if (i == start) {
            std::cout << "- ";
        } else {
            std::cout << (edgeTo.find(i) != edgeTo.end() ? char(edgeTo[i] + 65) : '-') << " ";
        }
    }
    std::cout << std::endl << "-------------------------" << std::endl;
    std::cout << "distTo[i]| ";
    for (double dist : distToVect) {
        std::cout << dist << " ";
    }
    std::cout << std::endl << std::endl <<"Kürzester Weg (Dijkstra):" << std::endl;
    std::cout << "Start: " << char(start + 65) << "\n";
    std::cout << "Ziel: " << char(goal + 65) << "\n";
    std::cout << "Pfad: ";

    if (dsp.hasPathTo(goal)) {
        auto path = dsp.pathTo(goal);
        for (const auto& edge : path) {
            std::cout << char(edge.from() + 65) << " [" << edge.weight() << "] -> ";
        }
        std::cout << char(goal + 65);
        std::cout << std::endl << "Kosten: " << dsp.distTo(goal) << std::endl;
    } else {
        std::cout << "Kein Pfad gefunden" << std::endl;
    }
}

int main() {
	// Starte Unit-Tests
	Catch::Session().run();

	EdgeWeightedGraph G = EdgeWeightedGraph("Graph1.txt");
	EdgeWeightedDigraph dG = EdgeWeightedDigraph("Graph2.txt");
	DijkstraSP dsp(dG, 0);

	std::cout << "tätige eine Auswahl zwischen 1 bis 10" << std::endl;

	

	int auswahl = 0;
	
	
	while(auswahl != 10){
		std::cout << 
		 std::setw(10) <<"Praktikum 5: Graphenalgorithem:" << std::endl <<
		"1) Graph einlesen" << std::endl <<
		"2) Tiefensuche" << std::endl <<
		"3) Breitensuche" << std::endl <<
		"4) MST nach Prim (Eingabe: Startknoten)" << std::endl <<
		"5) MST nach Kruskal" << std::endl <<
		"6) K ̈urzeste Wege nach Dijkstra (Eingabe: Startknoten)" << std::endl <<
		"7) Ausgabe der Adjazenzliste" << std::endl <<
		"8) Kante l ̈oschen" << std::endl <<
		"9) Kante hinzuf ̈ugen" << std::endl <<
		"10)Programm beenden" << std::endl;
		std::cin >> auswahl; 
		
		if(auswahl == 1) {
			std::cout << "Graph 1, 2 oder 3 einlesen" << std::endl;
			int auswahlGraph = 0; 
			std::cin >> auswahlGraph;
			
			switch (auswahlGraph)
			{
			case 1:
				G = EdgeWeightedGraph("graph1.txt");
				dG = EdgeWeightedDigraph("graph1.txt");
				
				break;
			case 2:
				G = EdgeWeightedGraph("graph2.txt");
				dG = EdgeWeightedDigraph("graph2.txt");
				break;
			case 3:
				G = EdgeWeightedGraph("graph2.txt");
				dG = EdgeWeightedDigraph("graph2.txt");
				break;
			default:
				std::cout << "Falsche Eingabe!" << std::endl;
				break;
		}
			if(G.getV() > 0) {
				std::cout << "Der Graph hat folgende Informationen: " << std::endl
				 << "Knoten (V): " << G.getV() << std::endl 
				 << "Kanten (E): " << G.getE() << std::endl 
				 << "_____________________"<< std::endl;

			}
		}

		if(auswahl == 2) {
			int start = 0;

			std::cout << "Tiefensuche wird ausgefuehrt mit Startknoten " << char(start+65)<<std::endl;
			
			std::vector<bool> marked;
			std::vector<int> edgeTo;	

			bool connected = Graphsearch::DFS(G, start, marked, edgeTo);	

		
			/*
			std::cout << "Marked: " << std::endl;
			for(int i = 0; i < marked.size(); i++) {
				std::cout << i << "->" << marked[i] << std::endl;
				if(marked[i]) std::cout << "true";
				else std::cout << "false";
				if(i == start) std::cout << "Startverticle: " ;
				std::cout << std::endl;
			}*/
			
			std::cout << "Graph zusammenhängend?: ";
			if(!connected) std::cout << "nein" << std::endl;
			else if(connected) std::cout << "ja" << std::endl;
			std::cout << std::endl;

		}

		if(auswahl == 3) {
			int startVerticle = 0;
			std::cout << "Breitensuche wird ausgefuehrt mit Startknoten 0" << std::endl;
			std::vector<bool> marked;
			std::vector<int> edgeTo;

			bool connected = Graphsearch::BFS(G, startVerticle, marked, edgeTo);

			std::cout << "Graph zusammenhängend?: ";
			if(!connected) std::cout << "nein" << std::endl;
			else if(connected) std::cout << "ja" << std::endl;
			std::cout << std::endl;

		}
		if(auswahl == 4) {
			std::cout << "WÄHLE STARTKNOTEN	" << std::endl;
			int startVerticle = 0;
			std::cin >> startVerticle;
			std::cout << "PrimMST wird ausgefuehrt mit Startknoten " << char(startVerticle+65) << std::endl;
			PrimMST primMST(G,startVerticle);
			printMST(primMST.edges(), "prim", primMST.weight());
		}
		if(auswahl == 5) {
			std::cout << "KruskalMST wird ausgefuehrt " << std::endl;
			KruskalMST kruskalMST(G);
			printMST(kruskalMST.edges(), "kruskal", kruskalMST.weight());
		}
		if(auswahl == 6) {
			DijkstraSP dsp(dG, 0);
			printDijkstra(dsp, 1, 5, dG);
		}
		if(auswahl == 7) {
			printAdjList(G);
   		 
		}
		if (auswahl == 8) {
			std::cout << "welche Kante möchtest du löschen? gebe die Kanten ein die verbunden sind + das Gewicht" << std::endl;
			
			int verticle1 = 0;
			int verticle2 = 0;
			int weight = 0;
			std::cin >> verticle1;
			std::cin >> verticle2;
			std::cin >> weight;

            Edge e(verticle1, verticle2, weight); // Beispielkante aus Graph1.txt
            DirectedEdge de(verticle1, verticle2, weight); // Beispielkante aus Graph1.txt

            if (G.del_Edge(e)) {
                std::cout << "ungerichteter Kante erfolgreich entfernt." << std::endl;
            } else {
                std::cout << "Kante konnte nicht entfernt werden." << std::endl;
            }

            if (dG.del_Edge(de)) {
                std::cout << "gerichteter Kante erfolgreich entfernt." << std::endl;
            } else {
                std::cout << "Kante konnte nicht entfernt werden." << std::endl;
            }
        }
		if (auswahl == 9) {
			std::cout << "welche Kante möchtest du hinzufügen? gebe die Kante ein die verbunden worden soll + das Gewicht" << std::endl;

			int verticle1 = 0;
			int verticle2 = 0;
			int weight = 0;
			std::cin >> verticle1;
			std::cin >> verticle2;
			std::cin >> weight;
            Edge e(verticle1, verticle2, weight); 
            G.add(e);

            DirectedEdge de1(verticle1, verticle2, weight); 
            dG.add(de1);

            std::vector<Edge> edges = G.edges();
            for (const Edge& edge : edges) {
                std::cout << "Kante: " << char(edge.either() + 65)
                    << " - " << char(edge.other(edge.either()) + 65)
                    << " [" << edge.weight() << "]" << std::endl;
            }

            std::vector<DirectedEdge> directedEdges = dG.edges();
            for (const DirectedEdge& edge : directedEdges) {
                std::cout << "Kante: " << char(edge.from() + 65) << " -> " << char(edge.to() + 65) << " [" << edge.weight() << "]" << std::endl;
            }
        }
    }


	return 0;
}










void menuAuswahl() {

	
}

void graphEinlesen() {
	

}