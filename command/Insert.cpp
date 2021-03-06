//
// Created by Hrayr on 5/30/2020.
//


#include "../types/structures.h"
#include "../types/String.h"
#include "Parser.h"
#include "Insert.h"
#include "../DB.h"

using namespace std;

void Insert::run(String query) {
    String table_name = Parser::getTable(query);
    struct table *tb = DB::getInstance()->getTableStructure(table_name);
    long long val_begin_pos;
    val_begin_pos = query.search(this->values_text) + 1;
    String Values_Raw = query.cut(val_begin_pos, query.length() - (val_begin_pos + 2));
    String *pt = Values_Raw.split((char *) "),(");
    long long i = 0;
    for (; pt[i] != nullptr; ++i) {
        tb->insert(pt[i]);
    }
    DB::getInstance()->flush(table_name);
    cout << "Affected " << i << " rows!" << endl;
}