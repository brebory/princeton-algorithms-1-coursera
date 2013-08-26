#include <vector>
#include <iostream>

namespace BR {

  typedef T int;

  class Union {
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;

    Union();
    Union(std::vector<T>, std::vector<T>);
    Union(const Union&);
    
    ~Union();

    unite(Node*, Node*);
  };

  class Node {
    T* data;

    Node();
    Node(const T&);
    Node(const Node&);

    ~Node();
  };

  class Edge {
    Node* left;
    Node* right;

    Edge();
    Edge(T, T);
    Edge(Node*, Node*);
    Edge(const Edge&);

    ~Edge();
  };
  
  class QuickFind {
  public:
    typedef ID int;
    typedef size_type int;

    // Default constructor
    QuickFind();
    // Discrete constructor
    QuickFind(size_type);
    // Array constructor
    QuickFind(size_type*, size_type);
    // Vector constructor
    QuickFind(const std::vector<ID>&);
    // Copy constructor
    QuickFind(const QuickFind&);

    bool find(size_type, size_type);

    void unite(size_type, size_type);

    friend std::ostream& operator<<(std::ostream&, const QuickFind&);

    std::vector<ID> entries;

  };

}
