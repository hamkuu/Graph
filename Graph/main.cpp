//
//  main.cpp
//  Graph
//
//  Created by Hamkuu Shaw on 6/26/16.
//  Copyright © 2016 hamkuu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
//#include <stack>

// neighbour relation
struct Neighbour {
    
    int dest;
    //int cost;
    struct Neighbour * next;
    
};

// vectex/node
struct Vectex {
    
    struct Neighbour * head;
    
};


// representing graph as
// adjacency list

class Graph {
public:
    Graph(int n){
        
        for (int i=0; i<n; ++i) {
            
            AddVectex();
            
        }
        
    }
    
    void AddVectex(){
        
        VectexNum++;
        VectexArray.resize(VectexNum);
        VectexArray[VectexNum-1].head = NULL;
        
    }
    
    void AddEdgeWithDirection(int src, int dest) {
        
        Neighbour * destPtr = new Neighbour;
        destPtr->dest = dest;
        destPtr->next = NULL;
        
        //insert new node right after head
        destPtr->next = VectexArray[src].head;
        VectexArray[src].head = destPtr;
        
    }
    
    void AddEdgeWithoutDiretion(int node_1, int node_2){
        
        AddEdgeWithDirection(node_1, node_2);
        AddEdgeWithDirection(node_2, node_1);
        
    }
    
    bool ifAreNeighours(int src, int dest) {
        
        Neighbour * traversePtr = VectexArray[src].head;
        
        while (traversePtr) {
            
            if (traversePtr->dest == dest) {
                
                return true;
                
            }
            
            traversePtr = traversePtr->next;
            
        }
        
        return false;
        
    }
    
    void BreadthFirstSearch(int startNode) {
        
        // tracking if nodes are visited
        bool * ifVisited = new bool[VectexNum];
        for (int i=0; i<VectexNum; ++i) {
            
            ifVisited[i] = false;
            
        }
        
        std::queue<int> BFSQueue;
        
        ifVisited[startNode] = true;
        BFSQueue.push(startNode);
        
        // loop until the queue is empty
        while (!BFSQueue.empty()) {
            
            int currentNode = BFSQueue.front();
            std::cout << currentNode << "->";
            BFSQueue.pop();
            
            // explore all neighbours of current node
            Neighbour * traversePtr = nullptr;
            traversePtr = VectexArray[currentNode].head;
            
            while (traversePtr) {
                
                int adjNode = traversePtr->dest;
                
                if (!ifVisited[adjNode]) {
                    
                    // mark as visited and enqueue
                    ifVisited[adjNode] = true;
                    BFSQueue.push(adjNode);
                    
                }
                
                traversePtr = traversePtr->next;
                
            }
            
            traversePtr = nullptr;
            
        }
        
        std::cout << "END" << std::endl;
        
        
    }
    
    
    
    void DepthFirstSearch(int startNode) {
        
        // tracking if nodes are visited
        bool * ifVisited = new bool[VectexNum];
        for (int i=0; i<VectexNum; ++i) {
            
            ifVisited[i] = false;
            
        }
        
        DFSHelper(startNode, ifVisited);
        
        std::cout << "END" << std::endl;
        
    }
    
    void DFSHelper(int currentNode, bool ifVisited[]) {
        
        ifVisited[currentNode] = true;
        std::cout << currentNode << "->";
        
        // explore all neighbours of current node
        Neighbour * traversePtr = nullptr;
        traversePtr = VectexArray[currentNode].head;
        
        while (traversePtr) {
            
            int adjNode = traversePtr->dest;
            
            if (!ifVisited[adjNode]) {
                
                // call DFSHelper recursively
                DFSHelper(adjNode, ifVisited);
                
            }
            
            traversePtr = traversePtr->next;
            
        }
        
        traversePtr = nullptr;
        
        
    }
    
    void PrintGraph(){
        
        Neighbour * traversePtr = nullptr;
        
        for (int i=0; i<VectexNum; ++i) {
            
            std::cout << i << "(HEAD)";
            
            traversePtr = VectexArray[i].head;
            
            while (traversePtr) {
                
                std::cout << "->" << traversePtr->dest;
                traversePtr = traversePtr->next;
                
            }
            
            traversePtr = nullptr;
            std::cout << std::endl;
            
        }
        
    }
    
private:
    
    int VectexNum = 0;
    std::vector<Vectex> VectexArray;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Graph myGraph = Graph(9);
    
    
    myGraph.AddEdgeWithoutDiretion(3, 6);
    myGraph.AddEdgeWithoutDiretion(0, 3);
    myGraph.AddEdgeWithoutDiretion(1, 3);
    myGraph.AddEdgeWithoutDiretion(3, 4);
    myGraph.AddEdgeWithoutDiretion(7, 3);
    
    myGraph.AddEdgeWithoutDiretion(1, 2);
    myGraph.AddEdgeWithoutDiretion(4, 5);
    myGraph.AddEdgeWithoutDiretion(8, 7);
    
    myGraph.AddEdgeWithoutDiretion(2, 5);
    myGraph.AddEdgeWithoutDiretion(5, 8);
    
    //std::cout << myGraph.ifAreNeighours(4, 1) << std::endl;
    
    myGraph.PrintGraph();
    
    //myGraph.BreadthFirstSearch(3);
    myGraph.DepthFirstSearch(3);
    
    return 0;
    
}
