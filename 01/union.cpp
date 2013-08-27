#include "union.h"

namespace BR {
  QuickFind::QuickFind() {
    entries = std::vector<QuickFind::ID>();
  }

  QuickFind::QuickFind(QuickFind::size_type amount) {
    for(QuickFind::ID el = 0; el < (QuickFind::ID) amount; ++el) {
      entries.push_back(el); 
    }
  }

  QuickFind::QuickFind(QuickFind::size_type* array, QuickFind::size_type len) {
    for(QuickFind::size_type idx = 0; idx < len; ++idx) {
      entries.push_back((QuickFind::ID) *array++);
    }
  }

  QuickFind::QuickFind(const std::vector<QuickFind::ID>& vec) {
    for(QuickFind::size_type idx = 0, len = (QuickFind::size_type) vec.size(); idx < len; ++idx) {
      entries.push_back((QuickFind::ID) vec.at(idx));
    }
  }

  bool QuickFind::find(QuickFind::size_type node1, QuickFind::size_type node2) {
    return entries.at(node1) == entries.at(node2);
  }

  void QuickFind::unite(QuickFind::size_type node1, QuickFind::size_type node2) {
    QuickFind::ID target_union_id = entries.at(node2); 
    QuickFind::ID source_union_id = entries.at(node1);

    if(target_union_id != source_union_id) {
      for(QuickFind::size_type idx = 0, len = entries.size(); idx < len; ++idx) {
        if(entries.at(idx) == source_union_id) {
          entries.at(idx) = target_union_id;
        }
      }
    }
  }

  std::ostream& operator<<(std::ostream& out, const QuickFind& source) {
    for(QuickFind::size_type idx = 0, len = source.entries.size(); idx < len; ++idx) {
      out << source.entries.at(idx);
    }
    return out;
  }


  QuickUnion::QuickUnion(QuickUnion::size_type *array, QuickUnion::size_type len) {
    for(QuickUnion::size_type idx = 0; idx < len; ++idx) {
      entries.push_back((QuickUnion::ID) *array++);
    }
  }

  bool QuickUnion::isRoot(QuickUnion::size_type element) {
    return element == (QuickUnion::size_type) entries.at(element); 
  }

  QuickUnion::ID QuickUnion::getRoot(QuickUnion::size_type element) {
    if(isRoot(element)) {
      return entries.at(element); 
    } else {
      return getRoot((QuickUnion::size_type) entries.at(element));
    }
  }

  bool QuickUnion::find(QuickUnion::size_type node1, QuickUnion::size_type node2) {
    return entries.at((QuickUnion::size_type) getRoot(node1)) == entries.at((QuickUnion::size_type) getRoot(node2));
  }

  void QuickUnion::unite(QuickUnion::size_type node1, QuickUnion::size_type node2) {
    if (!find(node1, node2)) {
      entries.at((QuickUnion::size_type) getRoot(node1)) = getRoot(node2);
    }
  }

  std::ostream& operator<<(std::ostream& out, const QuickUnion& source) {
    for(QuickUnion::size_type idx = 0; idx < (QuickUnion::size_type) source.entries.size(); ++idx) {
      out << source.entries.at(idx);
    }
    return out;
  }
}
