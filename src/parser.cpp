#include "../includes/parser.h"

int Parser::_adjacency_table[ROW_SIZE][COLUMN_SIZE];

// constructors
Parser::Parser(char *s) {
  _fail = false;
  set_buffer(s);
  make_table();
  build_keyword_list();
  set_string();
}

Parser::Parser(string s) {
  _fail = false;
  set_buffer(s);
  make_table();
  build_keyword_list();
  set_string();
}

// functions
void Parser::set_buffer(char *s) {
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    _buffer[i] = s[i];
  }
  _buffer[len] = '\0';
}

void Parser::set_buffer(string s) {
  int len = s.length();
  for (int i = 0; i < len; i++) {
    _buffer[i] = s[i];
  }
  _buffer[len] = '\0';
}

void Parser::set_string() {
  bool DEBUG = false;
  STokenizer stk(_buffer);
  Token t;
  stk >> t;
  input_q.clear();
  while (!stk.done()) {
    if(t.type_string()=="STRING") {
      string s;
      s.assign(t.token_str(),1,t.token_str().size()-2);
      input_q += s;
    }
    else if (t.type_string() != "SPACE") {
      input_q += t.token_str();
    }
    if(DEBUG) {
    cout << t << t.type_string() << endl;
    }
    t = Token();
    stk >> t;
  }
  if(DEBUG) {
  cout << "Input Queue: " << input_q << input_q.size() << endl;
  }
  _fail = !get_parse_tree();
}

void Parser::make_table() {
  // initializes the table
  init_table();

  // sets column 0 of a row to 1
  mark_success(6);
  mark_success(10);
  mark_success(16);
  mark_success(23);
  mark_success(33);
  mark_success(42);
  
  // marks(row,column,value)
  mark_cell(0,SELECT, 1);
  mark_cell(0,INSERT,20);
  mark_cell(0,CREATE,30);
  mark_cell(0,DROP,40);
  mark_cell(0,DELETE,50);

  mark_cell(1, OTHER, 2);
  mark_cell(1, STAR, 5);

  mark_cell(2, FROM, 3);
  mark_cell(2, COMMA, 4);

  mark_cell(3, OTHER, 6);

  mark_cell(4, OTHER, 2);

  mark_cell(5, FROM, 3);

  mark_cell(6, WHERE, 7);

  mark_cell(7, OTHER, 8);
  mark_cell(7, LBRACKET, 12);

  mark_cell(8, OPERATOR, 9);

  mark_cell(9, OTHER, 10);

  mark_cell(10, OR, 11);
  mark_cell(10, AND, 11);

  mark_cell(11,OTHER,8);
  mark_cell(11,LBRACKET, 12);
  
  mark_cell(12,LBRACKET,12);
  mark_cell(12,OTHER,13);

  mark_cell(13,OPERATOR,14);

  mark_cell(14,OTHER,15);

  mark_cell(15,OR,17);
  mark_cell(15,AND,17);
  mark_cell(15,RBRACKET,16);

  mark_cell(16,RBRACKET,16);
  mark_cell(16,OR,11);
  mark_cell(16,AND,11);

  mark_cell(17,OTHER,13);

  mark_cell(19,OTHER,23);

  mark_cell(20,INTO,21);

  mark_cell(21,OTHER,22);

  mark_cell(22,VALUES,19);

  mark_cell(23,COMMA,24);

  mark_cell(24,OTHER,23);

  mark_cell(29,OTHER,33);

  mark_cell(30,TABLE,31);

  mark_cell(31,OTHER,32);

  mark_cell(32,FIELDS,29);

  mark_cell(33,COMMA,34);

  mark_cell(34,OTHER,33);

  mark_cell(40,TABLE,41);

  mark_cell(41,OTHER,42);

  mark_cell(50,FROM,51);

  mark_cell(51,OTHER,52);

  mark_cell(52,WHERE,7);

}

