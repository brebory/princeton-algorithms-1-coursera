#include "union.h"
namespace BR {
  QuickFind::QuickFind() {
    entries = vector<ID>();
  }

  QuickFind::QuickFind(size_type amount) {
    for(ID el = 0; el < (ID) amount; ++el) {
      entries.push_back(el); 
    }
  }

  QuickFind::QuickFind(size_type* array, size_type len) {
    for(size_type idx = 0; idx < len; ++idx) {
      entries.push_back((ID) *array++);
    }
  }

  QuickFind::QuickFind(const std::vector<ID>& vec) {
    for(size_type idx = 0, len = (size_type) vec.size(); idx < len; ++idx) {
      entries.push_back((ID) vec.at(idx));
    }
  }

  bool QuickFind::find(size_type node1, size_type node2) {
    return entries.at(node1) == entries.at(node2);
  }

  void QuickFind::unite(size_type node1, size_type node2) {
    ID target_union_id = entries.at(node2); 
    ID source_union_id = entries.at(node1);

    if(target_union_id != source_union_id) {
      for(size_type idx = 0, len = entries.size(); idx < len; ++idx) {
        if(entries.at(idx) == source_union_id) {
          entries.at(i) = target_union_id;
        }
      }
    }
  }

  std::ostream& operator<<(std::ostream& out, const QuickFind& source) {
    for(size_type idx = 0, len = entries.size(); idx < len; ++idx) {
      out << entries.at(i);
    }
    return out;
  }

}
