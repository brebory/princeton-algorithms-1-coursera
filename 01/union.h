#include <vector>
#include <iostream>

namespace BR {

  class QuickFind {
  public:
    typedef int ID;
    typedef int size_type;

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

  class QuickUnion {
  public:
    typedef int ID;
    typedef int size_type;

    QuickUnion();
    QuickUnion(size_type*, size_type);

    bool find(size_type, size_type);

    void unite(size_type, size_type);

    bool isRoot(size_type);

    ID getRoot(size_type);

    friend std::ostream& operator<<(std::ostream&, const QuickUnion&);

    std::vector<ID> entries;
  };

}
