#include "Graph.h"
#include <string>
#include <iterator>
#include <algorithm>
using std::string;
using std::vector;
using std::cout;
using std::endl;

Graph::Graph(std::istream& input)
{
    char buffer;

    // Get Vertex data
    while(input >> buffer && buffer != '*'){
        vertexList.push_back(Vertex(buffer));
    }
    // Get edges and connect
    typedef vector<Vertex>::iterator Iter;
    Iter tail, head;
    size_t weight;

    while (!input.eof())
    {
        // Get edges information
        input >> buffer;
        tail = std::find(vertexList.begin(), vertexList.end(), Vertex(buffer));

        input >> weight;

        input >> buffer;
        head = std::find(vertexList.begin(), vertexList.end(), Vertex(buffer));

        // Add to list
        // Link adjacent list
        auto  tailList_tail{(*tail).firstOut};
        auto NewEdge{new Edge(head - vertexList.begin(), tail - vertexList.begin())};
        if(tailList_tail){
            while(tailList_tail->tailList){
                 tailList_tail = tailList_tail->tailList;
            }
            tailList_tail->tailList = NewEdge;
        }else{
            (*tail).firstOut = NewEdge;
        }

        // Link de-adjacent list
        auto headList_tail{(*head).firstIn};
        if(headList_tail){
            while(headList_tail->headList){
                headList_tail = headList_tail->headList;
            }
            headList_tail->headList = NewEdge;
        }else{
            (*head).firstIn = NewEdge;
        }
    }
    
    // Test
    // cout << "Vertex" << "\t" << "Tail" << "\t" << "Head" << endl;
    for(auto& i : vertexList){
        cout << i.data << "\t";

        auto ptr{i.firstIn};
        while (ptr){
            cout << ptr->headVtx << ' ' << ptr->tailVtx << '\t';
            ptr = ptr->tailList;
        }
        cout << endl;
    }
}

Graph::~Graph()
{
    for(auto& vtx : vertexList){
        // cout<<"Delete: ";
        if(!vtx.firstOut) continue;
        if(!vtx.firstOut->tailList){
            // cout << vtx.firstOut->headVtx <<' '<< vtx.firstOut->tailVtx << '\t';
            delete vtx.firstOut;
        }else {
            auto back{vtx.firstOut}, prior{back->tailList}; 
            while(prior){
                // cout << back->headVtx << ' ' << back->tailVtx << '\t';
                delete back;
                back = prior;
                prior = prior->tailList;
            }
            // cout<< back->headVtx << ' ' << back->tailVtx << endl;
            delete back;
        }
    }
}