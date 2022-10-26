#ifndef PARSER_H_
#define PARSER_H_

#include "data_structures/vector.h"
#include "data_structures/map.h"
#include "data_structures/mmap.h"
#include "data_structures/queue.h"
#include "stokenizer.h"

#define ROW_SIZE 61
#define COLUMN_SIZE 41
#define BUFFER_SIZE 100

class Parser {
 public:
  // constructors
  Parser(char *s);
  Parser(string s);

  bool fail() {
    return _fail;
  }
  MMap<string,string> &parse_tree() {
    return PTree;
  }

  enum keys {
    SELECT = 1,
    FROM,
    WHERE,
    OTHER,
    OPERATOR,
    STAR,
    OR,
    AND,
    INSERT,
    INTO,
    CREATE,
    COMMA,
    DROP,
    TABLE,
    DELETE,
    VALUES,
    FIELDS,
    LBRACKET,
    RBRACKET
  };

  int get_column(string token);
  void set_buffer(char *s);
  void set_buffer(string s);
  void set_string();
  
 private:
  // variables / structures
  MMap<string, string> PTree;
  Map<string, int> keywords;
  Vector<string> input_q;
  bool _fail;
  char _buffer[BUFFER_SIZE];
  static int _adjacency_table[ROW_SIZE][COLUMN_SIZE];
  
  // Initializing Functions
  void make_table();
  void build_keyword_list();
  bool get_parse_tree();

  // Helper Functions
  void init_table();
  void mark_success(int row);
  void mark_cell(int row, int column, int value);
  void mark_cells(int row, int start, int end, int value);
};

#endif  // PARSER_H_
