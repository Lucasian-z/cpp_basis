#include "text_query.h"

int main(int argc, char* argv[])
{
    TextQuery tq;
    string filename;
    cin >> filename;
    tq.readFile(filename);
    string query_word;//待查单词
    cin >> query_word;
    tq.query(query_word);
    return 0;
}