// initializes keywords
void Parser::build_keyword_list() {
  keywords["select"] = SELECT;
  keywords["Select"] = SELECT;
  keywords["SELECT"] = SELECT;
  keywords["from"] = FROM;
  keywords["From"] = FROM;
  keywords["FROM"] = FROM;
  keywords["where"] = WHERE;
  keywords["Where"] = WHERE;
  keywords["WHERE"] = WHERE;
  keywords["<"] = OPERATOR;
  keywords[">"] = OPERATOR;
  keywords["="] = OPERATOR;
  keywords["<="] = OPERATOR;
  keywords[">="] = OPERATOR;
  keywords["*"] = STAR;
  keywords["or"] = OR;
  keywords["Or"] = OR;
  keywords["OR"] = OR;
  keywords["||"] = OR;
  keywords["and"] = AND;
  keywords["And"] = AND;
  keywords["AND"] = AND;
  keywords["&"] = AND;
  keywords["&&"] = AND;
  keywords["insert"] = INSERT;
  keywords["Insert"] = INSERT;
  keywords["INSERT"] = INSERT;
  keywords["into"] = INTO;
  keywords["Into"] = INTO;
  keywords["INTO"] = INTO;
  keywords["create"] = CREATE;
  keywords["Create"] = CREATE;
  keywords["CREATE"] = CREATE;
  keywords["make"] = CREATE;
  keywords["Make"] = CREATE;
  keywords["MAKE"] = CREATE;
  keywords[","] = COMMA;
  keywords["drop"] = DROP;
  keywords["Drop"] = DROP;
  keywords["DROP"] = DROP;
  keywords["table"] = TABLE;
  keywords["Table"] = TABLE;
  keywords["TABLE"] = TABLE;
  keywords["delete"] = DELETE;
  keywords["Delete"] = DELETE;
  keywords["DELETE"] = DELETE;
  keywords["values"] = VALUES;
  keywords["Values"] = VALUES;
  keywords["VALUES"] = VALUES;
  keywords["fields"] = FIELDS;
  keywords["Fields"] = FIELDS;
  keywords["FIELDS"] = FIELDS;
  keywords["("] = LBRACKET;
  keywords[")"] = RBRACKET;
}

int Parser::get_column(string token) {
  return keywords[token];
}

// builds ptree and checks for failure
bool Parser::get_parse_tree() {
  bool DEBUG = false;
  PTree.clear();
  int state = 0;
  string token = "";
  for (int i = 0; i < input_q.size() && state >= 0;++i) {
    token = input_q[i];
    if(keywords.contains(token)) {
    state = _adjacency_table[state][keywords[token]];
    } else {
      state = _adjacency_table[state][OTHER];
    }
    if(DEBUG) {
      cout << "Token : " << token << endl;
      cout << "Column : " << state << endl;
    }
    switch(state) {
      //select = command
      case 1: {
        PTree["command"]+=token;
        break;
      }
      //field
      case 2: {
        PTree["fields"]+=token;
        break;
      }
      //all fields (*)
      case 5: {
        PTree["fields"]+=token;
        break;
      }
      //table name
      case 6: {
        PTree["table"]+=token;
        break;
      } 
      //where
      case 7: {
        PTree["where"]+="yes";
        break;
      }
      //field
      case 8: {
        PTree["condition"]+=token;
        break;
      }
      //operator
      case 9: {
        PTree["condition"]+=token;
        break;
      }
      //value
      case 10: {
        PTree["condition"]+=token;
        break;
      }
      //or/and
      case 11: {
        PTree["condition"]+=token;
        break;
      }
      //left bracket
      case 12: {
        PTree["condition"]+=token;
        break;
      }
      //field
      case 13: {
        PTree["condition"]+=token;
        break;
      }
      //operator
      case 14: {
        PTree["condition"]+=token;
        break;
      }
      //value
      case 15: {
        PTree["condition"]+=token;
        break;
      }
      //right bracket
      case 16: {
        PTree["condition"]+=token;
        break;
      }
      // or/and
      case 17: {
        PTree["condition"]+=token;
        break;
      }
      // insert = command
      case 20: {
        PTree["command"]+=token;
        break;
      }
      //table name
      case 22: {
        PTree["table"]+=token;
        break;
      }
      // values
      case 23: {
        PTree["values"]+=token;
        break;
      }
      // create/make = command
      case 30: {
        PTree["command"]+=token;
        break;
      }
      // table name
      case 32: {
        PTree["table"]+=token;
        break;
      }
      // fields
      case 33: {
        PTree["fields"]+=token;
        break;
      }
      // drop = command
      case 40: {
        PTree["command"]+=token;
        break;
      }
      // table name
      case 42: {
        PTree["table"]+=token;
        break;
      }
      //delete = command
      case 50: {
        PTree["command"]+=token;
        break;
      }
      //table name
      case 52: {
        PTree["table"]+=token;
        break;
      }
      // where
      case 53: {
        PTree["where"]+="yes";
        break;
      }
      default: {
        break;
      }
    }
    if(DEBUG) {
      cout << "State: " << state << endl;
    }
  }
  if(state==-1) {
    PTree.clear();
    return false;
  }
  if(_adjacency_table[state][0]) {
    return true;
  } else {
    PTree.clear();
    return false;
  }
}

// sets every column to -1 except first column
void Parser::init_table() {
  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COLUMN_SIZE; j++) {
      _adjacency_table[i][j] = -1;
    }
  }
  for (int i = 0; i < ROW_SIZE; i++) {
    _adjacency_table[i][0] = 0;
  }
}

// sets the first index in a certain row to 1
void Parser::mark_success(int row) {
   _adjacency_table[row][0] = 1; 
}

// mark a range of columns at a certain row
void Parser::mark_cells(int row, int start, int end, int value) {
  for (int j = start; j <= end; j++) {
    _adjacency_table[row][j] = value;
  }
}

// mark a range of columns at a certain row
void Parser::mark_cell(int row, int column, int value) {
  _adjacency_table[row][column] = value;
}