
#include <vector>

class Graph_Interface
{
    public:
    virtual void add_edge(int u, int v)=0;
    virtual void add_edge(int u, int v, double w);
}
class Node
{
    public:
        int _id;
        int color;
};

class Edge
{
    public:
        Node u;
        Node v;
        double weight;
};


class graph: public Graph_Interface
{

    graph(int nr_nodes, bool weighted, bool directed) : _edges{std::vector<std::vector<int>>(n,std::vector<int>{})}
                                                      , _directed{directed}
                                                      ,_weighted{weighted}
                                                      {}
    void add_edge(Edge const & e);
    private:
        std::vector<std::vector<Edge>> _edges;
        bool _directed;
        int _nr_nodes;
};

void graph::add_edge(Edge const & e)
{
    _edges[e.u].push_back(e);
    if(!_directed)
        _edges[v].push_back({v,0});
}

/*
class weighted_graph : public graph
{
    void add_edge(int u, int v, double w);
    private:
    std::vector<std::vector<std::pair<int,double>>> _edges;
};
void graph::add_edge(int u, int v)
{
    _edges[u].push_back({v,0});
    if(!_directed)
        _edges[v].push_back({v,0});
}

*/
graph * g = new weighted_graph{};
graph->add(
*/



parent -->vptr->  vtablename
virtual name

child:parent -> vtable->ptr
vptr for name -> parent->name
virutal name;
